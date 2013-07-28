//
// AObject.cpp for spacewar(convert) in /home/antoine/Desktop/spacewar
// 
// Made by antoine paquet
// Login   <paquet_a@epitech.net>
// 
// Started on  Sun Jul 28 05:37:27 2013 antoine paquet
// Last update Sun Jul 28 19:49:19 2013 bastien debret
//

#include		"AObject.hh"
#include		"SpaceWar.hh"
#include		"Position.hh"

AObject::AObject(int const &x, int const &y, sf::Sprite const &sprite)
  : _sprite(sprite)
{
  this->_pos = new Position(x, y);
}

AObject::~AObject()
{
}
