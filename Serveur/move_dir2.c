/*
** move_dir2.c for move_dir2 in /home/adil/Teck2/Spacewar/spacewar/Serveur
** 
** Made by adil boumahdi
** Login   <boumah_a@epitech.net>
** 
** Started on  Thu Jul 25 14:55:36 2013 adil boumahdi
** Last update Thu Jul 25 15:01:42 2013 adil boumahdi
*/

#include	"spacewar.h"

void            Hundred_twenty_five(t_player    *player)
{
  player->X = player->X - 1;
  player->Y = player->Y - 1;
}

void            Hundred_seventy(t_player        *player)
{
  player->Y = player->Y - 1;
}

void            Hundred_fifteen(t_player        *player)
{
  player->X = player->X + 1;
  player->Y = player->Y - 1;
}
