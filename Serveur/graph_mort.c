/*
** graph_mort.c for spacewar in /home/helain_f/Semestre_3/spacewar
** 
** Made by Florian Helaine
** Login   <helain_f@epitech.net>
** 
** Started on  Fri Jul 26 10:25:06 2013 Florian Helaine
** Last update Fri Jul 26 14:55:06 2013 Florian Helaine
*/

#include	"serveur.h"

void		graph_mort(t_player **list, t_player *pl)
{
  t_player	*tmp;
  char		buff[254];

  tmp = *list;
  memset(buff, '\0', 254);
  sprintf(buff, "Mor %d\n", pl->player_id);
  while (tmp != NULL)
    {
      if (tmp->player_fd != 0)
	write(tmp->player_fd, buff, strlen(buff));
      tmp = tmp->next;
    }
  printf("Le joueur %d est mort\n", pl->player_id);
}

void		graph_close(t_player **list, int fd)
{
  int		id;
  char		buff[254];
  t_player	*tmp;

  tmp = *list;
  while (tmp != NULL)
    {
      if (tmp->player_fd == fd)
	id = tmp->player_id;
      tmp = tmp->next;
    }
  memset(buff, '\0', 254);
  sprintf(buff, "Mor %d\n", id);
  tmp = *list;
  while (tmp != NULL)
    {
      if (tmp->player_fd != 0)
	write(tmp->player_fd, buff, strlen(buff));
      tmp = tmp->next;
    }
  printf("Le joueur %d s'est suicidé\n", id);
}
