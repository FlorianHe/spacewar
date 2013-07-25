//
// main.cpp for spacewar in /home/antoine/spacewar/dev
// 
// Made by antoine paquet
// Login   <paquet_a@epitech.net>
// 
// Started on  Tue Jul 23 13:25:12 2013 antoine paquet
// Last update Thu Jul 25 14:55:21 2013 antoine paquet
//

#include <unistd.h>

#include <iostream>
#include <string>

#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>

/*
** BROUILLON (moche)
**
** Tout va être convertis en OBJ quand cela sera à peu prés fonctionel !
*/

void	moveTop(sf::SocketTCP Client)
{
  char Buffer[] = "Avance\n";
  if (Client.Send(Buffer, sizeof(Buffer)) != sf::Socket::Done)
    {
      std::cout << "Error with Send\n";
    }

  char		Rep[128];
  std::size_t	Received;

  if (Client.Receive(Rep, sizeof(Rep), Received) != sf::Socket::Done)
    {
      std::cout << "Error with receive\n";
    }
  else
    std::cout << "Rep : " << Rep << std::endl;   // mettre la réponse dans un attribut, du coup faire un this->attribut = réponse.
}

void	moveRight(sf::SocketTCP Client)
{
  char Buffer[] = "Droite\n";
  if (Client.Send(Buffer, sizeof(Buffer)) != sf::Socket::Done)
    {
      std::cout << "Error with Send\n";      
    }

  char		Rep[128];
  std::size_t	Received;

  if (Client.Receive(Rep, sizeof(Rep), Received) != sf::Socket::Done)
    {
      std::cout << "Error with receive\n";
    }
  else
    std::cout << "Rep : " << Rep << std::endl;  
}

void	moveLeft(sf::SocketTCP Client)
{
  char Buffer[] = "Gauche\n";
  if (Client.Send(Buffer, sizeof(Buffer)) != sf::Socket::Done)
    {
      std::cout << "Error with Send\n";      
    }

  char		Rep[128];
  std::size_t	Received;

  if (Client.Receive(Rep, sizeof(Rep), Received) != sf::Socket::Done)
    {
      std::cout << "Error with receive\n";
    }
  else
    std::cout << "Rep : " << Rep << std::endl;
}

void	shoot(sf::SocketTCP Client)
{
  char Buffer[] = "Tir\n";
  if (Client.Send(Buffer, sizeof(Buffer)) != sf::Socket::Done)
    {
      std::cout << "Error with Send\n";      
    }

  char		Rep[128];
  std::size_t	Received;

  if (Client.Receive(Rep, sizeof(Rep), Received) != sf::Socket::Done)
    {
      std::cout << "Error with receive\n";
    }
  else
    std::cout << "Rep : " << Rep << std::endl;  
}

void	isDead(sf::SocketTCP Client) //cette fonction doit etre appelé à chaque tour de boucle pour check
{
  char Buffer[] = "Tir\n";
  if (Client.Send(Buffer, sizeof(Buffer)) != sf::Socket::Done)
    {
      std::cout << "Error with Send\n";      
    }

  char		Rep[128];
  std::size_t	Received;

  if (Client.Receive(Rep, sizeof(Rep), Received) != sf::Socket::Done)
    {
      std::cout << "Error with receive\n";
    }
  else
    std::cout << "Rep : " << Rep << std::endl;    
}

int	main(int ac, char **av)
{

  /*
  sf::SocketTCP Client;
  if (Client.Connect(4242, "127.0.0.1") != sf::Socket::Done)
    {
      std::cout << "Error with Connect()\n";
    }

  char Buffer[] = "Avance\n";
  if (Client.Send(Buffer, sizeof(Buffer)) != sf::Socket::Done)
    {
      std::cout << "Error with Send\n";      
    }

  char		Rep[128];
  std::size_t	Received;

  if (Client.Receive(Rep, sizeof(Rep), Received) != sf::Socket::Done)
    {
      std::cout << "Error with receive\n";
    }
  else
    std::cout << "Rep : " << Rep << std::endl;
  */


  sf::RenderWindow	App(sf::VideoMode(800, 800, 32), "SpaceWar");
  sf::Event		event;

  sf::Shape                     head = sf::Shape::Rectangle(10, 10, 41, 25, sf::Color(255, 255, 255));

  bool	running = true;

  //Connexion

  // mettre en obj
  // faire une methode pour la close


  sf::SocketTCP Client;
  if (Client.Connect(4242, "127.0.0.1") != sf::Socket::Done)
    {
      std::cout << "Error with Connect()\n";
    }


  while (running)
    {
      while (App.GetEvent(event))
	{
          if (event.Type == sf::Event::Closed)
	    {
	      App.Close();
	      running = false;
	    }
	  else if (event.Type == sf::Event::KeyPressed && event.Key.Code == sf::Key::Escape)
	    {
	      App.Close();
	      running = false;
	    }
	}

      const sf::Input &input = App.GetInput();

      if (input.IsKeyDown(sf::Key::Up))
	{
	  std::cout << "[SENDING] : Avance\\n" << std::endl;
	  moveTop(Client);
	}
      if (input.IsKeyDown(sf::Key::Right))
	{
	  std::cout << "[SENDING] : Droite\\n" << std::endl;
	  moveRight(Client);
	}
      if (input.IsKeyDown(sf::Key::Left))
	{
	  std::cout << "[SENDING] : Gauche\\n" << std::endl;
	  moveLeft(Client);
	}

      std::cout << "====IS DEAD====" << std::endl;
      isDead(Client);


      App.Clear(sf::Color(0, 0, 0));

      //      head.SetPosition(124, 124); //déplacement du vaisseau

      App.Draw(head);

      App.Display();

      usleep(100000);

    }

  return (0);




}
