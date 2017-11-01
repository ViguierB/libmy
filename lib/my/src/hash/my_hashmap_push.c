/*
** my_hash_table.c for libmy in /home/benji_epitech/workdir/perso/libmy/tmp/lib/my
** 
** Made by Benjamin Viguier
** Login   <benjamin.viguier@epitech.eu>
** 
** Started on  Fri Mar 24 19:49:07 2017 Benjamin Viguier
** Last update Wed Nov 01 20:00:12 2017 Benjamin Viguier
*/

#include <stdlib.h>
#include "internal.h"
#include "libmy.h"
#include "libmy_hash.h"

static t_hashmap_result __libmy_hashmap_pushto_clist(t_hashmap *hm,
                                                    t_bucket_elem *buck_elem,
                                                    t_hashmap_element *value)
{
  t_hashmap_element *need_malloc;

  need_malloc = malloc(sizeof(t_hashmap_element));
  if (!need_malloc)
    return (HM_ERROR | HM_OUTOFMEM);
  my_memcpy(need_malloc, value, sizeof(t_hashmap_element));
  buck_elem->value.clist = clist_push(buck_elem->value.clist, need_malloc);
  if (!buck_elem->value.clist)
    return (HM_ERROR | HM_OUTOFMEM);
  hm->used++;
  return (HM_SUCCESS);
}

static t_hashmap_result __libmy_hashmap_pushto_element(t_hashmap *hm,
                                                      t_bucket_elem *elem,
                                                      t_hashmap_element *value)
{
  t_hashmap_element *new;
  t_hashmap_element *old;

  new = malloc(sizeof(t_hashmap_element));
  old = malloc(sizeof(t_hashmap_element));
  if (!old || !new)
    return (HM_ERROR | HM_OUTOFMEM);
  my_memcpy(old, &(elem->value.elem), sizeof(t_hashmap_element));
  my_memcpy(new, value, sizeof(t_hashmap_element));
  elem->value.clist = clist_push(NULL, old);
  if (!elem->value.clist)
    return (HM_ERROR | HM_OUTOFMEM);
  elem->value.clist = clist_push(elem->value.clist, old);
  if (!elem->value.clist)
    return (HM_ERROR | HM_OUTOFMEM);
  hm->used++;
  return (HM_SUCCESS);
}

t_hashmap_result hashmap_push(t_hashmap *hm, t_hashmap_element *value)
{
  t_bucket_elem *bucket_elem;
  int           rehash_result;

  rehash_result = __libmy_hashmap_check_for_rehash(hm);
  if (rehash_result & HM_ERROR)
    return (rehash_result);
  if (value->key == NULL)
    return (HM_ERROR);
  bucket_elem = &(hm->bucket[__libmy_get_hashed_key(hm, value)]);
  if (bucket_elem->type == HM_EMPTY)
  {
    my_memcpy(&(bucket_elem->value.elem), value, sizeof(t_hashmap_element));
    bucket_elem->type = HM_ELEMENT;
    hm->used++;
    return (HM_SUCCESS);
  }
  else if (bucket_elem->type == HM_CLIST)
    return (__libmy_hashmap_pushto_clist(hm, bucket_elem, value));
  else if (bucket_elem->type == HM_ELEMENT)
    return (__libmy_hashmap_pushto_element(hm, bucket_elem, value));
  else
    return (HM_ERROR);
}