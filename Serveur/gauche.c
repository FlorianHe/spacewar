/*
** gauche.c for gauche in /home/adil/Teck2/Spacewar
** 
** Made by adil boumahdi
** Login   <boumah_a@epitech.net>
** 
** Started on  Fri Jul 19 15:20:54 2013 adil boumahdi
** Last update Thu Jul 25 15:31:15 2013 Florian Helaine
*/

#include	"spacewar.h"

void		gauche(t_player **list, int num_player)
{
  t_player	*tmp;

  tmp = *list;
  while (tmp != NULL)
    {
      if (tmp->player_fd == num_player)
	{
	  tmp->rotation = tmp->rotation - 45;
	  if (tmp->rotation < 0)
	    tmp->rotation = 315;
	  graph_gauche(list, tmp);
	}
      tmp = tmp->next;
    }
}
