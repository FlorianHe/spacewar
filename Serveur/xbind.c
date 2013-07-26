/*
** xbind.c for Spacewar in /home/mizuko/RAT
**
** Made by Augustin Marchand
** Login   <marcha_q@epitech.net>
**
** Started on  Mon Jul 22 14:43:11 2013 Augustin Marchand
** Last update Fri Jul 26 18:28:33 2013 Augustin Marchand
*/

#include                        <netdb.h>
#include                        <stdlib.h>
#include			"serveur.h"

void				xbind(int fd, t_serv *e)
{
  struct sockaddr_in		sin;

  sin.sin_family = AF_INET;
  sin.sin_port = htons(e->port);
  sin.sin_addr.s_addr = INADDR_ANY;
  if (bind(fd, (const struct sockaddr *)&sin, sizeof(sin)) == -1)
    {
      write(2, "BIND ERROR\n", 11);
      if (close(fd) == -1)
	{
          write (2, "ERROR: close\n", 13);
          exit(EXIT_SUCCESS);
        }
      exit(EXIT_FAILURE);
    }
  write(1, "BIND SUCCESS\n", 13);
}
