/*
** tir.c for tir in /home/adil/Teck2/Spacewar
** 
** Made by adil boumahdi
** Login   <boumah_a@epitech.net>
** 
** Started on  Mon Jul 22 13:36:43 2013 adil boumahdi
** Last update Tue Jul 23 13:40:52 2013 adil boumahdi
*/

#include	"spacewar.h"

t_missile		*tir(t_player **list, int num_player)
{
  t_player	*tmp;

  tmp = *list;
  while (tmp != NULL)
    {
      if (tmp->player_id == num_player)
	{
	  tir2(tmp);
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
  /* printf("%f\n", missile->x); */
  /* printf("%f\n", missile->y); */
  /* printf("%f\n", missile->rotation); */

  addmissile(&missile, missile);
  test(&missile);
}

void			test(t_missile **list)
{
  t_missile *tmp;
  printf("ok\n");

  tmp = *list;
  while (tmp->next != NULL)
    {
      printf("%f\n", tmp->x);
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
  player->essence = 80;
  premier.rotation = 40;
  premier.player_id = 1;

  deux.X = 20.00;
  deux.Y = 30.00;
  player->essence = 90;
  deux.rotation = 90;
  deux.player_id = 2;

  trois.X = 99.00;
  trois.Y = 98.00;
  player->essence = 100;
  trois.rotation = 99;
  trois.player_id = 3;

  player = NULL;

  addnode(&player, &premier);
  addnode(&player, &deux);
  addnode(&player, &trois);

  tir(&player, num_player);
  tir(&player, 3);
}
