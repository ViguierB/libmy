/*
** my_hash_table.c for libmy in /home/benji_epitech/workdir/perso/libmy/tmp/lib/my
** 
** Made by Benjamin Viguier
** Login   <benjamin.viguier@epitech.eu>
** 
** Started on  Fri Mar 24 19:49:07 2017 Benjamin Viguier
** Last update Sun Oct 22 21:52:11 2017 Benjamin Viguier
*/

#include <stdlib.h>
#include "internal.h"
#include "libmy.h"
#include "libmy_hash.h"

t_hashmap_value *get_hashmap_value(void *key, const size_t key_len, 
                                    void *value, const size_t value_len)
{
  static t_hashmap_value  res_value;

  res_value = (t_hashmap_value) {
    .key = key,
    .key_len = key_len,
    .value = value,
    .value_len = value_len
  };
  return (&res_value);
}

t_hashmap_result hashmap_push(t_hashmap *hm, t_hashmap_value *value)
{
  uint32_t  hash_value;

  if (hm->avalaible >= hm->size)
    return (HM_ERROR | HM_FULL);
  if (value->key == NULL)
    return (HM_ERROR);
  hash_value = __libmy_get_hashed_key(hm, value);
  my_memcpy(hm->map + hash_value, value, sizeof(t_hashmap_value));
  return (HM_SUCCESS);
}