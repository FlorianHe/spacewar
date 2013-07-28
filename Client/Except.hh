//
// Except.hh for spacewar(convert) in /home/antoine/Desktop/spacewar
// 
// Made by antoine paquet
// Login   <paquet_a@epitech.net>
// 
// Started on  Sun Jul 28 05:58:25 2013 antoine paquet
// Last update Sun Jul 28 05:58:40 2013 antoine paquet
//

#ifndef __EXCEPT_HH__
#define __EXCEPT_HH__

#include <string>
#include <exception>

class	Except : public std::exception
{
public:
  Except(const std::string &msg) throw();
  virtual ~Except() throw();
  virtual const char	*what() const throw();

private:
  std::string	msg;
};

#endif
