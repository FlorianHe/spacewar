/*
** graph_gauche.c for spacewar in /home/helain_f/Semestre_3/spacewar/Serveur
** 
** Made by Florian Helaine
** Login   <helain_f@epitech.net>
** 
** Started on  Wed Jul 24 21:12:13 2013 Florian Helaine
** Last update Fri Jul 26 10:18:28 2013 Florian Helaine
*/

#include	"serveur.h"

void		graph_gauche(t_player **list, t_player *perso)
{
  t_player	*tmp;
  char		buff[254];

  tmp = *list;
  memset(buff, '\0', 254);
  sprintf(buff, "Gau %d %d\n", perso->player_id, perso->rotation);
  while (tmp != NULL)
    {
      write(1, buff, strlen(buff));
      if (tmp->player_fd != 0)
	write(tmp->player_fd, buff, strlen(buff));
      tmp = tmp->next;
    }
}
