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
//the homepage of the web application
app.get('/', function (req, res) {
    res.sendFile(__dirname + '/index.html');
});

app.use(bodyParser.json());       // to support JSON-encoded bodies
app.use(bodyParser.urlencoded({     // to support URL-encoded bodies
    extended: true
}));
//the app listens to this port for requests
app.listen(2500, function () {
    console.log('http server listening on 2500');
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
    //I use this function "doIt" a lot, and it's a lazy way of not caring what time some async function returns
    function doIt(comm) {
        connection.query(comm, function (error, results) {
            if (error) throw error;
            res.send({ status: "success" });
        });
    }
});
//returning the first name of a user
app.get('/name', function(req, res){
   var userid = req.query.userid;
    var cmd = "select user.firstName from user where user.userid = '" + userid + "'";
    console.log(cmd);
    connection.query(cmd, function(error, results){
        console.log(results);
        res.send(results);
        
    });
});
//this request authenticates a user and if the user is valid it returns an encoded password as a token
app.post('/verify', function (req, res) {
    //pretty vulnerable to just requesting every possible password for a user, but it would be easy to implement counter-measures to that
    var thisUser = req.body.userid;
    var passAttempt = req.body.password;
    //we return the password as a token 
    function token(password){
        var value = 0;
        password.forEach(function(element, index, array){
            //This is a basic hash function for creating the token.  It's a little weak, but it's a start.
            value += element;
            value *= 31;
            value *= 29;
            
        });
        value = value % 103289729;
        function resolveCollisions(){
            sessions.forEach(function(element, index, array){
                if(element.token == value && element.userid == thisUser){
                    //here's how we resolve the collisions that will never happen
                    value = value * 5;
                    value = value % 103289729;
                    resolveCollisions();

                }    
            });
        }
        return value;
    }
    //the sql command, and the way we log it so that the console gives us tools to analyze potential overuse, or to catch bugs
    var cmd = "select userid, password, firstName from user where user.userid = '" + thisUser + "' and user.password = '" + passAttempt + "'";
    console.log(cmd);
    //here is where we execute the command on our connection
    connection.query(cmd, function (error, result) {
        if (error) throw error;

        if (result[0] != undefined) {
            //if the user is valid we return to the user their id and token, with a status of "success"
            var token = token(password);
            
            sessions.push({userid: thisUser, token: token});
            
            res.send({ status: "success", userid: thisUser, token: token});

        } else {
            //otherwise we tell them that the request failed, and we tell them which passsword and user it failed with
            res.send({ status: "failed", userid: thisUser, password: passAttempt });
        }
    });
});
/*

If you are trying to implement an application with any kind of security you should remove this last request,
or at the very least add some restriction to who calls it, but I like it as a debugging tool, especially
when the server is running on another machine.

*/
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
