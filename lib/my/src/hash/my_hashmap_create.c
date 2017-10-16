/*
** my_hashmap_create.c for libmy in /home/benji_epitech/workdir/perso/libmy/tmp/lib/my
** 
** Made by Benjamin Viguier
** Login   <benjamin.viguier@epitech.eu>
** 
** Started on  Thu Apr 27 16:42:10 2017 Benjamin Viguier
** Last update Mon Oct 16 23:12:54 2017 Benjamin Viguier
*/

#include <stdlib.h>
#include "libmy.h"
#include "libmy_hash.h"

t_hashmap	*hashmap_create(size_t len, t_hash_fct fct)
{
  t_hashmap     *hashmap_result;

  hashmap_result = malloc(sizeof(t_hashmap) + (t_hashmap_value * len));
  if (!hashmap_result) {
    return NULL;
  }
  my_memset(hashmap_result->map, 0, t_hashmap_value * len);
  hashmap_result->hash_fct = fct;
  hashmap_result->size = len;
  hashmap_result->avalaible = 0;
  return hashmap_result;
}
