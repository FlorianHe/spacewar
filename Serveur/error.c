/*
** error.c for Spacewar in /home/mizuko/RAT
**
** Made by Augustin Marchand
** Login   <marcha_q@epitech.net>
**
** Started on  Mon Jul 22 14:09:52 2013 Augustin Marchand
** Last update Mon Jul 22 14:23:13 2013 Augustin Marchand
*/

#include			<stdlib.h>
#include			<string.h>

void				error(char *buff)
{
  write(2, buff, strlen(buff));
  exit(EXIT_SUCCESS);
}
