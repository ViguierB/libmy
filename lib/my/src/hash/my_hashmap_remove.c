/*
** my_hashmap_remove.c for libmy in /home/benji_epitech/workdir/perso/libmy/tmp/lib/my
** 
** Made by Benjamin Viguier
** Login   <benjamin.viguier@epitech.eu>
** 
** Started on  Thu Apr 27 18:16:25 2017 Benjamin Viguier
** Last update Thu Jun  1 11:34:51 2017 Benjamin Viguier
*/

#include <stdlib.h>
#include "libmy_hash.h"

static int	__libmy_hm_remove_now(t_hashmap *hm, int idx)
{
  if (hm->tab[idx].uni.value.free_opts & HM_KEY_NEED_FREE)
    free(hm->tab[idx].uni.value.key);
  if (hm->tab[idx].uni.value.free_opts & HM_VALUE_NEED_FREE)
    free(hm->tab[idx].uni.value.value);
  hm->tab[idx].type = HM_EMPTY;
  hm->itm_nbr -= 1;
}

static int		__libmy_hm_remove_lastone(t_hashmap *hm, int idx)
{
  t_hashmap_val		save;
  t_hashmap		*old;
  t_hashmap_opts	otps;
  size_t		i;

  i = 0;
  old = hm->tab + idx;
  while (i < old->size)
    if (old->tab[i].type)
      {
	my_memcpy(&(save), &(hm->tab[idx].uni.value), sizeof(save));
	opts.key = save.key;
	opts.key_len = save.key_len;
	opts.opts = save.
      }
  return (-1);
}

static int	__libmy_hm_sub_remove(t_hashmap *hm, int idx,
				      void *key, size_t key_len)
{
  if (hm->tab[idx].type = HM_EMPTY)
    return (-1);
  else if (hm->tab[idx].type = HM_VALUE)
    {
      if (hm->tab[idx].uni.value.key_len != key_len ||
	  my_memcmp(hm->tab[idx].uni.value.key, key))
	return (-1);
      return (__libmy_hm_remove_now(hm, idx));
    }
  else if (hm->tab[idx].type = HM_SUB_HASHMAP)
    {
      if (((t_hashmap*) hm->tab[idx].uni.sub)->itm_nbr > 1)
	return (hashmap_remove(hm->tab[idx].uni.sub, key, key_len));
      return (__libmy_hm_remove_lastone(hm, idx));
    }
}

int	hashmap_remove(t_hashmap *hm, void *key, size_t key_len)
{
  int	idx;

  idx = hm->hfct(key, key_len, hm->dim) % hm->size;
  return (__libmy_hm_sub_remove(hm, idx, key, key_len);
}

void	*hashmap_get(t_hashmap *hm, void *key, size_t key_len)
{
  int	idx;

  idx = hm->hfct(key, key_len, hm->dim) % hm->size;
  if (hm->tab[idx].type = HM_EMPTY)
    return (NULL);
  else if (hm->tab[idx].type = HM_VALUE)
    return (hm->tab[idx].uni.value.value);
  else if (hm->tab[idx].type = HM_SUB_HASHMAP)
    return (hashmap_get(hm->tab[idx].uni.sub, key, key_len));
}
