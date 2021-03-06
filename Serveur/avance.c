/*
** avance.c for avance in /home/adil/Teck2/Spacewar
** 
** Made by adil boumahdi
** Login   <boumah_a@epitech.net>
** 
** Started on  Fri Jul 19 15:18:30 2013 adil boumahdi
** Last update Sun Jul 28 18:22:09 2013 Florian Helaine
*/

#include	"serveur.h"

static	t_rotation	tab_value_[8] =
  {
    {0, Zero},
    {45, Forty_five},
    {90, Ninety},
    {135, Hundred_thirty_five},
    {180, Hundred_eighty},
    {225, Hundred_twenty_five},
    {270, Hundred_seventy},
    {315, Hundred_fifteen}
  };

void		check_value(t_player *player)
{
  if (player->X > 0)
    player->X = player->X % 800;
  else if (player->X < 0)
    player->X = 800 + player->X;
  if (player->Y > 0)
    player->Y = player->Y % 800;
  else if (player->Y < 0)
    player->Y = 800 + player->Y;
}

void		avance(t_player **list, int num_player)
{
  t_player	*tmp;

  tmp = *list;
  while (tmp != NULL)
    {
      if (tmp->player_fd == num_player && tmp->essence > 0)
      	{
	  check_value(tmp);
	  check_rotation(tmp);
	  check_value(tmp);
	  tmp->essence--;
	  graph_avance(list, tmp);
	  graph_essence(list, tmp);
	}
      tmp = tmp->next;
    }
}

void		check_rotation(t_player *player)
{
  int		j;

  j = 0;
  while (j < 8 && player->rotation != tab_value_[j].rotation_)
    j++;
  if (j != 8)
    tab_value_[j].funct(player);
}

void		addnode(t_player **start, t_player *node)
{
  t_player	*new;

  new = xmalloc(sizeof(t_player));
  new->X = node->X;
  new->Y = node->Y;
  new->time = 0;
  new->essence = 999;
  new->rotation = 0;
  new->player_id = node->player_id;
  new->player_fd = node->player_fd;
  new->nb_missile = 0;
  new->missile = node->missile;
  new->next = *start;
  *start = new;
}
