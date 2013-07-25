/*
** avance.c for avance in /home/adil/Teck2/Spacewar
** 
** Made by adil boumahdi
** Login   <boumah_a@epitech.net>
** 
** Started on  Fri Jul 19 15:18:30 2013 adil boumahdi
** Last update Thu Jul 25 15:27:10 2013 adil boumahdi
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
      if (tmp->player_fd == num_player)
      	{
	  check_value(tmp);
	  check_rotation(tmp);
	  /* tmp->X = (tmp->X + cos(3.14 * tmp->rotation / 180.0)); */
      	  /* tmp->Y = (tmp->Y + sin(3.14 * tmp->rotation / 180.0)); */
	  check_value(tmp);
	  /* printf("%f\n", tmp->X); */
      	  /* printf("%f\n", tmp->Y); */
      	  /* printf("%f\n", tmp->rotation); */
      	  /* printf("%d\n", tmp->player_id); */
	  /* tmp->essence = tmp->essence - coeff  gravité */
	  printf("x == %d y == %d\n", tmp->X, tmp->Y);
	  graph_avance(tmp->player_fd, tmp);
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
  new->essence = node->essence;
  new->rotation = node->rotation;
  new->player_id = node->player_id;
  new->player_fd = node->player_fd;
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
  premier.rotation = 315;
  premier.player_id = 2;
  premier.player_fd = 2;

  /* deux.X = 20.00; */
  /* deux.Y = 30.00; */
  /* deux.rotation = 90; */
  /* deux.player_id = 3; */
  /* deux.player_fd = 3; */

  /* trois.X = 99.00; */
  /* trois.Y = 98.00; */
  /* trois.rotation = 99; */
  /* trois.player_id = 4; */
  /* trois.player_fd = 4; */

  player = NULL;

  addnode(&player, &premier);
  /* addnode(&player, &deux); */
  /* addnode(&player, &trois); */

  avance(&player, num_player);
}
