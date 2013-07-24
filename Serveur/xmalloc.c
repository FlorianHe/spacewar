/*
** xmalloc.c for zappy in /home/bastien/project/zappy-2016-helain_f/Serveur
** 
** Made by bastien debret
** Login   <bastien@epitech.net>
** 
** Started on  Wed Jun 26 14:54:01 2013 bastien debret
** Last update Wed Jul 24 19:01:58 2013 Florian Helaine
*/

#include	<stdlib.h>

void                    *xmalloc(int size)
{
  void                  *ptr;

  ptr = malloc(size);
  if (ptr == NULL)
    exit(EXIT_FAILURE);
  else
    return (ptr);
}
