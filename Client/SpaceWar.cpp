//
// SpaceWar.cpp for spacewar in /home/antoine/Desktop/spacewar
// 
// Made by antoine paquet
// Login   <paquet_a@epitech.net>
// 
// Started on  Sun Jul 28 03:09:59 2013 antoine paquet
// Last update Sun Jul 28 15:07:58 2013 antoine paquet
//

#include "SpaceWar.hh"
#include "Network.hh"
#include "Ship.hh"
#include "Sun.hh"
#include "Shoot.hh"
#include "Except.hh"
#include <stdlib.h>

SpaceWar::SpaceWar()
  : _run(true)
{
}

SpaceWar::~SpaceWar()
{
  this->_network->disconnect();
  delete this->_network;
}

void				SpaceWar::initialize()
{
  if (!this->_ship1.LoadFromFile("./Client/sprite/ship.jpg"))
    throw Except("Error loadfromfile");
  this->_ship2.SetImage(this->_ship1);
  if (!this->_sun1.LoadFromFile("./Client/sprite/sun.jpg"))
    throw Except("Error loadfromfile");
  this->_sun2.SetImage(this->_sun1);
  if (!this->_shoot1.LoadFromFile("./Client/sprite/shoot.jpg"))
    throw Except("Error loadfromfile");
  this->_shoot2.SetImage(this->_shoot1);
  this->_app.Create(sf::VideoMode(800, 800, 32), "SpaceWar");
  this->_network = new Network();
  this->_network->connect();
  this->_sun = new Sun(380, 380, this->_sun2);
}

void				SpaceWar::run()
{
  std::vector<std::string>::iterator	it;
  std::string				tmp;
  std::string				id;

  while (this->_run != false)
    {
      this->_network->reading();
      this->_network->running();
      this->_rep = this->_network->getRep();
      if (!this->_rep.empty())
	{
	  it = this->_rep.begin();
	  while (it != this->_rep.end())
	    {
	      tmp = *it;
	      if (tmp != "ERROR")
		{
		  std::cout << "REP <"<< *it << ">" << std::endl;
		  this->_params.clear();
		  this->_params.str(tmp);
		  this->_params >> id;
		  if (id == "New")
		    addShip();
		  if (id == "Ava")
		    moveShip();
		  if (id == "Dro"
		      || id == "Gau")
		    rotateShip();
		  if (id == "Tir")
		    addShoot();
		  if (id == "MoT")
		    eraseShoot();
		  if (id == "Ess")
		    updateGas();
		  if (id == "Mor")
		    eraseShip();
		}
	      ++it;
	    }
	}
      update();
      draw();
    }
}

void			SpaceWar::update()
{
  const sf::Input &input = this->_app.GetInput();

  while (this->_app.GetEvent(this->_event))
    {
      if ((this->_event.Type == sf::Event::Closed)
          || ((this->_event.Type == sf::Event::KeyPressed) && (this->_event.Key.Code == sf::Key::Escape)))
        {
          this->_run = false;
          this->_app.Close();
        }
      if (input.IsKeyDown(sf::Key::Up))
        {
	  std::cout << "[SENDING] : Avance\\n" << std::endl;
	  this->_network->sending("Avance\n");
        }
      if (input.IsKeyDown(sf::Key::Right))
        {
	  std::cout << "[SENDING] : Droite\\n" << std::endl;
	  this->_network->sending("Droite\n");
        }
      if (input.IsKeyDown(sf::Key::Left))
        {
	  std::cout << "[SENDING] : Gauche\\n" << std::endl;
	  this->_network->sending("Gauche\n");
        }
      if (input.IsKeyDown(sf::Key::Space))
        {
	  std::cout << "[SENDING] : Tir\\n" << std::endl;
	  this->_network->sending("Tir\n");
        }
    }
}

