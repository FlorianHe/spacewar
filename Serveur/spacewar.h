/*
** spacewar.h for spacewar in /home/adil/Teck2/Spacewar
** 
** Made by adil boumahdi
** Login   <boumah_a@epitech.net>
** 
** Started on  Thu Jul 18 18:36:04 2013 adil boumahdi
** Last update Sat Jul 27 18:26:08 2013 Florian Helaine
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
  int			time;
  int			essence;
  int			rotation;
  int			player_id;
  int			player_fd;
  int			nb_missile;
  struct s_missile	*missile;
  struct s_player	*next;
}			t_player;

typedef struct		s_missile
{
  int			x;
  int			y;
  int			rotation;
  int			nb_tir;
  int			time;
  int			time_grav;
  struct s_missile	*next;
}			t_missile;

typedef struct          s_rotation
{
  int                   rotation_;
  void                  (*funct)(t_player *);
}                       t_rotation;

typedef struct          s_rotation_tir
{
  int                   rotation_;
  void                  (*funct)(t_missile *, int);
}                       t_rotation_tir;

void			tir2(t_player **, t_player *);
void			addmissile(t_missile **, t_missile *);
void                    check_rotation(t_player *);
void                    Zero(t_player *);
void                    Forty_five(t_player *);
void                    Ninety(t_player *);
void                    Hundred_thirty_five(t_player *);
void                    Hundred_eighty(t_player *);
void                    Hundred_twenty_five(t_player *);
void                    Hundred_seventy(t_player *);
void                    Hundred_fifteen(t_player *);
void			Zero_tir(t_missile *, int);
void			Forty_five_tir(t_missile *, int);
void			Ninety_tir(t_missile *, int);
void			Hundred_thirty_five_tir(t_missile *, int);
void			Hundred_eighty_tir(t_missile *, int);
void			Hundred_twenty_five_tir(t_missile *, int);
void		        Hundred_seventy_tir(t_missile *, int);
void			Hundred_fifteen_tir(t_missile *, int);

#endif
