/*
** xsocket.c for Spacewar in /home/mizuko/RAT
**
** Made by Augustin Marchand
** Login   <marcha_q@epitech.net>
**
** Started on  Mon Jul 22 14:33:44 2013 Augustin Marchand
** Last update Mon Jul 22 14:37:57 2013 Augustin Marchand
*/

#include			<netdb.h>
#include			<stdlib.h>
#include			<sys/types.h>
#include			<sys/socket.h>

int				xsocket()
{
  int				fd;
  struct protoent		*pe;

  pe = getprotobyname("TCP");
  if (!pe)
    exit(EXIT_FAILURE);
  if ((fd = socket(AF_INET, SOCK_STREAM, pe->p_proto)) == -1)
    error("SOCKET ERROR\n");
  write(1, "SOCKET SUCCESS\n", 15);
  return (fd);
}
