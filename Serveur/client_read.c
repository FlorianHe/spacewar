/*
** client_read.c for Spacewar in /home/mizuko/RAT
**
** Made by Augustin Marchand
** Login   <marcha_q@epitech.net>
**
** Started on  Mon Jul 22 15:15:14 2013 Augustin Marchand
** Last update Fri Jul 26 18:38:00 2013 Augustin Marchand
*/

#include		<string.h>
#include		"serveur.h"

void                    client_read(t_serv *e, int fd)
{
  int                   r;
  char                  buff[124];

  memset(buff, '\0', 124);
  r = read(fd, buff, 124);
  printf("%s", buff);
  if (r > 0)
    {
      if (strcmp(buff, "Avance\n") == 0)
	avance(&(e->next), fd);
      else if (strcmp(buff, "Droite\n") == 0)
	droite(&(e->next), fd);
      else if (strcmp(buff, "Gauche\n") == 0)
	gauche(&(e->next), fd);
      else if (strcmp(buff, "Tir\n") == 0)
	tir(&(e->next), fd);
    }
  else
    {
      printf("%d: Connection closed\n", fd);
      graph_close(&(e->next), fd);
      deletenode(&(e->next), fd);
      e->fd_type[fd] = FD_FREE;
      close(fd);
    }
}
