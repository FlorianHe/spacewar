/*
** add_client.c for Spacewar in /home/mizuko/RAT
**
** Made by Augustin Marchand
** Login   <marcha_q@epitech.net>
**
** Started on  Mon Jul 22 15:01:38 2013 Augustin Marchand
** Last update Thu Jul 25 15:09:20 2013 Florian Helaine
*/

#include			"serveur.h"

void				add_player(t_serv *serv, int fd)
{
  t_player			new;
  t_player			*tmp;
  char				buff[254];

  new.X = rand() % 800;
  new.Y = rand() % 800;
  if (new.X <= 465 && new.X >= 435)
    new.X = rand() % 400;
  if (new.Y <= 465 && new.Y >= 435)
    new.X = rand() % 400;
  new.essence = 80;
  new.rotation = 0;
  new.player_id = serv->id_player++;
  new.player_fd = fd;
  new.nb_missile = 0;
  new.missile = NULL;
  addnode(&(serv->next), &new);
  memset(buff, '\0', 254);
  sprintf(buff, "New %d %d %d %d\n", new.player_id, new.X, new.Y, new.rotation);
  tmp = serv->next;
  while (tmp != NULL)
    {
      write(1, buff, strlen(buff));
      write(tmp->player_fd, buff, strlen(buff));
      tmp = tmp->next;
    }
}

void				add_client(t_serv *e, int fd)
{
  int				client;

  client = xaccept(fd);
  e->fd_type[client] = FD_CLIENT;
  e->fct_read[client] = client_read;
  add_player(e, client);
}
