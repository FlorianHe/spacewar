//
// Position.hh for spacewar(convert) in /home/antoine/Desktop/spacewar
// 
// Made by antoine paquet
// Login   <paquet_a@epitech.net>
// 
// Started on  Sun Jul 28 05:51:55 2013 antoine paquet
// Last update Sun Jul 28 14:53:18 2013 antoine paquet
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
  Position(int x, int y);
  ~Position();

public:
  void		setX(int x);
  void		setY(int y);

public:
  int		getX() const;
  int		getY() const;
};

#endif
