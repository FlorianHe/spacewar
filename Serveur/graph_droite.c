/*
** graph_droite.c for spacewar in /home/helain_f/Semestre_3/spacewar/Serveur
** 
** Made by Florian Helaine
** Login   <helain_f@epitech.net>
** 
** Started on  Wed Jul 24 21:08:03 2013 Florian Helaine
** Last update Thu Jul 25 14:08:29 2013 Florian Helaine
*/

#include	"serveur.h"

void		graph_droite(t_player **list, t_player *perso)
{
  t_player	*tmp;
  char		buff[254];

  tmp = *list;
  memset(buff, '\0', 254);
  sprintf(buff, "Dro %d %d\n", perso->player_id, perso->rotation);
  while (tmp != NULL)
    {
      write(1, buff, strlen(buff));
      write(tmp->player_fd, buff, strlen(buff));
      tmp = tmp->next;
    }
}
