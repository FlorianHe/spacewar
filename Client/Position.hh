//
// Position.hh for spacewar(convert) in /home/antoine/Desktop/spacewar
// 
// Made by antoine paquet
// Login   <paquet_a@epitech.net>
// 
// Started on  Sun Jul 28 05:51:55 2013 antoine paquet
// Last update Sun Jul 28 19:51:53 2013 bastien debret
//

#ifndef __POSITION_HH__
#define __POSITION_HH__

#include <iostream>

class	Position
{
protected:
  int		_x;
  int		_y;

public:
  Position(int const &x, int const &y);
  ~Position();

public:
  void		setX(int const &x);
  void		setY(int const &y);

public:
  int		getX() const;
  int		getY() const;
};

#endif
