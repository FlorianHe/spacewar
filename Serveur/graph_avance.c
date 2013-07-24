/*
** graph_avance.c for spacewar in /home/helain_f/Semestre_3/spacewar
** 
** Made by Florian Helaine
** Login   <helain_f@epitech.net>
** 
** Started on  Wed Jul 24 18:40:32 2013 Florian Helaine
** Last update Wed Jul 24 21:08:35 2013 Florian Helaine
*/

#include	"serveur.h"

void		graph_avance(int fd, t_player *perso)
{
  char		tmp[1024];

  memset(tmp, '\0', 1024);
  sprintf(tmp, "Ava %d %d %d\n", perso->player_id, perso->X, perso->Y);
  write(1, tmp, strlen(tmp));
  write(fd, tmp, strlen(tmp));
}
