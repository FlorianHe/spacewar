/*
** deletenode.c for spacewar in /home/helain_f/Semestre_3/spacewar
** 
** Made by Florian Helaine
** Login   <helain_f@epitech.net>
** 
** Started on  Thu Jul 25 15:59:30 2013 Florian Helaine
** Last update Thu Jul 25 16:14:36 2013 Florian Helaine
*/

#include	"serveur.h"

void		deletenode(t_player **list, int fd_pl)
{
  t_player	*tmp;

  tmp = *list;
  while (tmp != NULL)
    {
      if (tmp->player_fd == fd_pl)
      	{
	  tmp = NULL;
	}
    }
}
