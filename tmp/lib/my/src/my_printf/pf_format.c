/*
** pf_format.c for libmy in /home/benji_epitech/workdir/perso/libmy/tmp/lib/my
** 
** Made by Benjamin Viguier
** Login   <benjamin.viguier@epitech.eu>
** 
** Started on  Mon Feb 27 12:21:52 2017 Benjamin Viguier
** Last update Sat May 13 18:52:46 2017 Benjamin Viguier
*/

#include "internal.h"

int	__pf_format(t_pf_data *data, t_pf_prm *prm)
{
  if (prm->size == 0)
    {
      __pf_putchar(data, '%');
      data->fmt = ((*(prm->save) == '%') ? (prm->save + 1) : prm->save);
      return (0);
    }
  
  return (0);
}
