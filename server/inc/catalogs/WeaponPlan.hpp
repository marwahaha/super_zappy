//
// Weapon.hpp for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Tue Dec  9 14:17:46 2014 
// Last Update Tue Dec  9 16:12:46 2014 
//

unsigned int
WeaponPlan::getDamages() const
{
  return (m_damages);
}

unsigned int
WeaponPlan::getRange() const
{
  return (m_range);
}

Hoopla::EItem
WeaponPlan::getAmmo() const
{
  return (m_ammo);
}

unsigned int
WeaponPlan::getReloadTime() const
{
  return (m_reloadTime);
}
