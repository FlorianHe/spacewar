/*
** check_value.c for check_value in /home/adil/Teck2/Spacewar
** 
** Made by adil boumahdi
** Login   <boumah_a@epitech.net>
** 
** Started on  Tue Jul 23 13:42:58 2013 adil boumahdi
** Last update Tue Jul 23 14:11:11 2013 adil boumahdi
*/

#include	"spacewar.h"

void		check_value(t_player *player)
{
  if (player->X > 1000)
    player->X = 0;
  else if (player->X < 0)
    player->X = 1000;
  if (player->Y < 0)
    player->Y = 1000;
  else if (player->Y > 1000)
    player->Y = 0;
}
