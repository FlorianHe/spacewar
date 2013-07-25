/*
** droite.c for droite in /home/adil/Teck2/Spacewar
** 
** Made by adil boumahdi
** Login   <boumah_a@epitech.net>
** 
** Started on  Fri Jul 19 15:20:31 2013 adil boumahdi
** Last update Thu Jul 25 13:54:21 2013 adil boumahdi
*/

#include	"spacewar.h"

void            droite(t_player **list, int num_player)
{
  t_player	*tmp;

  tmp = *list;
  while (tmp != NULL)
    {
      if (tmp->player_fd == num_player)
	{
	  tmp->rotation = tmp->rotation + 45;
	  if (tmp->rotation >= 360)
	    tmp->rotation = 0;
	  graph_droite(tmp->player_fd, tmp);
	}
      tmp = tmp->next;
    }
}
