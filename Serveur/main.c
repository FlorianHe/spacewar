/*
** main.c for spacewar in /home/mizuko/RAT
**
** Made by Augustin Marchand
** Login   <marcha_q@epitech.net>
**
** Started on  Mon Jul 22 14:03:18 2013 Augustin Marchand
** Last update Tue Jul 23 13:35:02 2013 adil boumahdi
*/

#include			<string.h>
#include			<stdlib.h>
#include			"serveur.h"

int				main(int ac, char *av[])
{
  t_serv			serv;
  int				i;

  i = 1;
  serv.game = 5;
  serv.player = 2;
  while(i != ac)
    {
      if (strcmp(av[i], "-p") == 0 && serv.player == 2 && i + 1 < ac)
	serv.player = atoi(av[i + 1]);
      else if (strcmp(av[i], "-g") == 0 && serv.game == 5 && i + 1 < ac)
	serv.game = atoi(av[i + 1]);
      else
	error("Usage: ./Spacewar [-p player_number -g game_number]\n");
      i = i + 2;
    }
  if (serv.player < 2 || serv.player > 10)
    error("Value must be between 2 and 10\n");
  if (serv.game < 5 || serv.game > 10)
    error("Value must be between 5 and 10\n");
  memset(serv.fd_type, FD_FREE, MAX_FD);
  serveur(&serv);
  while (1)
    run(&serv);
}
