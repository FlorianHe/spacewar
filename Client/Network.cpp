//
// Network.cpp for spacewar(convert) in /home/antoine/Desktop/spacewar
// 
// Made by antoine paquet
// Login   <paquet_a@epitech.net>
// 
// Started on  Sun Jul 28 05:38:16 2013 antoine paquet
// Last update Sun Jul 28 14:57:15 2013 antoine paquet
//

#include		"Network.hh"
#include		"Except.hh"

Network::Network()
{
}

Network::~Network()
{
}

void			Network::connect()
{
  this->_timeout = 0;
  if (this->_client.Connect(4242, "127.0.0.1") != sf::Socket::Done)
    throw Except("Error with Connect()\n");
  this->_selector.Add(this->_client);
}

void			Network::reading()
{
  float             t;
  char              buff[1];
  std::size_t       size;
  std::string       tmp;

  tmp.clear();
  bzero(buff, 1);
  t = 0.01;
  if (this->_selector.Wait(t) > 0)
    {
      while (buff[0] != '\n')
	{
	  if (this->_client.Receive(buff, sizeof(buff), size) != sf::Socket::Done)
	    {
	      std::cerr << "ERROR TIMEOUT\n";
	      this->_timeout += 1;
	    }
	  if (buff[0] != '\n')
	    tmp += buff[0];
	  if (this->_timeout >= 30)
	    throw Except("[ERROR] Timeout is over");
	}
    }
  if (tmp.size() > 0)
    {
      tmp += "\n";
      this->_data.append(tmp);
    }
}

void			Network::sending(const std::string &cmd)
{
  if (this->_client.Send(cmd.c_str(), sizeof(cmd.c_str())) != sf::Socket::Done)
    throw Except("[ERROR] : Can't send to server.");
}

void			Network::running()
{
  std::size_t           found;
  std::size_t           start;
  std::string           tmp_rep;

  found = 1;
  start = 0;
  while (found != std::string::npos)
    {
      if ((found = this->_data.find('\n')) != std::string::npos)
        {
          tmp_rep = this->_data.substr(start, found);
	  this->_rep.push_back(tmp_rep);
          this->_data.erase(0, found + 1);
        }
    }

}

std::vector<std::string>	Network::getRep()
{
  std::vector<std::string>	tmp;

  if (!this->_rep.empty())
    {
      tmp = this->_rep;
      this->_rep.clear();
    }
  else
    tmp.push_back("ERROR");
  return (tmp);
}

void                            Network::disconnect()
{
  this->_selector.Remove(this->_client);
}

