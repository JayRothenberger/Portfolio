This is a basic node http server that serves a website and some basic user functionality.  The login function then serves the
user a new page and an encoded password in the form of a token when the user logs in.  The page that it serves is stubbed right
now, but I'm planning to add to it in the future.  Below is a breif description of relevant files and their functionalities.

app.js: The JavaScript for the node server, this is the application that you will run, and it will serve you pages and 
answer your requests

serverdb.sql: The SQL schema containing the user table accessed by the server for user verification and storage

index.html: A basic login page with a draggable login form.

user.html: A stubbed page served after the user logs in. 

NOTE: the node modules: express, mysql, url, body-parser, path, are all required for this application, but are not included in the folder.