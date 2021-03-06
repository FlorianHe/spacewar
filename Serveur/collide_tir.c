/*
** collide_tir.c for spacewar in /home/helain_f/Semestre_3/spacewar
** 
** Made by Florian Helaine
** Login   <helain_f@epitech.net>
** 
** Started on  Sat Jul 27 17:28:06 2013 Florian Helaine
** Last update Sun Jul 28 13:55:22 2013 Florian Helaine
*/

#include	"serveur.h"

void		deletemissile(t_player **l, t_player *pl, t_missile *tir)
{
  graph_tir_suppr(l, tir);
  tir->nb_tir = 0;
  pl->nb_missile--;
}

void		collide_vaisseau(t_player **list, t_missile *tir)
{
  t_player	*tmp;

  tmp = *list;
  while (tmp != NULL)
    {
      if ((tir->x >= tmp->X - 20 && tir->x <= tmp->X + 20)
	  && (tir->y >= tmp->Y - 20 && tir->y <= tmp->Y + 20))
	is_dead(list, tmp);
      tmp = tmp->next;
    }
}

void		collide_tir(t_player **list, t_player *pl, t_missile *tir)
{
  collide_vaisseau(list, tir);
  if (tir->x < 0 || tir->x > 800 || tir->y < 0 || tir->y > 800)
    deletemissile(list, pl, tir);
  else if (tir->x >= 385 && tir->x <= 415)
    deletemissile(list, pl, tir);
  else if (tir->y >= 385 && tir->y <= 415)
    deletemissile(list, pl, tir);
}
