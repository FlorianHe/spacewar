/*
** gravite.c for spacewar in /home/helain_f/Semestre_3/spacewar
** 
** Made by Florian Helaine
** Login   <helain_f@epitech.net>
** 
** Started on  Wed Jul 24 18:33:48 2013 Florian Helaine
** Last update Wed Jul 24 22:24:07 2013 Florian Helaine
*/

#include	"serveur.h"

void		applique_gravite(t_player *pl)
{
  if (pl->X <= 550 && pl->X >= 250 && pl->Y <= 550 && pl->X >= 250)
    gravite_high(pl);
  else if (pl->X <= 700 && pl->X >= 100 && pl->Y <= 700 && pl->X >= 100)
    gravite_low(pl);
}

void		gravite(t_player **list)
{
  t_player	*tmp;

  tmp = *list;
  while (tmp != NULL)
    {
      applique_gravite(tmp);
      tmp = tmp->next;
    }
}
