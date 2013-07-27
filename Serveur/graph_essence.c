/*
** graph_essence.c for spacewar in /home/helain_f/Semestre_3/spacewar
** 
** Made by Florian Helaine
** Login   <helain_f@epitech.net>
** 
** Started on  Fri Jul 26 16:42:18 2013 Florian Helaine
** Last update Sat Jul 27 17:55:17 2013 Florian Helaine
*/

#include	"serveur.h"

void		graph_essence(t_player **list, t_player *perso)
{
  t_player	*tmp;
  char		buff[254];

  tmp = *list;
  memset(buff, '\0', 254);
  sprintf(buff, "Ess %d %d\n", perso->player_id, perso->essence);
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
