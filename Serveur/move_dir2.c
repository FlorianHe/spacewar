/*
** move_dir2.c for move_dir2 in /home/adil/Teck2/Spacewar/spacewar/Serveur
** 
** Made by adil boumahdi
** Login   <boumah_a@epitech.net>
** 
** Started on  Thu Jul 25 14:55:36 2013 adil boumahdi
** Last update Fri Jul 26 14:28:53 2013 Florian Helaine
*/

#include	"spacewar.h"

void            Hundred_twenty_five(t_player *player)
{
  player->X = player->X - 1;
  player->Y = player->Y + 1;
}

void            Hundred_seventy(t_player *player)
{
  player->X = player->X - 1;
}

void            Hundred_fifteen(t_player *player)
{
  player->X = player->X - 1;
  player->Y = player->Y - 1;
}
