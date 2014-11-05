//
// GraphicListener.cpp for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Mon Oct 20 14:27:00 2014 
// Last Update Wed Nov  5 13:21:29 2014 
//

#include "core/Server.hh"
#include "debug/LogManager.hh"
#include "network/listeners/GraphicListener.hh"

#include <cstdlib>

GraphicListener::GraphicListener()
{
  this->initCommand("CHK", 3, &GraphicListener::sendChunkData);
  this->initCommand("CAS", 3, &GraphicListener::sendHooplaData);
  this->initCommand("PDC", 2, &GraphicListener::sendPlayerData);
  this->initCommand("TDC", 2, &GraphicListener::sendTeamData);
}

GraphicListener::~GraphicListener()
{
}


void
GraphicListener::sendHooplaData(Client* client, const Hoopla& hoopla,
				unsigned int x, unsigned int y) const
{
  char	buffer[0x1000];

  sprintf(buffer, "CAS %d %d %d %d %d %d %d %d",
	  x, y,
	  hoopla.ground, (int)hoopla.height,
	  hoopla.item, hoopla.itemNumber,
	  hoopla.object, hoopla.player_id);
  *client << buffer;
}

void
GraphicListener::sendTeamData(Client* client, const Team& team, unsigned int id) const
{
  char	buffer[0x1000];

  sprintf(buffer, "TDC %d %s %d", id, team.getName(), team.isDiscalified());
  *client << buffer;
}


bool
GraphicListener::sendChunkData(Client* client, char* const* args) const
{
  const Map*	map = this->getServerData();
  const Chunk*	chunk;
  char		buffer[0x1000];
  unsigned int	x;
  unsigned int	y;
  unsigned int	hx;
  unsigned int	hy;
  bool		valid;

  x = atoi(args[1]);
  y = atoi(args[2]);

  valid = IS_GOOD_CHUNK_POS(x, y, map);
  if (valid == false)
    LogManagerSingleton::access()->error.print("Trying to get an invalid chunk : %d/%d.",
					       x, y);
  else
    {
      chunk = &map->getChunk(x, y);
      sprintf(buffer, "CHK %d %d", x, y);
      *client << buffer;
      for (hx = 0; hx < CHUNK_SIZE; ++hx)
	for (hy = 0; hy < CHUNK_SIZE; ++hy)
	  this->sendHooplaData(client, chunk->getHoopla(hx, hy),
			       x * CHUNK_SIZE + hx, y * CHUNK_SIZE + hy);
    }

  return (valid);
}

bool
GraphicListener::sendHooplaData(Client* client, char* const* args) const
{
  const Map*	map = this->getServerData();
  unsigned int	x;
  unsigned int	y;
  bool		valid;

  x = atoi(args[1]);
  y = atoi(args[2]);

  valid = IS_GOOD_HOOPLA_POS(x, y, map);
  if (valid == false)
    LogManagerSingleton::access()->error.print("Trying to get an invalid hoopla : %d/%d.",
					       x, y);
  else
    this->sendHooplaData(client,
			 map->getChunk(x / CHUNK_SIZE, y / CHUNK_SIZE)
			 .getHoopla(x % CHUNK_SIZE, y % CHUNK_SIZE),
			 x, y);

  return (valid);
}

bool
GraphicListener::sendPlayerData(Client* client, char* const* args) const
{
  (void)(client);
  (void)(args);
  return (true);
}

bool
GraphicListener::sendTeamData(Client* client, char* const* args) const
{
  const GameData*       gameData = this->getServerData();
  unsigned int		id;
  bool			valid;

  id = atoi(args[1]);
  valid = (id >= gameData->getTeamsNumber());
  if (valid == false)
    LogManagerSingleton::access()->error.print("Invalid team id %d.", id);
  else
    this->sendTeamData(client, gameData->getTeams()[id], id);

  return (valid);
}
