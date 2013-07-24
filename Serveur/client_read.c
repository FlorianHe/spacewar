/*
** client_read.c for Spacewar in /home/mizuko/RAT
**
** Made by Augustin Marchand
** Login   <marcha_q@epitech.net>
**
** Started on  Mon Jul 22 15:15:14 2013 Augustin Marchand
** Last update Wed Jul 24 11:58:38 2013 Florian Helaine
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
        write(fd, "Ava 1 124 124\n", strlen("Ava 1 124 124\n"));
      else if (strcmp(buff, "Droite\n") == 0)
	write(fd, "Dro 1 40\n", strlen("Dro 1 40\n"));
      else if (strcmp(buff, "Gauche\n") == 0)
	write(fd, "Gau 1 310\n", strlen("Gau 1 310\n"));
      else if (strcmp(buff, "Tir\n") == 0)
	write(fd, "Tir 150 150\n", strlen("Tir 150 150\n"));
    }
  else
    {
      printf("%d: Connection closed\n", fd);
      e->fd_type[fd] = FD_FREE;
      close(fd);
    }
}
