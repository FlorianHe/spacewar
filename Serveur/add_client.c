/*
** add_client.c for Spacewar in /home/mizuko/RAT
**
** Made by Augustin Marchand
** Login   <marcha_q@epitech.net>
**
** Started on  Mon Jul 22 15:01:38 2013 Augustin Marchand
** Last update Mon Jul 22 15:12:59 2013 Augustin Marchand
*/

#include			"serveur.h"

void				add_client(t_serv *e, int fd)
{
  int				client;

  client = xaccept(fd);
  e->fd_type[client] = FD_CLIENT;
  e->fct_read[client] = client_read;
}
