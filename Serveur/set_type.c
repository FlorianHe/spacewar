/*
** set_type.c for Spacewar in /home/mizuko/RAT
**
** Made by Augustin Marchand
** Login   <marcha_q@epitech.net>
**
** Started on  Mon Jul 22 15:07:47 2013 Augustin Marchand
** Last update Mon Jul 22 15:09:10 2013 Augustin Marchand
*/

#include		<sys/time.h>
#include		<sys/types.h>
#include		<unistd.h>
#include		"serveur.h"

int                     setType(t_serv *e, fd_set *fd_read)
{
  int                   i;
  int                   fd_max;

  i = 0;
  fd_max = 0;
  while (i < MAX_FD)
    {
      if (e->fd_type[i] != FD_FREE)
        {
          FD_SET(i, fd_read);
          fd_max = i;
        }
      i++;
    }
  return (i);
}
