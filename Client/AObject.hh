//
// AObject.hh for spacewar(convert) in /home/antoine/Desktop/spacewar
// 
// Made by antoine paquet
// Login   <paquet_a@epitech.net>
// 
// Started on  Sun Jul 28 05:57:22 2013 antoine paquet
// Last update Sun Jul 28 19:49:17 2013 bastien debret
//

#ifndef __AOBJECT_HH__
#define __AOBJECT_HH__

#include <iostream>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "Position.hh"

class SpaceWar;

class		AObject
{
protected:
  Position		*_pos;
  sf::Sprite		_sprite;

public:
  AObject(int const &, int const &, sf::Sprite const &sprite);
  virtual		~AObject();

  virtual void	       	draw(SpaceWar &game) = 0;
};

#endif
