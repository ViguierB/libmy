/*
** my_hashmap_remove.c for libmy in /home/benji_epitech/workdir/perso/libmy/tmp/lib/my
** 
** Made by Benjamin Viguier
** Login   <benjamin.viguier@epitech.eu>
** 
** Started on  Thu Apr 27 18:16:25 2017 Benjamin Viguier
** Last update Wed Nov 01 20:02:48 2017 Benjamin Viguier
*/

#include <stdlib.h>
#include "internal.h"
#include "libmy_hash.h"

t_hashmap_result  hashmap_remove(t_hashmap *hm, t_hashmap_element *key,
                                  void (*free_fct)(t_hashmap_element *))
{
  (void) hm;
  (void) key;
  (void) free_fct;
  return (HM_SUCCESS);
}