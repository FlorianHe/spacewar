//
// Network.hh for spacewar(convert) in /home/antoine/Desktop/spacewar
// 
// Made by antoine paquet
// Login   <paquet_a@epitech.net>
// 
// Started on  Sun Jul 28 05:51:15 2013 antoine paquet
// Last update Sun Jul 28 14:57:28 2013 antoine paquet
//

#ifndef __NETWORK_HH__
#define __NETWORK_HH__

#include <iostream>
#include <SFML/Network.hpp>
#include <vector>
#include <string.h>

class			Network
{
protected:
  sf::SocketTCP         _client;
  sf::SelectorTCP       _selector;
  std::string		_data;
  std::vector<std::string>	_rep;
  float			_timeout;

public:
  Network();
  ~Network();

  void			connect();
  void			reading();
  void			sending(const std::string &cmd);
  void			running();
  void			disconnect();

  std::vector<std::string>	getRep();
};

#endif
