/*
** mort.c for spacewar in /home/helain_f/Semestre_3/spacewar
** 
** Made by Florian Helaine
** Login   <helain_f@epitech.net>
** 
** Started on  Fri Jul 26 10:24:17 2013 Florian Helaine
** Last update Sun Jul 28 20:53:20 2013 Florian Helaine
*/

#include	"serveur.h"

void		is_dead(t_player **list, t_player *pl, t_serv *serv)
{
  int		fd;

  fd = pl->player_fd;
  graph_mort(list, pl);
  deletenode(list, pl->player_fd);
  serv->fd_type[fd] = FD_FREE;
  close(fd);
}

void		applique_mort(t_player **list, t_player *pl, t_serv *serv)
{
  if (pl->X - 20 >= 385 && pl->X - 20 <= 415)
    is_dead(list, pl, serv);
  else if (pl->X + 20 >= 385 && pl->X + 20 <= 415)
    is_dead(list, pl, serv);
  else if (pl->Y - 20 >= 385 && pl->Y - 20 <= 415)
    is_dead(list, pl, serv);
  else if (pl->Y + 20 >= 385 && pl->Y + 20 <= 415)
    is_dead(list, pl, serv);
}

void		mort(t_player **list, t_serv *serv)
{
  t_player	*tmp;

  tmp = *list;
  while (tmp != NULL)
    {
      if (tmp->player_fd != 0)
	applique_mort(list, tmp, serv);
      tmp = tmp->next;
    }
}
