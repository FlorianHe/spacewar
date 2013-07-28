//
// Sun.hh for spacewar(convert) in /home/antoine/Desktop/spacewar
// 
// Made by antoine paquet
// Login   <paquet_a@epitech.net>
// 
// Started on  Sun Jul 28 05:55:33 2013 antoine paquet
// Last update Sun Jul 28 19:55:46 2013 bastien debret
//

#ifndef __SUN_HH__
#define __SUN_HH__

#include "AObject.hh"
#include <iostream>

class	       	Sun : public AObject
{
public:
  Sun(int const &x, int const &y, sf::Sprite const &sprite);
  ~Sun();

  void 		draw(SpaceWar &game);
};

#endif
