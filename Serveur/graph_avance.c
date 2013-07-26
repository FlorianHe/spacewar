/*
** graph_avance.c for spacewar in /home/helain_f/Semestre_3/spacewar
** 
** Made by Florian Helaine
** Login   <helain_f@epitech.net>
** 
** Started on  Wed Jul 24 18:40:32 2013 Florian Helaine
** Last update Fri Jul 26 10:18:18 2013 Florian Helaine
*/

#include	"serveur.h"

void		graph_avance(t_player **list, t_player *perso)
{
  t_player	*tmp;
  char		buff[254];

  tmp = *list;
  memset(buff, '\0', 254);
  sprintf(buff, "Ava %d %d %d\n", perso->player_id, perso->X, perso->Y);
  while (tmp != NULL)
    {
      write(1, buff, strlen(buff));
      if (tmp->player_fd != 0)
	write(tmp->player_fd, buff, strlen(buff));
      tmp = tmp->next;
    }
}
