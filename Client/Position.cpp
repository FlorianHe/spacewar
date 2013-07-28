//
// Position.cpp for spacewar(convert) in /home/antoine/Desktop/spacewar
// 
// Made by antoine paquet
// Login   <paquet_a@epitech.net>
// 
// Started on  Sun Jul 28 05:51:31 2013 antoine paquet
// Last update Sun Jul 28 05:51:37 2013 antoine paquet
//

#include			"Position.hh"

Position::Position(int x, int y)
  : _x(x), _y(y)
{
}

Position::~Position()
{
}

void				Position::setX(int x)
{
  this->_x = x;
}

void				Position::setY(int y)
{
  this->_y = y;
}

int				Position::getX() const
{
  return (this->_x);
}

int				Position::getY() const
{
  return (this->_y);
}
