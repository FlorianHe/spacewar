/*
** client_read.c for Spacewar in /home/mizuko/RAT
**
** Made by Augustin Marchand
** Login   <marcha_q@epitech.net>
**
** Started on  Mon Jul 22 15:15:14 2013 Augustin Marchand
** Last update Sun Jul 28 20:51:20 2013 Florian Helaine
*/

#include		<string.h>
#include		"serveur.h"

void			connection_close(t_serv *serv, int fd)
{
  printf("%d: Connection closed\n", fd);
  graph_close(&(serv->next), fd);
  deletenode(&(serv->next), fd);
  serv->fd_type[fd] = FD_FREE;
  close(fd);
}

void			exec_cmd(t_serv *serv, int fd, char *buff)
{
  if (strcmp(buff, "Avance\n") == 0)
    avance(&(serv->next), fd);
  else if (strcmp(buff, "Droite\n") == 0)
    droite(&(serv->next), fd);
  else if (strcmp(buff, "Gauche\n") == 0)
    gauche(&(serv->next), fd);
  else if (strcmp(buff, "Tir\n") == 0)
    tir(&(serv->next), fd);
}

void                    client_read(t_serv *e, int fd)
{
  int                   r;
  char                  tmp[2];
  char			*buff;

  asprintf(&buff, "");
  while (strcmp(tmp, "\n") != 0)
    {
      memset(tmp, '\0', 2);
      r = read(fd, tmp, 1);
      if (r <= 0)
	{
	  connection_close(e, fd);
	  sprintf(tmp, "\n");
	}
      asprintf(&buff, "%s%s", buff, tmp);
    }
  if (r > 0)
    exec_cmd(e, fd, buff);
  free(buff);
}
