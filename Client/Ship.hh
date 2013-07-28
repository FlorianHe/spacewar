//
// Ship.hh for spacewar(convert) in /home/antoine/Desktop/spacewar
// 
// Made by antoine paquet
// Login   <paquet_a@epitech.net>
// 
// Started on  Sun Jul 28 06:00:48 2013 antoine paquet
// Last update Sun Jul 28 19:53:31 2013 bastien debret
//

#ifndef __SHIP_HH__
#define __SHIP_HH__

#include		"AObject.hh"

class			Ship : public AObject
{
protected:
  int			_dir;
  int			_nb;

public:
  Ship(int const &nb, int const &x, int const &y, int const &dir, sf::Sprite const &sprite);
  ~Ship();

  void			draw(SpaceWar &game);

  void			setPos(int const &x, int const &y);
  void			setDir(int const &dir);

  int			getNb() const;
};

#endif
