/*
** move_dir_tir.c for spacewar in /home/helain_f/Semestre_3/spacewar
** 
** Made by Florian Helaine
** Login   <helain_f@epitech.net>
** 
** Started on  Fri Jul 26 14:23:28 2013 Florian Helaine
** Last update Fri Jul 26 14:42:51 2013 Florian Helaine
*/

#include	"spacewar.h"

void            Zero_tir(t_missile *tir, int i)
{
  tir->y = tir->y - i;
}

void            Forty_five_tir(t_missile *tir, int i)
{
  tir->y = tir->y - i;
  tir->x = tir->x + i;
}

void            Ninety_tir(t_missile *tir, int i)
{
  tir->x = tir->x + i;
}

void            Hundred_thirty_five_tir(t_missile *tir, int i)
{
  tir->x = tir->x + i;
  tir->y = tir->y + i;
}

void            Hundred_eighty_tir(t_missile *tir, int i)
{
  tir->y = tir->y + i;
}
