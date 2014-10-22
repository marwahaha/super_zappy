//
// AuthentificationListener.cpp for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Mon Oct 20 14:27:00 2014 
// Last Update Wed Oct 22 11:24:39 2014 
//

#include "core/Server.hh"
#include "debug/LogManager.hh"
#include "network/Protocol.hh"
#include "network/listeners/AuthentificationListener.hh"

#include <cstdio>
#include <cstring>

AuthentificationListener::AuthentificationListener()
{
}

AuthentificationListener::~AuthentificationListener()
{
}


void
AuthentificationListener::graphicAuthentification(Client* client)
{
  const Server*	server = Server::accessServer();
  char		buffer[0x1000];

  client->setGraphic();

  sprintf(buffer, "ISL %d %d %d",
	  server->getSpeed(), server->getLonger(), server->getLarger());
  *client << buffer;

  LogManagerSingleton::access()->connection.print("Client %d authentified as graphic.",
						  client->getFd());
}

bool
AuthentificationListener::listenFromClient(Client* client, char* message)
{
  bool	authentified;

  authentified = true;
  if (!strcmp(message, AUTHENTIFICATION_GRAPHICAL))
    this->graphicAuthentification(client);
  else
    authentified = false;

  return (authentified);
}
