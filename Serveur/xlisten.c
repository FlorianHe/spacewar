/*
** xlisten.c for Spacewar in /home/mizuko/RAT
**
** Made by Augustin Marchand
** Login   <marcha_q@epitech.net>
**
** Started on  Mon Jul 22 14:46:55 2013 Augustin Marchand
** Last update Mon Jul 22 14:47:59 2013 Augustin Marchand
*/

#include                        <netdb.h>
#include                        <stdlib.h>
//#include                        <unistd.h>
//#include                        <sys/types.h>
//#include                        <sys/socket.h>

void				xlisten(int fd)
{
  if (listen(fd, 20) == -1)
    {
      write(2, "LISTEN ERROR\n", 13);
      if (close(fd) == -1)
	{
	  write (2, "ERROR: close\n", 13);
	  exit(EXIT_SUCCESS);
	}
      exit(EXIT_FAILURE);
    }
  write(1, "LISTEN SUCCESS\n", 15);
}
