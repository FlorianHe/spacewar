/*
** graph_droite.c for spacewar in /home/helain_f/Semestre_3/spacewar/Serveur
** 
** Made by Florian Helaine
** Login   <helain_f@epitech.net>
** 
** Started on  Wed Jul 24 21:08:03 2013 Florian Helaine
** Last update Wed Jul 24 21:12:03 2013 Florian Helaine
*/

#include	"serveur.h"

void		graph_droite(int fd, t_player *perso)
{
  char		tmp[1024];

  memset(tmp, '\0', 1024);
  sprintf(tmp, "Dro %d %d\n", perso->player_id, perso->rotation);
  write(1, tmp, strlen(tmp));
  write(fd, tmp, strlen(tmp));
}
