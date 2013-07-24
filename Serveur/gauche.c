/*
** gauche.c for gauche in /home/adil/Teck2/Spacewar
** 
** Made by adil boumahdi
** Login   <boumah_a@epitech.net>
** 
** Started on  Fri Jul 19 15:20:54 2013 adil boumahdi
** Last update Wed Jul 24 21:29:24 2013 Florian Helaine
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
	  tmp->rotation = tmp->rotation - 15;
	  if (tmp->rotation < 0)
	    tmp->rotation = 345;
	  graph_gauche(tmp->player_fd, tmp);
	}
      tmp = tmp->next;
    }
}
