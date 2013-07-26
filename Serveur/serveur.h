/*
** serveur.h for Spacewar in /home/mizuko/RAT
**
** Made by Augustin Marchand
** Login   <marcha_q@epitech.net>
**
** Started on  Mon Jul 22 14:48:51 2013 Augustin Marchand
** Last update Fri Jul 26 18:26:15 2013 Augustin Marchand
*/

#ifndef			SERVEUR_H__
#define			SERVEUR_H__

#include		<stdlib.h>
#include		<stdio.h>
#include		"spacewar.h"

#define			FD_FREE 0
#define			FD_SERVEUR 1
#define			FD_CLIENT 2

#define			MAX_FD 512

typedef void		(*ptr)();

typedef struct		s_serv
{
  int			player;
  int			game;
  int			port;
  int			id_player;
  int			fd_type[MAX_FD];
  ptr			fct_read[MAX_FD];
  t_player		*next;
}			t_serv;

void			serveur_read(t_serv *, int);
void			client_read(t_serv *, int);
void			addnode(t_player **, t_player *);
void                    *xmalloc(int size);

#endif
