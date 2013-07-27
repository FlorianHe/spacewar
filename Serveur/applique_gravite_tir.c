/*
** applique_gravite_tir.c for spacewar in /home/helain_f/Semestre_3/spacewar
** 
** Made by Florian Helaine
** Login   <helain_f@epitech.net>
** 
** Started on  Sat Jul 27 18:21:45 2013 Florian Helaine
** Last update Sat Jul 27 18:51:27 2013 adil boumahdi
*/

#include	"serveur.h"

void		gravite_top_left_tir(t_player **list, t_missile *tir)
{
  tir->x += 1;
  tir->y += 1;
  graph_tir(list, tir);
}

void		gravite_top_right_tir(t_player **list, t_missile *tir)
{
  tir->x -= 1;
  tir->y += 1;
  graph_tir(list, tir);
}

void		gravite_bot_left_tir(t_player **list, t_missile *tir)
{
  tir->x += 1;
  tir->y -= 1;
  graph_tir(list, tir);
}

void		gravite_bot_right_tir(t_player **list, t_missile *tir)
{
  tir->x -= 1;
  tir->y -= 1;
  graph_tir(list, tir);
}

void		gravite_tir(t_player **list, t_missile *tir)
{
  if (tir->time_grav >= 3)
    {
      if (tir->x >= 0 && tir->x <= 400 && tir->y >= 0 && tir->y <= 400)
	gravite_top_left_tir(list, tir);
      else if (tir->x >= 400 && tir->x <= 800 && tir->y <= 800 &&
	       tir->y >= 400)
	gravite_bot_right_tir(list, tir);
      else if (tir->x >= 0 && tir->x <= 400 && tir->y <= 800 && tir->y >= 400)
	gravite_bot_left_tir(list, tir);
      else if (tir->x >= 400 && tir->x <= 800 && tir->y <= 400 && tir->y >= 0)
	gravite_top_right_tir(list, tir);
      tir->time_grav = 0;
    }
  else
    tir->time_grav++;
}
