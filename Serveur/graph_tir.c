/*
** graph_tir.c for spacewar in /home/helain_f/Semestre_3/spacewar/Serveur
** 
** Made by Florian Helaine
** Login   <helain_f@epitech.net>
** 
** Started on  Thu Jul 25 14:21:17 2013 Florian Helaine
** Last update Sun Jul 28 13:56:20 2013 Florian Helaine
*/

#include	"serveur.h"

void		graph_tir(t_player **list, t_missile *tir)
{
  t_player	*tmp;
  char		buff[254];

  tmp = *list;
  memset(buff, '\0', 254);
  sprintf(buff, "Tir %d %d %d\n", tir->nb_tir, tir->x, tir->y);
  while (tmp != NULL)
    {
      if (tmp->player_fd != 0)
	{
	  write(1, buff, strlen(buff));
	  write(tmp->player_fd, buff, strlen(buff));
	}
      tmp = tmp->next;
    }
}

void		graph_tir_suppr(t_player **list, t_missile *tir)
{
  t_player	*tmp;
  char		buff[254];

  tmp = *list;
  memset(buff, '\0', 254);
  sprintf(buff, "MoT %d\n", tir->nb_tir);
  while (tmp != NULL)
    {
      if (tmp->player_fd != 0)
	{
	  write(1, buff, strlen(buff));
	  write(tmp->player_fd, buff, strlen(buff));
	}
      tmp = tmp->next;
    }
}
