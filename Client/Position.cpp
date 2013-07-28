//
// Position.cpp for spacewar(convert) in /home/antoine/Desktop/spacewar
// 
// Made by antoine paquet
// Login   <paquet_a@epitech.net>
// 
// Started on  Sun Jul 28 05:51:31 2013 antoine paquet
// Last update Sun Jul 28 19:51:44 2013 bastien debret
//

#include			"Position.hh"

Position::Position(int const &x, int const &y)
  : _x(x), _y(y)
{
}

Position::~Position()
{
}

void				Position::setX(int const &x)
{
  this->_x = x;
}

void				Position::setY(int const &y)
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
