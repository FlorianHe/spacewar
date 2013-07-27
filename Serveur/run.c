/*
** run.c for Spacewar in /home/mizuko/RAT
**
** Made by Augustin Marchand
** Login   <marcha_q@epitech.net>
**
** Started on  Mon Jul 22 15:04:56 2013 Augustin Marchand
** Last update Sat Jul 27 18:01:16 2013 Florian Helaine
*/

#include                <sys/time.h>
#include                <stdio.h>
#include                "serveur.h"

void                    run(t_serv *e)
{
  int                   i;
  int                   fd_max;
  fd_set                fd_read;
  struct timeval	tv;

  i = 0;
  tv.tv_sec = 0;
  tv.tv_usec = 100000;
  FD_ZERO(&fd_read);
  fd_max = setType(e, &fd_read);
  if (select(fd_max + 1, &fd_read, NULL, NULL, &tv) == -1)
    perror("select");
  while (i < MAX_FD)
    {
      if (FD_ISSET(i, &fd_read))
        e->fct_read[i](e, i);
      gravite(&(e->next));
      mort(&(e->next), e);
      i++;
    }
}
