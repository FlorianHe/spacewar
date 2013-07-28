//
// Except.cpp for for spacewar in /home/antoine/Desktop/spacewar
// 
// Made by antoine paquet
// Login   <paquet_a@epitech.net>
// 
// Started on  Sun Jul 28 05:50:06 2013 antoine paquet
// Last update Sun Jul 28 14:48:39 2013 antoine paquet
//

#include "Except.hh"

const char		*Except::what() const throw()
{
  return (this->msg.c_str());
}

Except::Except(const std::string &msg) throw() : msg(msg)
{
}

Except::~Except() throw()
{
}
