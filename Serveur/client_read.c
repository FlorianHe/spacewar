/*
** client_read.c for Spacewar in /home/mizuko/RAT
**
** Made by Augustin Marchand
** Login   <marcha_q@epitech.net>
**
** Started on  Mon Jul 22 15:15:14 2013 Augustin Marchand
** Last update Tue Jul 23 16:40:32 2013 adil boumahdi
*/

#include		<string.h>
#include		"serveur.h"

void                    client_read(t_serv *e, int fd)
{
  int                   r;
  char                  buff[1024];

  memset(buff, '\0', 1024);
  r = read(fd, buff, 1024);
  if (r > 0)
    {
      if (strcmp(buff, "Avance\n") == 0)
        ;
      else if (strcmp(buff, "Droite\n") == 0)
	;
      else if (strcmp(buff, "Gauche\n") == 0)
        ;
      else if (strcmp(buff, "Tir\n") == 0)
	;
    }
  else
    {
      printf("%d: Connection closed\n", fd);
      e->fd_type[fd] = FD_FREE;
      close(fd);
    }
}
