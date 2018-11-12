//declare the dependencies for 
const mysql = require('mysql');
const express = require('express');
const app = express();
const url = require('url');
const bodyParser = require('body-parser');
const path = require('path');


const connection = mysql.createConnection({
    host: 'localhost',
    user: 'root',
    password: 'password',
    database: 'serverdb'
});

/*
this is an array that stores the tokens of users that are logged in to
reference when someone tries to make an action that requires being logged in
*/
var sessions = [];
    
app.get('/', function (req, res) {
    res.sendFile(__dirname + '/index.html');
});

app.use(bodyParser.json());       // to support JSON-encoded bodies
app.use(bodyParser.urlencoded({     // to support URL-encoded bodies
    extended: true
}));

app.listen(2500, function () {
    console.log('http server listening on 2500');
});

app.get('/', function (req, res) {
    res.sendFile(path.resolve('./index.html'));
});

app.get('/ping', function (req, res) {

    console.log('pong');
    res.send('pong');

});

//Checks if there is an already existing user and adds if not there
app.post('/addUser', function (req, res) {
    console.log('adding user');
    var thisUser = req.body.userid;
    var first = req.body.firstName;
    var last = req.body.lastName;
    var password = req.body.password;

    //change this sql command to take only these four fields
    
    connection.query("select * from user where userid = '" + thisUser + "'", function (error, results) {
        if (error) throw error;
        if (results.length >= 1) {
            res.send({ status: "duplicate user" });
        } else {
            var command = "insert into user (userid, firstName, lastName, password) values ('" + thisUser + "', '" + first + "', '" + last + "', '" + password + "')";

            doIt(command);
        }
    });
    function doIt(comm) {
        connection.query(comm, function (error, results) {
            if (error) throw error;
            res.send({ status: "success" });
        });
    }
});

app.get('/name', function(req, res){
   var userid = req.query.userid;
    var cmd = "select user.firstName from user where user.userid = '" + userid + "'";
    console.log(cmd);
    connection.query(cmd, function(error, results){
        console.log(results);
        res.send(results);
        
    });
});

app.post('/verify', function (req, res) {
    var thisUser = req.body.userid;
    var passAttempt = req.body.password;
    
    function token(password){
        var value = 0;
        password.forEach(function(element, index, array){
            
            value += element;
            value *= 31;
            value *= 29;
            
        });
        value = value % 103289729;
        return value;
    }

    var cmd = "select userid, password, firstName from user where user.userid = '" + thisUser + "' and user.password = '" + passAttempt + "'";
    console.log(cmd);
    connection.query(cmd, function (error, result) {
        if (error) throw error;

        if (result[0] != undefined) {
            
            var token = token(password);
            
            res.send({ status: "success", userid: thisUser, token: token});
            
            sessions.push({userid: thisUser, token: token});

        } else {
            res.send({ status: "failed", userid: thisUser, password: passAttempt });
        }
    });
});

app.post('/getUser', function (req, res) {
    var thisUser = req.body.userid;

    var cmd = "select * from user where userid = '" + thisUser + "'";

    connection.query(cmd, function (error, result) {
        if (error) throw error;
        if (result[0] != undefined) {
            res.send(result);

        } else {
            res.send({ status: "failed" });
        }
    });

});
