/*
** serveur_read.c for Spacewar in /home/mizuko/RAT
**
** Made by Augustin Marchand
** Login   <marcha_q@epitech.net>
**
** Started on  Mon Jul 22 14:59:45 2013 Augustin Marchand
** Last update Mon Jul 22 15:00:21 2013 Augustin Marchand
*/

#include			"serveur.h"

void				serveur_read(t_serv *e, int fd)
{
  add_client(e, fd);
}
