/*
** my_hashmap_internal.c for libmy in /home/benji_epitech/workdir/libmy/lib/my/src/hash
**
** Made by Benjamin Viguier
** Login   <benjamin.viguier@epitech.eu>
**
** Started on  Sun Oct 22 13:07:23 2017 Benjamin Viguier
** Last update Wed Nov 01 20:01:56 2017 Benjamin Viguier
*/

#include "libmy.h"
#include "libmy_hash.h"

uint32_t __libmy_get_hashed_key(t_hashmap *hm, t_hashmap_element *value)
{
  return (hm->hash_fct(value->key, value->key_len, 0));
}