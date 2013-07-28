//
// main.cpp for spacewar(convert) in /home/antoine/Desktop/spacewar
// 
// Made by antoine paquet
// Login   <paquet_a@epitech.net>
// 
// Started on  Sun Jul 28 05:37:57 2013 antoine paquet
// Last update Sun Jul 28 14:51:59 2013 antoine paquet
//

#include		"SpaceWar.hh"
#include		"Except.hh"

int			main()
{
  SpaceWar		*game;

  try
    {
      game = new SpaceWar();
      game->initialize();
      game->run();
    }
  catch (const Except &e)
    {
      std::cerr << e.what () << std::endl;
    }
  return (0);
}
