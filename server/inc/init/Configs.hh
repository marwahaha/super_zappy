//
// Configs.hh for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Sun Oct 12 05:32:05 2014 
// Last Update Sun Nov  9 04:59:05 2014 
//

#ifndef CONFIGS_HH_
# define CONFIGS_HH_

# include "Teams.hh"

# define DEFAULT_PORT		(4242)
# define DEFAULT_SPEED		(10000)
# define DEFAULT_MAP_WIDTH	(4)
# define DEFAULT_MAP_HEIGHT	(4)

# define PORT_MIN		(0x401)
# define PORT_MAX		(0xFFFF)
# define SPEED_MIN		(1000)
# define SPEED_MAX		(10000000)
# define MAP_SIZE_MIN		(4)
# define MAP_SIZE_MAX		(256)
# define TEAMS_NUMBER_MIN	(2)

# define FLAGS_NUMBER		(5)

class	Configs
{
public:
  struct		Map
  {
    Map(unsigned int width, unsigned int height);

    unsigned int	width;
    unsigned int	height;
  };

private:
  typedef void	(Configs::*ParamReader)(char* arg);

private:
  Map		m_map;
  unsigned int	m_port;
  unsigned int	m_speed;
  Teams		m_teams;
  ParamReader	m_paramReader;

public:
  Configs();
  ~Configs();

private:
  void	changePort(char* port);
  void	changeSpeed(char* speed);
  void	changeMapWidth(char* width);
  void	changeMapHeight(char* height);
  void	addTeam(char* team);

private:
  void	emplFlagsTabs(ParamReader* readers, char* flags);
  void	changeReader(char flag);
  void	readArg(char* arg);

public:
  void	readConfigs(int argc, char** argv);

public:
  inline const Teams&	getTeams() const;
  inline unsigned int	getPort() const;
  inline unsigned int	getSpeed() const;
  inline const Map&	getMapConfigs() const;
};

#include "Configs.hpp"

#endif // !CONFIGS_HH_
