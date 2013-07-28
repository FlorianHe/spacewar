//
// SpaceWar.hh for spacewar(convert) in /home/antoine/Desktop/spacewar
// 
// Made by antoine paquet
// Login   <paquet_a@epitech.net>
// 
// Started on  Sun Jul 28 05:55:05 2013 antoine paquet
// Last update Sun Jul 28 14:51:22 2013 antoine paquet
//

#ifndef __SPACEWAR_HH__
#define __SPACEWAR_HH__

#include <iostream>
#include <vector>
#include <sstream>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include "Sun.hh"
#include "Network.hh"

class	Ship;
class	Shoot;

class			SpaceWar
{
protected:
  bool			_run;
  sf::RenderWindow      _app;
  sf::Event             _event;
  Network		*_network;
  std::vector<std::string>	_rep;
  std::vector<Ship *>	_ships;
  std::stringstream	_params;
  sf::Image		_ship1;
  sf::Sprite		_ship2;
  Sun			*_sun;
  sf::Image		_sun1;
  sf::Sprite		_sun2;
  std::vector<Shoot *>	_shoots;
  sf::Image		_shoot1;
  sf::Sprite		_shoot2;

public:
  SpaceWar();
  ~SpaceWar();

  void			initialize();
  void			run();
  void			update();
  void			draw();

  void			addShip();
  void			moveShip();
  void			rotateShip();
  void			addShoot();
  void			eraseShoot();
  void			eraseShip();
  void			updateGas();

  sf::RenderWindow	&getApp();
};

#endif
