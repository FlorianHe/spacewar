/*
** tir.c for tir in /home/adil/Teck2/Spacewar
** 
** Made by adil boumahdi
** Login   <boumah_a@epitech.net>
** 
** Started on  Mon Jul 22 13:36:43 2013 adil boumahdi
** Last update Tue Jul 23 17:18:46 2013 adil boumahdi
*/

#include	"spacewar.h"

void		*tir(t_player **list, int num_player)
{
  t_player	*tmp;

  tmp = *list;
  while (tmp != NULL)
    {
      if (tmp->player_id == num_player)
	{
	  tir2(tmp);
	  return (NULL);
	}
      tmp = tmp->next;
    }
}

void			tir2(t_player *player)
{
  t_missile		*missile;

  missile = malloc(sizeof(t_missile));
  missile->x = player->X;
  missile->y = player->Y;
  missile->rotation = player->rotation;

  addmissile((&player->missile), missile);
  test(&player->missile);
}

void			test(t_missile	**list)
{
  t_missile *tmp;

  tmp = *list;
  while (tmp != NULL)
    {
      printf("%d\n", tmp->x);
      tmp = tmp->next;
    }
}

void            addmissile(t_missile **start, t_missile *node)
{
  t_missile      *new;

  new = malloc(sizeof(t_missile));
  new->x = node->x;
  new->y = node->y;
  new->rotation = node->rotation;
  new->next = *start;
  *start = new;
}

void            addnode(t_player **start, t_player *node)
{
  t_player      *new;

  new = malloc(sizeof(t_player));
  new->X = node->X;
  new->Y = node->Y;
  new->essence = node->essence;
  new->rotation = node->rotation;
  new->player_id = node->player_id;
  new->missile = NULL;
  new->next = *start;
  *start = new;
}

int		main(int ac, char **av)
{
  t_player      *player;
  t_player      premier;
  t_player      deux;
  t_player      trois;
  int           num_player;

  num_player = 2;

  player =  malloc(sizeof(t_player));

  premier.X = 13.00;
  premier.Y = 15.00;
  premier.essence = 80;
  premier.rotation = 40;
  premier.player_id = 2;

  deux.X = 20.00;
  deux.Y = 30.00;
  deux.essence = 90;
  deux.rotation = 90;
  deux.player_id = 3;

  trois.X = 99.00;
  trois.Y = 98.00;
  trois.essence = 100;
  trois.rotation = 99;
  trois.player_id = 3;

  player = NULL;
  /* player->missile =  NULL; */

  addnode(&player, &premier);
  addnode(&player, &deux);
  addnode(&player, &trois);

  tir(&player, num_player);
  tir(&player, num_player);
}
