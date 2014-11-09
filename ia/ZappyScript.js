//
// Script.js for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/ia
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Thu Nov  6 14:27:41 2014 
// Last Update Sun Nov  9 09:00:18 2014 
//

load("Objects.js");
load("Vector.js");

function	ZappyScript()
{
    this.ring = new java.util.concurrent.locks.ReentrantLock(true);
    this.ring.lock();
    this.messages = [];
}

ZappyScript.prototype.copy = function()
{
    script = new ZappyScript;

    script.start = this.start;
    script.play = this.play;

    for (var attr in this)
    {
        if (this.hasOwnProperty(attr))
	{
	    script[attr] = this[attr];
	}
    }

    return (script);
}

ZappyScript.prototype.start = function()
{
    var	waiting;
    var message;

    waiting = true;

    while (waiting)
    {
	message = this.waitForAnswer("START");
	if (message[0] == "true")
	{
	    waiting = false;
	}
    }

    this.play();
}


ZappyScript.prototype.sendMessage = function(message)
{
    this.messages.push(message);
    this.ring.unlock();
    this.ring.lock();
}

ZappyScript.prototype.readUnexpectedMessage = function(message)
{
    print("MESSAGE : " + message[1]);
}

ZappyScript.prototype.waitForAnswer = function(wanted)
{
    var	answer;
    var message;

    answer = null;

    while (answer == null)
    {
	if (this.messages.length > 0)
	{
	    message = this.messages[0];
	    this.messages.shift();
	    if (message[0] == wanted)
	    {
		message.shift();
		answer = message;
	    }
	    else
	    {
		this.readUnexpectedMessage(message);
	    }
	}
	else
	{
	    this.ring.lock();
	    this.ring.unlock();
	}
    }

    return (answer);
}


ZappyScript.prototype.displace = function(x, y)
{
    var	answer;

    client.send("DIS " + this.player.name + ' ' + x + ' ' + y);
    answer = this.waitForAnswer("END");

    return (answer[0] == "true");
}

ZappyScript.prototype.search = function(object)
{
    var	answer;
    var	found;

    client.send("SRH " + this.player.name + ' ' + object.id);
    answer = this.waitForAnswer("OBJECT");

    if (answer[0] == "NULL")
    {
	found = null;
    }
    else
    {
	found = new Object(parseInt(answer[0]));
	found.position.x = parseInt(answer[1]);
	found.position.y = parseInt(answer[2]);
    }

    return (found);
}
