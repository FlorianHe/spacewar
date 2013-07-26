/*
** checking.c for Spacewar in /home/mizuko/RAT/Spacewar/spacewar/Serveur
**
** Made by Augustin Marchand
** Login   <marcha_q@epitech.net>
**
** Started on  Fri Jul 26 18:22:45 2013 Augustin Marchand
** Last update Fri Jul 26 18:30:41 2013 Augustin Marchand
*/

#include			"serveur.h"

void				checking(t_serv *e, int ac, char *av[])
{
  int				i;

  i = 1;
  while(i != ac)
    {
      if (strcmp(av[i], "-n") == 0 && e->player == 2 && i + 1 < ac)
        e->player = atoi(av[i + 1]);
      else if (strcmp(av[i], "-g") == 0 && e->game == 5 && i + 1 < ac)
        e->game = atoi(av[i + 1]);
      else if (strcmp(av[i], "-p") == 0 && e->port == 4242 && i + 1 < ac)
        e->port = atoi(av[i + 1]);
      else
        error("Usage: ./Spacewar [-n player_number -g game_number -p port]\n");
      i = i + 2;
    }
}
