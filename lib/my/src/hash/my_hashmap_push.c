/*
** my_hash_table.c for libmy in /home/benji_epitech/workdir/perso/libmy/tmp/lib/my
** 
** Made by Benjamin Viguier
** Login   <benjamin.viguier@epitech.eu>
** 
** Started on  Fri Mar 24 19:49:07 2017 Benjamin Viguier
** Last update Sun Oct 22 13:10:39 2017 Benjamin Viguier
*/

#include <stdlib.h>
#include "libmy.h"
#include "libmy_hash.h"

t_hashmap_result *get_hashmap_value(void *key, uint32_t key_len,
                                    void *value, uint32_t value_len)
{
  static t_hashmap_value  value;

  value = (t_hashmap_value) {
    .key = key,
    .key_len = key_len,
    .value = value,
    .value_len = value_len
  };
  return (&value);
}

t_hashmap_result hashmap_push(t_hashmap *hm, t_hashmap_value *value)
{
  uint32_t  hash_value;

  if (hm->avalaible >= hm->size)
    return (HM_ERROR | HM_FULL);
  hash_value = __libmy_get_hashed_key(hm, value);
  my_memcpy(hm->map + hash_value, value);
  return (HM_SUCCESS);
}