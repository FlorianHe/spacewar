//
// Sun.cpp for spacewar(conver) in /home/antoine/Desktop/spacewar
// 
// Made by antoine paquet
// Login   <paquet_a@epitech.net>
// 
// Started on  Sun Jul 28 05:55:42 2013 antoine paquet
// Last update Sun Jul 28 05:55:59 2013 antoine paquet
//

#include "Sun.hh"
#include "SpaceWar.hh"

Sun::Sun(int x, int y, sf::Sprite sprite)
  : AObject(x, y, sprite)
{
}

Sun::~Sun()
{
}

void			Sun::draw(SpaceWar &game)
{
  this->_sprite.SetPosition(this->_pos->getX(), this->_pos->getY());
  game.getApp().Draw(this->_sprite);
}
