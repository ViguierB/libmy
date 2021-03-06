/*
** my_hashmap_create.c for libmy in /home/benji_epitech/workdir/perso/libmy/tmp/lib/my
** 
** Made by Benjamin Viguier
** Login   <benjamin.viguier@epitech.eu>
** 
** Started on  Thu Apr 27 16:42:10 2017 Benjamin Viguier
** Last update Thu Apr 27 16:59:07 2017 Benjamin Viguier
*/

#include <stdlib.h>
#include "libmy.h"
#include "libmy_hash.h"

t_hashmap	*hashmap_create(size_t len, t_hash_fct fct)
{
  t_hashmap     *res;

  res = malloc(sizeof(*res) + (sizeof(t_hashmap_tab) * len));
  my_memset(res->tab, 0, len);
  res->size = MAX(len, MIN_TAB_SIZE);
  res->hfct = fct;
  res->dim = 0;
  res->itm_nbr = 0;
  return (res);
}
