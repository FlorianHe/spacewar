//
// Shoot.hh for spacewar(convert) in /home/antoine/Desktop/spacewar
// 
// Made by antoine paquet
// Login   <paquet_a@epitech.net>
// 
// Started on  Sun Jul 28 05:54:10 2013 antoine paquet
// Last update Sun Jul 28 14:49:54 2013 antoine paquet
//

#ifndef __SHOOT_HH__
#define __SHOOT_HH__

#include       	<iostream>
#include       	"AObject.hh"

class  		Shoot : public AObject
{
protected:
  int  		_nb;

public:
  Shoot(int x, int y, sf::Sprite sprite, int nb);
  ~Shoot();

  void 		draw(SpaceWar &game);
  int	       	getNb() const;
};

#endif
