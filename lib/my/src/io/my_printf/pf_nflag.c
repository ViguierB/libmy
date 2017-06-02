/*
** pf_nflag.c for libmy in /home/benji_epitech/workdir/perso/libmy/lib/my
** 
** Made by Benjamin Viguier
** Login   <benjamin.viguier@epitech.eu>
** 
** Started on  Wed May 24 13:53:15 2017 Benjamin Viguier
** Last update Fri Jun  2 11:40:49 2017 Benjamin Viguier
*/

#include "internal.h"

int	__pf_getnbr(t_pf_data *pf, t_pf_prm *fmt)
{
  int	*ptr;

  ptr = fmt->myvar.ptr;
  if (fmt->flag & PF_FLAG_DEZ)
    *ptr = *ptr + pf->pos;
  else
    *ptr = pf->pos;
  return (0);
}
