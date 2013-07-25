/*
** move_dir.c for dir in /home/adil/Teck2/Spacewar/spacewar/Serveur
** 
** Made by adil boumahdi
** Login   <boumah_a@epitech.net>
** 
** Started on  Thu Jul 25 14:53:15 2013 adil boumahdi
** Last update Thu Jul 25 15:47:46 2013 Florian Helaine
*/

#include	"spacewar.h"

void            Zero(t_player *player)
{
  printf("%d\n", player->X);
  player->Y = player->Y - 1;
  printf("%d\n", player->X);
}

void            Forty_five(t_player     *player)
{
  player->Y = player->Y - 1;
  player->X = player->X + 1;
}

void            Ninety(t_player *player)
{
  player->X = player->X + 1;
}

void            Hundred_thirty_five(t_player    *player)
{
  player->X = player->X + 1;
  player->Y = player->Y + 1;
}

void            Hundred_eighty(t_player *player)
{
  player->Y = player->Y + 1;
}
