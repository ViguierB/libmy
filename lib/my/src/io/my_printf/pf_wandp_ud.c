/*
** pf_wandp_ud.c for libmy in /home/benji_epitech/workdir/perso/libmy/tmp/lib/my/src/my_printf
** 
** Made by Benjamin Viguier
** Login   <benjamin.viguier@epitech.eu>
** 
** Started on  Mon May 22 13:47:58 2017 Benjamin Viguier
** Last update Sat May 27 13:24:18 2017 Benjamin Viguier
*/

#include "internal.h"

int	__pf_ud_print(t_pf_data *pf, t_pf_prm *fmt, t_wandp_ud *wandp)
{
  int	space_nbr;
  int	zero_nbr;

  space_nbr = wandp->space_len;
  zero_nbr = wandp->zero_len;
  if (!(fmt->flag & PF_FLAG_SUB))
    while (space_nbr--)
      __pf_putchar(pf, ' ');
  __pf_write(pf, wandp->header, my_strlen(wandp->header));
  while (zero_nbr--)
    __pf_putchar(pf, '0');
  __pf_write(pf, wandp->buffer, my_strlen(wandp->buffer));
  if (fmt->flag & PF_FLAG_SUB)
    while (space_nbr--)
      __pf_putchar(pf, ' ');
  return (0);
}

int	__pf_wisneg(t_pf_prm *fmt, int wlocal)
{
  if (wlocal < 0)
    {
      wlocal = -(wlocal);
      fmt->flag |= PF_FLAG_SUB;
    }
  return (wlocal);
}

int	__pf_wandp_ud(t_pf_prm *fmt, int len,
		      int header_len, t_wandp_ud *res)
{
  int	wlocal;
  int	plocal;

  wlocal = __pf_wisneg(fmt, fmt->width);
  plocal = fmt->preci;
  if (plocal < 0)
    {
      wlocal = wlocal - len - header_len;
      if ((fmt->flag & PF_FLAG_ZERO) && !(fmt->flag & PF_FLAG_SUB))
	res->zero_len = MAX(wlocal, 0);
      else
	res->space_len = MAX(wlocal, 0);
    }
  else
    {
      plocal = plocal - len;
      res->zero_len = MAX(plocal, 0);
      wlocal = wlocal - len - header_len - res->zero_len;
      res->space_len = MAX(wlocal, 0);
    }
  return (0);
}