void			SpaceWar::draw()
{
  std::vector<Ship *>::iterator		it;
  std::vector<Shoot *>::iterator	it2;
  int					i;

  i = 0;
  this->_app.Clear(sf::Color(0, 0, 0));
  if (!this->_ships.empty())
    {
      it = this->_ships.begin();
      while (it != this->_ships.end())
        {
          this->_ships[i]->draw(*this);
          ++i;
          ++it;
        }
    }
  i = 0;
  if (!this->_shoots.empty())
    {
      it2 = this->_shoots.begin();
      while (it2 != this->_shoots.end())
        {
          this->_shoots[i]->draw(*this);
          ++i;
          ++it2;
        }
    }
  this->_sun->draw(*this);
  this->_app.Display();
}

void			SpaceWar::addShip()
{
  std::string		nb;
  std::string		x;
  std::string		y;
  std::string		dir;

  this->_params >> nb >> x >> y >> dir;
  this->_ships.push_back(new Ship(atoi(nb.c_str()), atoi(x.c_str()),
				  atoi(y.c_str()), atoi(dir.c_str()), this->_ship2));
}

void			SpaceWar::eraseShip()
{
  std::vector<Ship *>::iterator	it;
  std::string		nb;
  int			i;
  int			x;

  i = 0;
  x = -1;
  this->_params >> nb;
  if (!this->_ships.empty())
    {
      it = this->_ships.begin();
      while (it != this->_ships.end())
	{
	  if (this->_ships[i]->getNb() == atoi(nb.c_str()))
	    x = i;
	  ++i;  
	  ++it;
	}
    }
  if (x != -1)
    this->_ships.erase(this->_ships.begin() + x);
}

void			SpaceWar::moveShip()
{
  std::vector<Ship *>::iterator	it;
  std::string		nb;
  std::string		x;
  std::string		y;
  int			i;

  i = 0;
  this->_params >> nb >> x >> y; 
  if (!this->_ships.empty())
    {
      it = this->_ships.begin();
      while (it != this->_ships.end())
	{
	  if (this->_ships[i]->getNb() == atoi(nb.c_str()))
	    this->_ships[i]->setPos(atoi(x.c_str()), atoi(y.c_str()));
	  ++i;  
	  ++it;
	}
    }
}

void			SpaceWar::rotateShip()
{
  std::vector<Ship *>::iterator	it;
  std::string		nb;
  std::string		dir;
  int			i;

  i = 0;
  this->_params >> nb >> dir;
  if (!this->_ships.empty())
    {
      it = this->_ships.begin();
      while (it != this->_ships.end())
	{
	  if (this->_ships[i]->getNb() == atoi(nb.c_str()))
	    this->_ships[i]->setDir(atoi(dir.c_str()));
	  ++i;  
	  ++it;
	}
    }
}

void			SpaceWar::addShoot()
{
  std::string		nb;
  std::string		x;
  std::string		y;

  this->_params >> nb >> x >> y;
  this->_shoots.push_back(new Shoot(atoi(x.c_str()), atoi(y.c_str()),
				   this->_shoot2, atoi(nb.c_str())));
}

void			SpaceWar::eraseShoot()
{
  std::vector<Shoot *>::iterator	it;
  std::string		nb;
  int			i;
  int			x;

  i = 0;
  x = -1;
  this->_params >> nb;
  if (!this->_shoots.empty())
    {
      it = this->_shoots.begin();
      while (it != this->_shoots.end())
	{
	  if (this->_shoots[i]->getNb() == atoi(nb.c_str()))
	    x = i;
	  ++i;  
	  ++it;
	}
    }
  if (x != -1)
    this->_shoots.erase(this->_shoots.begin() + x);
}

void			SpaceWar::updateGas()
{
  std::string		nb;
  std::string		qt;

  this->_params >> nb >> qt;
  std::cout << "[INFO] Gas remaining : " << qt << std::endl;

}

sf::RenderWindow	&SpaceWar::getApp()
{
  return (this->_app);
}
