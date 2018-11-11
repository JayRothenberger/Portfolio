In the Bot folder is a sample discord application that I wrote in JavaScript on top of node utilizing the Discord.js library.  It has the
ability to clear messages from the chat, to acknowledge when the user has thanked it, list its commands to the user.  The
bot spilts the command into a command and arguments making this a suitable baseline for far more complex operations.  The
bot can also take multiple commands in a single text input by separating each of the commands by enclosing them in {}.  Below
is a list of relevant files and a breif description of the functionality of each.

app.js: this holds most of the code relevant to the bot's function, and it contains all of the implementation for all of 
the commands.

config.json: contains a stubbed field of the app token and a now deprecated field for the command prefix.

node_modules: contains all of the relevant files for node.