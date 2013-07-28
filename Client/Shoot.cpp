//
// Shoot.cpp for spacewar(convert) in /home/antoine/Desktop/spacewar
// 
// Made by antoine paquet
// Login   <paquet_a@epitech.net>
// 
// Started on  Sun Jul 28 05:53:29 2013 antoine paquet
// Last update Sun Jul 28 06:01:54 2013 antoine paquet
//

#include "Shoot.hh"
#include "SpaceWar.hh"

Shoot::Shoot(int x, int y, sf::Sprite sprite, int nb)
  : AObject(x, y, sprite), _nb(nb)
{
}

Shoot::~Shoot()
{
}

void	Shoot::draw(SpaceWar &game)
{
  this->_sprite.SetPosition(this->_pos->getX(), this->_pos->getY());
  game.getApp().Draw(this->_sprite);
}

int			Shoot::getNb() const
{
  return (this->_nb);
}
