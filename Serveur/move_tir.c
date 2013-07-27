/*
** move_tir.c for spacewar in /home/helain_f/Semestre_3/spacewar
** 
** Made by Florian Helaine
** Login   <helain_f@epitech.net>
** 
** Started on  Fri Jul 26 14:10:07 2013 Florian Helaine
** Last update Sat Jul 27 18:28:25 2013 Florian Helaine
*/

#include	"serveur.h"

static	t_rotation_tir	tab_value_tir[8] =
  {
    {0, Zero_tir},
    {45, Forty_five_tir},
    {90, Ninety_tir},
    {135, Hundred_thirty_five_tir},
    {180, Hundred_eighty_tir},
    {225, Hundred_twenty_five_tir},
    {270, Hundred_seventy_tir},
    {315, Hundred_fifteen_tir}
  };

void		move_tir(t_player **list, t_player *pl)
{
  static int	i = 0;
  int		j;
  t_missile	*tmp2;

  tmp2 = pl->missile;
  while (tmp2 != NULL)
    {
      j = 0;
      while (j < 8 && tmp2->rotation != tab_value_tir[j].rotation_)
	j++;
      if (j != 8 && tmp2->time >= 3500 && tmp2->nb_tir != 0)
	{
	  tab_value_tir[j].funct(tmp2, 1);
	  gravite_tir(list, tmp2);
	  collide_tir(list, pl, tmp2);
	  graph_tir(list, tmp2);
	  tmp2->time = 0;
	}
      else
	tmp2->time++;
      tmp2 = tmp2->next;
    }
}

void		pop_tir(t_missile *tir)
{
  int		j;

  j = 0;
  while (j < 8 && tir->rotation != tab_value_tir[j].rotation_)
    j++;
  if (j != 8)
    tab_value_tir[j].funct(tir, 30);
}
