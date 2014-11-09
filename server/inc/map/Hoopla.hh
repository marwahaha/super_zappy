//
// Hoopla.hh for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Sun Oct 12 07:28:24 2014 
// Last Update Sun Nov  9 07:14:22 2014 
//

#ifndef HOOPLA_HH_
# define HOOPLA_HH_

# define MAX_ITEMS_BY_HOOPLA	(5)

# define MAX_HEIGHT		(9)
# define MIN_HEIGHT		(0.2f)
# define MAX_MOISTURE		(9)
# define MIN_MOISTURE		(0)

# define COLD_HEIGHT		(7.0f)
# define INTERMEDIATE_HEIGHT	(5.0f)
# define HOT_HEIGHT		(3.0f)

# define LOW_GROUND		(Hoopla::ocean)
# define HIGH_GROUND		(Hoopla::snow)

# define IS_EMPTY(hoopla)	((hoopla).hasPlayer == false && (hoopla).object == Hoopla::nothing)

struct	Hoopla
{
  enum	EGround
  {
    snow,
    bare,
    tundra,
    taiga,
    shrubland,
    sludge,
    temperate_jungle,
    temperate_forest,
    tallgrass,
    grassland,
    plain,
    desert,
    tropical_jungle,
    tropical_forest,
    marsh,
    beach,
    river,
    lake,
    ice,
    ocean,
    grounds_number
  };

  enum	EItem
  {
    none,
    items_number
  };

  enum	EObject
  {
    nothing,
    bush,
    shrub,
    oak,
    ash,
    saplin,
    maple,
    player,
    objects_number
  };

  unsigned char		ground;
  float			height;
  unsigned char		item;
  unsigned char		itemNumber;
  unsigned char		object;
  bool		        hasPlayer;

  Hoopla();
  ~Hoopla();
};

#endif // !HOOPLA_HH_
