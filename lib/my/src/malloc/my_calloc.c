/*
** calloc.c for libmy in /home/benji_epitech/workdir/perso/libmy/tmp/lib/my/src/malloc
** 
** Made by Benjamin Viguier
** Login   <benjamin.viguier@epitech.eu>
** 
** Started on  Wed Apr 26 15:30:40 2017 Benjamin Viguier
** Last update Wed Apr 26 16:00:54 2017 Benjamin Viguier
*/

#include "libmy.h"
#include "libmy_malloc.h"

void	*my_pcalloc(size_t len, int ch)
{
  void	*res;

  res = my_malloc(len);
  my_memset(res, ch, len);
  return (res);
}

void	*my_calloc(size_t len)
{
  return (my_pcalloc(len, 0));
}
