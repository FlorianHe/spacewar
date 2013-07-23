/*
** map_alloc.c for map_alloc in /home/adil/Teck2/Spacewar
** 
** Made by adil boumahdi
** Login   <boumah_a@epitech.net>
** 
** Started on  Fri Jul 19 09:51:43 2013 adil boumahdi
** Last update Fri Jul 19 15:18:22 2013 adil boumahdi
*/

#include	"spacewar.h"

char		**alloc_map()
{
  char		**map;
  int		i;

  i = 0;
  map = malloc((50 + 1) * sizeof (char*));
  while (i < 50)
    {
      map[i] = malloc((50 + 1) * sizeof (char));
      i++;
    }
  map[i] = NULL;
  return (map);
}

char		**place_game(char **map)
{
  map[48][10] = 1; //bot
  map[25][25] = 2; //planete du centre
  map[2][30] = 3; //Joueur 1;
  move_opponent(map);
  return (map);
}

int		check_colision(char **map)
{
}

char		**move_opponent(char **map)
{
  int		x;
  int		y;

  while (check_crash(map) != 1)
    {
    }
}



int		main(int ac, char **av)
{
  char		**tab;

  tab = alloc_map();
  place_game(tab);
}



