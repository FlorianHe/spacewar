/*
** serveur.c for Spacewar in /home/mizuko/RAT
**
** Made by Augustin Marchand
** Login   <marcha_q@epitech.net>
**
** Started on  Mon Jul 22 14:38:09 2013 Augustin Marchand
** Last update Fri Jul 26 18:28:41 2013 Augustin Marchand
*/

#include			"serveur.h"

int				serveur(t_serv *e)
{
  int				fd;

  fd = xsocket();
  xbind(fd, e);
  xlisten(fd);
  e->fd_type[fd] = FD_SERVEUR;
  e->fct_read[fd] = serveur_read;
}
