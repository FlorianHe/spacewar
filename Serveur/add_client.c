/*
** add_client.c for Spacewar in /home/mizuko/RAT
**
** Made by Augustin Marchand
** Login   <marcha_q@epitech.net>
**
** Started on  Mon Jul 22 15:01:38 2013 Augustin Marchand
** Last update Fri Jul 26 10:30:28 2013 Florian Helaine
*/

#include			"serveur.h"

void				init_player(t_serv *serv, int fd)
{
  char				buff[254];
  t_player			new;
  t_player			*tmp;

  new.X = rand() % 800;
  new.Y = rand() % 800;
  if (new.X <= 500 && new.X >= 300)
    new.X = rand() % 300;
  if (new.Y <= 500 && new.Y >= 300)
    new.X = rand() % 300;
  new.player_id = serv->id_player++;
  new.player_fd = fd;
  new.missile = NULL;
  addnode(&(serv->next), &new);
  memset(buff, '\0', 254);
  sprintf(buff, "New %d %d %d 0\n", new.player_id, new.X,
	  new.Y);
  tmp = serv->next;
  while (tmp != NULL)
    {
      write(1, buff, strlen(buff));
      if (tmp->player_fd != 0)
	write(tmp->player_fd, buff, strlen(buff));
      tmp = tmp->next;
    }
}

void				add_player(t_serv *serv, int fd)
{
  t_player			*tmp;
  char				buff[254];

  init_player(serv, fd);
  tmp = serv->next;
  while (tmp != NULL)
    {
      if (tmp->player_fd != 0 && tmp->player_fd != fd)
	{
	  memset(buff, '\0', 254);
	  sprintf(buff, "New %d %d %d %d\n", tmp->player_id, tmp->X,
		  tmp->Y, tmp->rotation);
	  write(1, buff, strlen(buff));
	  write(fd, buff, strlen(buff));
	}
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
