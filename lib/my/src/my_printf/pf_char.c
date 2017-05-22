/*
** pf_char.c for libmy in /home/benji_epitech/workdir/perso/libmy/lib/my
** 
** Made by Benjamin Viguier
** Login   <benjamin.viguier@epitech.eu>
** 
** Started on  Mon May 22 19:39:06 2017 Benjamin Viguier
** Last update Mon May 22 19:39:25 2017 Benjamin Viguier
*/

#include "internal.h"

int	__pf_char(t_pf_data *pf, t_pf_prm *fmt)
{
  int	width;

  width = fmt->width;
  if (fmt->flag & PF_FLAG_SUB)
    __pf_putchar(pf, fmt->myvar.d);
  while (--width > 0)
    __pf_putchar(pf, ' ');
  if (!(fmt->flag & PF_FLAG_SUB))
    __pf_putchar(pf, fmt->myvar.d);
  return (0);
}
