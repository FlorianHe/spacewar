/*
** avance.c for avance in /home/adil/Teck2/Spacewar
** 
** Made by adil boumahdi
** Login   <boumah_a@epitech.net>
** 
** Started on  Fri Jul 19 15:18:30 2013 adil boumahdi
** Last update Mon Jul 22 16:54:22 2013 adil boumahdi
*/

#include	"spacewar.h"

void		avance(t_player **list, int num_player)
{
  t_player	*tmp;

  tmp = *list;
  while (tmp != NULL)
    {
      if (tmp->player_id == num_player)
      	{
      	  tmp->X = (tmp->X + cos(3.14 * tmp->rotation / 180.0));
      	  tmp->Y = (tmp->Y + sin(3.14 * tmp->rotation / 180.0));
      	  printf("%f\n", tmp->X);
      	  printf("%f\n", tmp->Y);
      	  printf("%d\n", tmp->essence);
      	  printf("%f\n", tmp->rotation);
      	  printf("%d\n", tmp->player_id);
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

  premier.X = 13.00;
  premier.Y = 15.00;
  player->essence = 80;
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
