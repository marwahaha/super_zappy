//
// Hoopla.hh for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Sun Oct 12 07:28:24 2014 
// Last Update Wed Oct 22 14:49:06 2014 
//

#ifndef HOOPLA_HH_
# define HOOPLA_HH_

# define MAX_ITEMS_BY_HOOPLA	(5)

# define MAX_HEIGHT		(10)
# define MAX_MOISTURE		(10)

class	Hoopla
{
public:
  enum	EGround
  {
    snow,
    bare,
    tundra,
    taiga,
    shurbland,
    rocky_desert,
    temperate_jungle,
    temperate_forest,
    tallgrass,
    grassland,
    plain,
    desert,
    tropical_jungle,
    tropical_forest,
    beach,
    ocean,
    grounds_number
  };

public:
  enum	EItem
  {
    none,
    items_number
  };

public:
  enum	EObject
  {
    nothing,
    objects_number
  };

public:
  EGround	ground;
  unsigned int	height;
  EItem		item;
  unsigned int	itemNumber;
  EObject	object;
  unsigned int	player_id;

public:
  Hoopla();
  ~Hoopla();
};

#endif // !HOOPLA_HH_
