//
// Ship.hh for spacewar(convert) in /home/antoine/Desktop/spacewar
// 
// Made by antoine paquet
// Login   <paquet_a@epitech.net>
// 
// Started on  Sun Jul 28 06:00:48 2013 antoine paquet
// Last update Sun Jul 28 14:55:08 2013 antoine paquet
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
  Ship(int nb, int x, int y, int dir, sf::Sprite sprite);
  ~Ship();

  void			draw(SpaceWar &game);

  void			setPos(int x, int y);
  void			setDir(int dir);

  int			getNb() const;
};

#endif
