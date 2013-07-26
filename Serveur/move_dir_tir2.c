/*
** move_dir_tir2.c for spacewar in /home/helain_f/Semestre_3/spacewar
** 
** Made by Florian Helaine
** Login   <helain_f@epitech.net>
** 
** Started on  Fri Jul 26 14:28:29 2013 Florian Helaine
** Last update Fri Jul 26 14:43:18 2013 Florian Helaine
*/

#include	"spacewar.h"

void            Hundred_twenty_five_tir(t_missile *tir, int i)
{
  tir->x = tir->x - i;
  tir->y = tir->y + i;
}

void            Hundred_seventy_tir(t_missile *tir, int i)
{
  tir->x = tir->x - i;
}

void            Hundred_fifteen_tir(t_missile *tir, int i)
{
  tir->x = tir->x - i;
  tir->y = tir->y - i;
}
