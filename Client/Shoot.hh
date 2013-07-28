//
// Shoot.hh for spacewar(convert) in /home/antoine/Desktop/spacewar
// 
// Made by antoine paquet
// Login   <paquet_a@epitech.net>
// 
// Started on  Sun Jul 28 05:54:10 2013 antoine paquet
// Last update Sun Jul 28 19:54:23 2013 bastien debret
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
  Shoot(int const &, int const &, sf::Sprite const &, int const &);
  ~Shoot();

  void 		draw(SpaceWar &game);
  int	       	getNb() const;
};

#endif
