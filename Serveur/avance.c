/*
** avance.c for avance in /home/adil/Teck2/Spacewar
** 
** Made by adil boumahdi
** Login   <boumah_a@epitech.net>
** 
** Started on  Fri Jul 19 15:18:30 2013 adil boumahdi
** Last update Tue Jul 23 15:35:35 2013 adil boumahdi
*/

#include	"spacewar.h"

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
      if (tmp->player_id == num_player)
      	{
	  check_value(tmp);
	  tmp->X = (tmp->X + cos(3.14 * tmp->rotation / 180.0));
      	  tmp->Y = (tmp->Y + sin(3.14 * tmp->rotation / 180.0));
	  check_value(tmp);
	  /* printf("%f\n", tmp->X); */
      	  /* printf("%f\n", tmp->Y); */
      	  /* printf("%f\n", tmp->rotation); */
      	  /* printf("%d\n", tmp->player_id); */
	  /* tmp->essence = tmp->essence - coeff  gravité */
	}
      tmp = tmp->next;
    }
}

void		addnode(t_player **start, t_player *node)
{
  t_player	*new;

  new = malloc(sizeof(t_player));

  new->X = node->X;
  new->Y = node->Y;
  new->essence = node->essence;
  new->rotation = node->rotation;
  new->player_id = node->player_id;

  new->next = *start;
  *start = new;
}

int             main(int ac, char **av)
{
  t_player      *player;
  t_player	premier;
  t_player	deux;
  t_player	trois;
  int		num_player;

  num_player = 2;

  player =  malloc(sizeof(t_player));

  premier.X = 1004;
  premier.Y = -15.00;
  player->essence = 30;
  premier.rotation = 40;
  premier.player_id = 2;

  deux.X = 20.00;
  deux.Y = 30.00;
  player->essence = 90;
  deux.rotation = 90;
  deux.player_id = 3;

  trois.X = 99.00;
  trois.Y = 98.00;
  player->essence = 100;
  trois.rotation = 99;
  trois.player_id = 4;

  player = NULL;

  addnode(&player, &premier);
  addnode(&player, &deux);
  addnode(&player, &trois);

  avance(&player, num_player);
}
