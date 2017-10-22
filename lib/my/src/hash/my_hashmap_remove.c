/*
** my_hashmap_remove.c for libmy in /home/benji_epitech/workdir/perso/libmy/tmp/lib/my
** 
** Made by Benjamin Viguier
** Login   <benjamin.viguier@epitech.eu>
** 
** Started on  Thu Apr 27 18:16:25 2017 Benjamin Viguier
** Last update Sun Oct 22 22:02:02 2017 Benjamin Viguier
*/

#include <stdlib.h>
#include "internal.h"
#include "libmy_hash.h"

t_hashmap_result  hashmap_remove(t_hashmap *hm, t_hashmap_value *key,
                                  void (*free_fct)(t_hashmap_value *))
{
  uint32_t  hashed;
  
  hashed = __libmy_get_hashed_key(hm, key);
  if (hm->map[hashed].key != NULL)
  {
    if (free_fct)
      free_fct(hm->map + hashed);
    my_memset(hm->map + hashed, 0, sizeof(t_hashmap_value));
    return (HM_SUCCESS);
  }
  else
  {
    return (HM_ERROR | HM_EMPTY);
  }
}