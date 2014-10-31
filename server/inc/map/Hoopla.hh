//
// Hoopla.hh for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Sun Oct 12 07:28:24 2014 
// Last Update Tue Oct 28 14:53:12 2014 
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

class	Hoopla
{
public:
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
    bush,
    shrub,
    oak,
    ash,
    saplin,
    maple,
    objects_number
  };

public:
  unsigned char		ground;
  float			height;
  unsigned char		item;
  unsigned char		itemNumber;
  unsigned char		object;
  unsigned short	player_id;

public:
  Hoopla();
  ~Hoopla();
};

#endif // !HOOPLA_HH_
