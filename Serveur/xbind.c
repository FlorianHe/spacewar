/*
** xbind.c for Spacewar in /home/mizuko/RAT
**
** Made by Augustin Marchand
** Login   <marcha_q@epitech.net>
**
** Started on  Mon Jul 22 14:43:11 2013 Augustin Marchand
** Last update Mon Jul 22 14:46:08 2013 Augustin Marchand
*/

#include                        <netdb.h>
#include                        <stdlib.h>

void				xbind(int fd)
{
  struct sockaddr_in		sin;

  sin.sin_family = AF_INET;
  sin.sin_port = htons(4242);
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