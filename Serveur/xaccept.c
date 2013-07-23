/*
** xaccept.c for Spacewar in /home/mizuko/RAT
**
** Made by Augustin Marchand
** Login   <marcha_q@epitech.net>
**
** Started on  Mon Jul 22 15:02:37 2013 Augustin Marchand
** Last update Mon Jul 22 15:03:52 2013 Augustin Marchand
*/

#include                        <netdb.h>
#include                        <stdlib.h>

int                             xaccept(int fd)
{
  struct sockaddr_in            sin;
  int                           sin_size;
  int                           client;

  sin_size = sizeof(sin);
  client = accept(fd, (struct sockaddr *)&sin, (socklen_t *)&sin_size);
  if (fd == -1)
    {
      write(2, "ACCEPT ERROR\n", 13);
      if (close(fd) == -1)
	{
	  write (2, "ERROR: close\n", 13);
	  exit(EXIT_SUCCESS);
	}
      exit(EXIT_FAILURE);
    }
  write(1, "NEW CONNECTION SUCCESS\n", 23);
  return (client);
}
