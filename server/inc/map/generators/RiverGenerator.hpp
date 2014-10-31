//
// RiverGenerator.hpp for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Mon Oct 27 17:41:11 2014 
// Last Update Tue Oct 28 15:38:53 2014 
//

bool
RiverGenerator::canHandleRiver(const Hoopla& hoopla) const
{
  return (hoopla.height / 10.0f > MIN_HEIGHT &&
	  hoopla.ground == Hoopla::ocean);
}
