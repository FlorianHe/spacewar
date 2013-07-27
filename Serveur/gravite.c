/*
** gravite.c for spacewar in /home/helain_f/Semestre_3/spacewar
** 
** Made by Florian Helaine
** Login   <helain_f@epitech.net>
** 
** Started on  Wed Jul 24 18:33:48 2013 Florian Helaine
** Last update Sat Jul 27 18:27:54 2013 Florian Helaine
*/

#include	"serveur.h"

void		gravite(t_player **list)
{
  t_player	*tmp;

  tmp = *list;
  while (tmp != NULL)
    {
      if (tmp->player_fd != 0)
	{
	  applique_gravite(list, tmp);
	  move_tir(list, tmp);
	}
      tmp = tmp->next;
    }
}
