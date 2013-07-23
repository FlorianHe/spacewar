/*
** main.c for spacewar in /home/mizuko/RAT
**
** Made by Augustin Marchand
** Login   <marcha_q@epitech.net>
**
** Started on  Mon Jul 22 14:03:18 2013 Augustin Marchand
** Last update Mon Jul 22 15:04:49 2013 Augustin Marchand
*/

#include			<string.h>
#include			<stdlib.h>
#include			"serveur.h"

int				main(int ac, char *av[])
{
  t_serv			e;
  int				i;

  e.player = 2;
  e.game = 5;
  i = 1;
  while(i != ac)
    {
      if (strcmp(av[i], "-p") == 0 && e.player == 2 && i + 1 < ac)
	e.player = atoi(av[i + 1]);
      else if (strcmp(av[i], "-g") == 0 && e.game == 5 && i + 1 < ac)
	e.game = atoi(av[i + 1]);
      else
	error("Usage: ./Spacewar [-p player_number -g game_number]\n");
      i = i + 2;
    }
  if (e.player < 2 || e.player > 10)
    error("Value must be between 2 and 10\n");
  if (e.game < 5 || e.game > 10)
    error("Value must be between 5 and 10\n");
  memset(e.fd_type, FD_FREE, MAX_FD);
  serveur(&e);
  while (1)
    run(&e);
}
