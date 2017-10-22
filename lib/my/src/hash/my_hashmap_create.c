/*
** my_hashmap_create.c for libmy in /home/benji_epitech/workdir/perso/libmy/tmp/lib/my
** 
** Made by Benjamin Viguier
** Login   <benjamin.viguier@epitech.eu>
** 
** Started on  Thu Apr 27 16:42:10 2017 Benjamin Viguier
** Last update Sun Oct 22 21:53:16 2017 Benjamin Viguier
*/

#include <stdlib.h>
#include "libmy.h"
#include "libmy_hash.h"

t_hashmap	*hashmap_create(size_t len, t_hash_fct fct)
{
  t_hashmap     *hashmap_result;

  if (!len) 
    len = DEFAULT_MAP_SIZE;
  if (!fct)
    fct = &murmur3_32;
  hashmap_result = malloc(sizeof(t_hashmap) + (sizeof(t_hashmap_value) * len));
  if (!hashmap_result) {
    return NULL;
  }
  my_memset(hashmap_result->map, 0, sizeof(t_hashmap_value) * len);
  hashmap_result->hash_fct = fct;
  hashmap_result->size = len;
  hashmap_result->avalaible = 0;
  return (hashmap_result);
}

t_hashmap_value *hm_f_ss(char *key, char *value)
{
  return (get_hashmap_value(key, my_strlen(value), value, my_strlen(value)));
}

t_hashmap_value *hm_f_sh(char *key, void *value, const size_t value_len)
{
  return (get_hashmap_value(key, my_strlen(value), value, value_len));
}