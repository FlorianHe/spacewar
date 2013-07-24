/*
** add_client.c for Spacewar in /home/mizuko/RAT
**
** Made by Augustin Marchand
** Login   <marcha_q@epitech.net>
**
** Started on  Mon Jul 22 15:01:38 2013 Augustin Marchand
** Last update Wed Jul 24 20:55:30 2013 Florian Helaine
*/

#include			"serveur.h"

void				add_player(t_serv *serv, int fd)
{
  t_player			new;

  new.X = rand() % 800;
  new.Y = rand() % 800;
  new.essence = 80;
  new.rotation = 0;
  new.player_id = serv->id_player++;
  new.player_fd = fd;
  addnode(&(serv->next), &new);
}

void				add_client(t_serv *e, int fd)
{
  int				client;

  client = xaccept(fd);
  e->fd_type[client] = FD_CLIENT;
  e->fct_read[client] = client_read;
  add_player(e, client);
}
