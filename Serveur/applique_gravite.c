/*
** applique_gravite.c for spacewar in /home/helain_f/Semestre_3/spacewar
** 
** Made by Florian Helaine
** Login   <helain_f@epitech.net>
** 
** Started on  Fri Jul 26 10:23:07 2013 Florian Helaine
** Last update Fri Jul 26 10:23:22 2013 Florian Helaine
*/

#include	"serveur.h"

void		gravite_top_left(t_player **list, t_player *pl)
{
  pl->X += 1;
  pl->Y += 1;
  graph_avance(list, pl);
}

void		gravite_top_right(t_player **list, t_player *pl)
{
  pl->X -= 1;
  pl->Y += 1;
  graph_avance(list, pl);
}

void		gravite_bot_left(t_player **list, t_player *pl)
{
  pl->X += 1;
  pl->Y -= 1;
  graph_avance(list, pl);
}

void		gravite_bot_right(t_player **list, t_player *pl)
{
  pl->X -= 1;
  pl->Y -= 1;
  graph_avance(list, pl);
}

void		applique_gravite(t_player **list, t_player *pl)
{
  if (pl->time >= 10000)
    {
      if (pl->X >= 0 && pl->X <= 400 && pl->Y >= 0 && pl->Y <= 400)
	gravite_top_left(list, pl);
      else if (pl->X >= 400 && pl->X <= 800 && pl->Y <= 800 && pl->Y >= 400)
	gravite_bot_right(list, pl);
      else if (pl->X >= 0 && pl->X <= 400 && pl->Y <= 800 && pl->Y >= 400)
	gravite_bot_left(list, pl);
      else if (pl->X >= 400 && pl->X <= 800 && pl->Y <= 400 && pl->Y >= 0)
	gravite_top_right(list, pl);
      pl->time = 0;
    }
  else
    pl->time++;
}
