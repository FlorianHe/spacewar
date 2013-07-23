/*
** droite.c for droite in /home/adil/Teck2/Spacewar
** 
** Made by adil boumahdi
** Login   <boumah_a@epitech.net>
** 
** Started on  Fri Jul 19 15:20:31 2013 adil boumahdi
** Last update Sun Jul 21 16:46:55 2013 adil boumahdi
*/

#include	"spacewar.h"

void            droite(t_player **list, int num_player)
{
  t_player	*tmp;

  while (tmp != NULL)
    {
      if (tmp->player_id == num_player)
	player->rotation = player->rotation + 15;
      tmp = tmp->next;
    }
}
