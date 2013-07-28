//
// Ship.cpp for spacewar(convert) in /home/antoine/Desktop/spacewar
// 
// Made by antoine paquet
// Login   <paquet_a@epitech.net>
// 
// Started on  Sun Jul 28 05:53:11 2013 antoine paquet
// Last update Sun Jul 28 06:01:28 2013 antoine paquet
//

#include "Ship.hh"
#include "SpaceWar.hh"

Ship::Ship(int nb, int x, int y, int dir, sf::Sprite sprite)
  : AObject(x, y, sprite), _nb(nb), _dir(dir)
{
}

Ship::~Ship()
{
}

void                    Ship::draw(SpaceWar &game)
{
  this->_sprite.SetRotation(this->_dir);
  this->_sprite.SetPosition(this->_pos->getX(), this->_pos->getY());
  game.getApp().Draw(this->_sprite);
}

void			Ship::setPos(int x, int y)
{
  this->_pos->setX(x);
  this->_pos->setY(y);
}

void			Ship::setDir(int dir)
{
  this->_dir = dir;
}

int			Ship::getNb() const
{
  return (this->_nb);
}
