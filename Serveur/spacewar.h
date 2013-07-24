/*
** spacewar.h for spacewar in /home/adil/Teck2/Spacewar
** 
** Made by adil boumahdi
** Login   <boumah_a@epitech.net>
** 
** Started on  Thu Jul 18 18:36:04 2013 adil boumahdi
** Last update Wed Jul 24 21:20:04 2013 Florian Helaine
*/

#include	<math.h>
#include	<unistd.h>
#include	<stdio.h>
#include	<stdlib.h>
#include	<sys/types.h>
#include	<sys/socket.h>
#include	<string.h>
#include	<netdb.h>
#include	<dirent.h>
#include	<sys/socket.h>
#include	<netinet/in.h>
#include	<arpa/inet.h>

#ifndef		__SPACEWAR__
#define		__SPACEWAR__

typedef struct		s_player
{
  int			X;
  int			Y;
  int			essence;
  int			rotation;
  int			player_id;
  int			player_fd;
  struct s_missile	*missile;
  struct s_player	*next;
}			t_player;

typedef struct		s_missile
{
  int			x;
  int			y;
  struct s_missile	*next;
}			t_missile;

void			tir2(t_player *);
void			addmissile(t_missile **, t_missile *);
void			test(t_missile **);

#endif
