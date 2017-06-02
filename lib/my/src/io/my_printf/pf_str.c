/*
** pf_str.c for libmy in /home/ben/epitech/libmy/tmp/lib/my
** 
** Made by Benjamin Viguier
** Login   <benjamin.viguier@epitech.eu>
** 
** Started on  Thu May 18 01:22:12 2017 Benjamin Viguier
** Last update Fri Jun  2 11:07:52 2017 Benjamin Viguier
*/

#include "internal.h"

void	__pf_do_strwidth(t_pf_data *pf, int local)
{
  int	width;

  width = MAX(local, 0);
  while (width--)
    __pf_putchar(pf, ' ');
}

int		__pf_str(t_pf_data *pf, t_pf_prm *fmt)
{
  int		wlocal;
  int		plocal;
  char		*str;
  size_t	my_len;

  if (fmt->myvar.s == NULL)
    fmt->myvar.s = "(null)";
  str = fmt->myvar.s;
  my_len = ((fmt->preci < 0) ? my_strlen(str) :
	    my_strnlen(str, (size_t) fmt->preci));
  plocal = ((fmt->preci < 0) ? my_len : MIN((size_t) fmt->preci, my_len));
  wlocal = __pf_wisneg(fmt, fmt->width) - plocal;
  if (!(fmt->flag & PF_FLAG_SUB))
    __pf_do_strwidth(pf, wlocal);
  while (plocal-- && *str)
    __pf_write(pf, str++, 1);
  if (fmt->flag & PF_FLAG_SUB)
    __pf_do_strwidth(pf, wlocal);
  return (0);
}
