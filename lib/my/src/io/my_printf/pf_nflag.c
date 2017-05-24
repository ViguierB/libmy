/*
** pf_nflag.c for libmy in /home/benji_epitech/workdir/perso/libmy/lib/my
** 
** Made by Benjamin Viguier
** Login   <benjamin.viguier@epitech.eu>
** 
** Started on  Wed May 24 13:53:15 2017 Benjamin Viguier
** Last update Wed May 24 13:54:50 2017 Benjamin Viguier
*/

#include "internal.h"

int	__pf_getnbr(t_pf_data *pf, t_pf_prm *fmt)
{
  int	*ptr;
  
  ptr = fmt->myvar.ptr;
  *ptr = pf->pos;
  return (0);
}
