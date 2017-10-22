/*
** my_hashmap_internal.c for libmy in /home/benji_epitech/workdir/libmy/lib/my/src/hash
**
** Made by Benjamin Viguier
** Login   <benjamin.viguier@epitech.eu>
**
** Started on  Sun Oct 22 13:07:23 2017 Benjamin Viguier
** Last update Sun Oct 22 13:11:20 2017 Benjamin Viguier
*/

#include "libmy.h"
#include "libmy_hash.h"

uint32_t __libmy_get_hashed_key(t_hashmap *hm, t_hashmap_value *value)
{
  uint16_t        seed;
  uint32_t        hashed;
  t_hashmap_value *cur;

  seed = 0;
  while (1)
  {
    hashed = hm->hash_fct(value->key, value->key_len, seed) % hm->size;
    cur = hm->map + hashed; 
    if (cur->key == NULL || (cur->key_len == value.key_len &&
        my_memcmp(cur->key, value.key, value.key_len))
      return (hashed);
    else
      seed++;
  }
  return (0);
}