//
// PerlinMap.cpp for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Fri Oct 24 17:14:09 2014 
// Last Update Fri Oct 24 17:56:52 2014 
//

#include "abstractions/allocs.hh"
#include "map/Chunk.hh"
#include "map/generators/PerlinMap.hh"

#include <cmath>

PerlinMap::PerlinMap(unsigned int longer, unsigned int larger,
		     unsigned int step, unsigned int octavesNumber) :
  HeightMap(longer, larger),
  m_step(step),
  m_octavesNumber(octavesNumber),
  m_maxLonger(ceilf((float)(longer * 10) / step)),
  m_maxLarger(ceilf((float)(larger * 10) / step))
{
  m_step = 20 + (longer + larger) / CHUNK_SIZE;
  MALLOC(m_numbers, m_maxLonger * m_maxLarger, float);
  this->randomiseNumbers();
}

PerlinMap::~PerlinMap()
{
  free(m_numbers);
}


void
PerlinMap::randomiseNumbers()
{
  unsigned int	i;

  for (i = 0; i < m_maxLonger * m_maxLarger; ++i)
    m_numbers[i] = random() % 100 - 50;
}


float
PerlinMap::getNumber(unsigned int x, unsigned int y) const
{
  return (m_numbers[y * m_maxLonger + x]);
}

float
PerlinMap::interpolationCos(float a, float b, float x) const
{
  float	k;

  k = (1 - cosf(x * M_PI)) / 2.0f;
  return (a * (1.0f - k) + b * k);
}

float
PerlinMap::interpolationCos2D(float a, float b, float c, float d, float x, float y) const
{
  float	y1;
  float	y2;

  y1 = this->interpolationCos(a, b, x);
  y2 = this->interpolationCos(c, d, x);
  return (this->interpolationCos(y1, y2, y));
}

float
PerlinMap::getNoise(unsigned int x, unsigned int y) const
{
  unsigned int	posx;
  unsigned int	posy;

  posx = (x / m_step);
  posy = (y / m_step);
  return (this->interpolationCos2D(this->getNumber(posx + 0, posy + 0),
				   this->getNumber(posx + 1, posy + 0),
				   this->getNumber(posx + 0, posy + 1),
				   this->getNumber(posx + 1, posy + 1),
				   fmodf(x / (float)m_step, 1), fmodf(y / (float)m_step, 1)));
}


int
PerlinMap::calcHeight(unsigned int x, unsigned int y)
{
  float		sum;
  float		p;
  unsigned int	i;
  unsigned int	power;

  sum = 0.0f;
  p = 1.0f;
  power = 1;
  for (i = 0; i < m_octavesNumber; ++i)
    {
      sum += p * this->getNoise(x * power, y * power);
      p *= PERLIN_PERSISTANCE;
      power *= 2;
    }

  return ((int)sum);
}
