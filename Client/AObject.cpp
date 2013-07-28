//
// AObject.cpp for spacewar(convert) in /home/antoine/Desktop/spacewar
// 
// Made by antoine paquet
// Login   <paquet_a@epitech.net>
// 
// Started on  Sun Jul 28 05:37:27 2013 antoine paquet
// Last update Sun Jul 28 05:37:28 2013 antoine paquet
//

#include		"AObject.hh"
#include		"SpaceWar.hh"
#include		"Position.hh"

AObject::AObject(int x, int y, sf::Sprite sprite)
  : _sprite(sprite)
{
  this->_pos = new Position(x, y);
}

AObject::~AObject()
{
}
