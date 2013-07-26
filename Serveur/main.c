/*
** main.c for spacewar in /home/mizuko/RAT
**
** Made by Augustin Marchand
** Login   <marcha_q@epitech.net>
**
** Started on  Mon Jul 22 14:03:18 2013 Augustin Marchand
** Last update Fri Jul 26 18:30:02 2013 Augustin Marchand
*/

#include			<string.h>
#include			<stdlib.h>
#include			"serveur.h"

int				main(int ac, char **av)
{
  t_serv			serv;

  serv.game = 5;
  serv.player = 2;
  serv.port = 4242;
  serv.next = NULL;
  serv.id_player = 1;
  srand (time(NULL));
  checking(&serv, ac, av);
  if (serv.player < 2 || serv.player > 10)
    error("Value must be between 2 and 10\n");
  if (serv.game < 5 || serv.game > 10)
    error("Value must be between 5 and 10\n");
  memset(serv.fd_type, FD_FREE, MAX_FD);
  serveur(&serv);
  while (1)
    run(&serv);
}
