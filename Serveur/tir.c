/*
** tir.c for tir in /home/adil/Teck2/Spacewar
** 
** Made by adil boumahdi
** Login   <boumah_a@epitech.net>
** 
** Started on  Mon Jul 22 13:36:43 2013 adil boumahdi
** Last update Sat Jul 27 18:26:20 2013 Florian Helaine
*/

#include	"serveur.h"

void		*tir(t_player **list, int num_player)
{
  t_player	*tmp;

  tmp = *list;
  while (tmp != NULL)
    {
      if (tmp->player_fd == num_player)
	{
	  if (tmp->nb_missile < 5)
	    {
	      tir2(list, tmp);
	      tmp->nb_missile++;
	    }
	  return (NULL);
	}
      tmp = tmp->next;
    }
}

void		tir2(t_player **list, t_player *player)
{
  static int	i = 1;
  t_missile	*missile;

  missile = xmalloc(sizeof(t_missile));
  missile->rotation = player->rotation;
  missile->x = player->X;
  missile->y = player->Y;
  pop_tir(missile);
  missile->nb_tir = i++;
  graph_tir(list, missile);
  addmissile(&(player->missile), missile);
}

void            addmissile(t_missile **start, t_missile *node)
{
  t_missile      *new;

  new = xmalloc(sizeof(t_missile));
  new->x = node->x;
  new->y = node->y;
  new->rotation = node->rotation;
  new->time = 0;
  new->time_grav = 0;
  new->nb_tir = node->nb_tir;
  new->next = *start;
  *start = new;
}
