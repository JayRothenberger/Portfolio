// Load up the discord.js library
const Discord = require("discord.js");
var owjs = require('overwatch-js');
const client = new Discord.Client();
const config = require("./config.json");
//const pen = require("./TonyPen.js")
    var tagR = RegExp('[A-Za-z]*(-|#)[0-9]*');
    var discR = RegExp('[A-Za-z]*;[0-9]*');
    var politeExp = RegExp('(please|thank you|thanks|pls|plz)');
    var tag;
    var elim = 0;
    var elim2 = 0;

// This is your client. Some people call it `bot`, some people call it `self`, 
// some might call it `cootchie`. Either way, when you see `client.something`, or `bot.something`,
// this is what we're refering to. Your client.


// Here we load the config.json file that contains our token and our prefix values. 

// config.token contains the bot's token
// config.prefix contains the message prefix.

client.on("ready", () => {
  // This event will run if the bot starts, and logs in, successfully.
  console.log(`Bot has started, with ${client.users.size} users, in ${client.channels.size} channels of ${client.guilds.size} guilds.`); 
  // Example of changing the bot's playing game to something useful. `client.user` is what the
  // docs refer to as the "ClientUser".
  client.user.setActivity(`on ${client.guilds.size} servers`);
});

client.on("guildCreate", guild => {
  // This event triggers when the bot joins a guild.
  console.log(`New guild joined: ${guild.name} (id: ${guild.id}). This guild has ${guild.memberCount} members!`);
  client.user.setActivity(`on ${client.guilds.size} servers`);
});

client.on("guildDelete", guild => {
  // this event triggers when the bot is removed from a guild.
  console.log(`I have been removed from: ${guild.name} (id: ${guild.id})`);
  client.user.setActivity(`on ${client.guilds.size} servers`);
});


client.on("message", async message => {
  // This event will run on every single message received, from any channel or DM.
  
  // It's good practice to ignore other bots. This also makes your bot ignore itself
  // and not get into a spam loop (we call that "botception").
  if(message.author.bot) return;
  
    var reg = /{([a-z]+|\s+|\-+|\#+|[0-9]+)+}/g;
    
  console.log("Message.content: '" + message.content.toLowerCase() + "' Matches reg: " + message.content.toLowerCase().match(/{([a-z]+|\s+|\-+|\#+|[0-9]+)+}/g))
    
  if(!message.content.toLowerCase().match(/{([a-z]+|\s+|\-+|\#+|[0-9]+)+}/g)) return;
  
  // Here we separate our "command" name, and our "arguments" for the command. 
  // e.g. if we have the message "{say Is this the real life?}" , we'll get the following:
  // command = say
  // args = ["Is", "this", "the", "real", "life?"]
  
const arg = message.content.trim().match(/{([A-Z]+|[a-z]+|\s+|\-+|\#+|[0-9]+)+}/g);
    message.content.toLowerCase().match(/{([a-z]+|\s+|\-+|\#+|[0-9]+)+}/g).forEach(async function(element, index, array){
        var soFar;
        for(var i = 0; index >= i; i++){
            message.content.toLowerCase().match(/{([a-z]+|\s+|\-+|\#+|[0-9]+)+}/g)[i];
            
        }
    var args = arg[index].trim().replace(/{|}/g, "").split(/ +/g);
    var command = args[0];
        
    console.log("args: ", arg, "args for this command: ", args, "command: ", command, "index: ", index)

  if(command === "purge" || command === "clean" || command === "clear") {
    // This command removes all messages from all users in the channel, up to 100.
    
    // get the delete count, as an actual number.

    const deleteCount = parseInt(args[0], 10) + 1;
    // Ooooh nice, combined conditions. <3

    if(!deleteCount || deleteCount < 2 || deleteCount > 100)
      return message.reply("Please provide a number between 1 and 100 for the number of messages to delete");
    
    // So we get our messages, and delete them. Simple enough, right?
    const fetched = await message.channel.fetchMessages({limit: deleteCount});
    message.channel.bulkDelete(fetched)
      .catch(error => message.reply(`Couldn't delete messages because of: ${error}`));
  }

    if(command === "help"){
    message.author.send("no")
 
    }
        
    if(politeExp.exec(message.content.toLowerCase())){
    
    message.reply("sure, no problem.")
    }
        
    if(command === "say"){
        
        message.delete()
        message.channel.send(args.join(" "))
        
    }
    if(command === "rank"){
        //clean the input for the API
        var me = args[1].replace('#', '-')
        //create a virtual window to run jQuery in
        var jsdom = require('jsdom');
        const { JSDOM } = jsdom;
        const { window } = new JSDOM();
        const { document } = (new JSDOM('')).window;
        global.document = document;
        //run jQuery on the document we are pretending exists
        var $ = jQuery = require('jquery')(window);

        //here is the url for the api with the command argument battletag
        var url = 'https://ow-api.com/v1/stats/pc/us/' + me + '/profile';
        
        //log the url for debugging
        console.log("Url: " + url)
        $.get(url, function(data, status){
            
        //the data returned from the API was a JSON once or twice, but now it is a string?
        console.log(data)
            
        if(data.private)//profiles that are private cannot be read
            message.reply("your profile seems to be private, I cannot see it")
        else //because the JSON is pretending to be a string we must parse it
            message.reply("your rank is: " + JSON.parse(data).rating)
        });

    }
    });
    


});

client.login(config.token);