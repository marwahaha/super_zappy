//
// ATerraformer.hpp for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Wed Oct 22 14:24:54 2014 
// Last Update Wed Oct 22 14:25:22 2014 
//

#include "map/Chunk.hh"

const Hoopla&
ATerraformer::getHoopla(unsigned int x, unsigned int y) const
{
  return (m_hooplas[y * m_configs.longer * CHUNK_SIZE + x]);
}
