/*
** my_hash_table.c for libmy in /home/benji_epitech/workdir/perso/libmy/tmp/lib/my
** 
** Made by Benjamin Viguier
** Login   <benjamin.viguier@epitech.eu>
** 
** Started on  Fri Mar 24 19:49:07 2017 Benjamin Viguier
** Last update Thu Apr 27 18:59:33 2017 Benjamin Viguier
*/

#include <stdlib.h>
#include "libmy.h"
#include "libmy_hash.h"

static int	__libmy_push_sub_hm(t_hashmap *hm, int idx,
				    t_hashmap_opts *opts);

static int	__libmy_hm_malloc(t_hashmap_opts *opts)
{
  void	*key;
  void	*value;

  if (!(opts->opts & HM_NOCLONE_KEY))
    {
      if (!(key = malloc(opts->key_len)))
	return (-1);
      my_memcpy(key, opts->key, opts->key_len);
      opts->key = key;
    }
  if (opts->opts & HM_CLONE_VALUE)
    {
      if (!(value = malloc(opts->value_len)))
	return (-1);
      my_memcpy(value, opts->value, opts->value_len);
      opts->value = value;
    }
  return (0);
}

static int	__libmy_hm_setvalue(t_hashmap *hm, int idx,
				    t_hashmap_opts *opts)
{
  hm->tab[idx].type = HM_VALUE;
  hm->tab[idx].uni.value.value = opts->value;
  hm->tab[idx].uni.value.key = opts->key;
  hm->tab[idx].uni.value.key_len = opts->key_len;
  if (!(opts->opts & HM_NOCLONE_KEY))
    hm->tab[idx].uni.value.free_opts |= HM_KEY_NEED_FREE;
  if (opts->opts & HM_CLONE_VALUE)
    hm->tab[idx].uni.value.free_opts |= HM_VALUE_NEED_FREE;
  hm->itm_nbr += 1;
  return (0);
}

static int	__libmy_create_sub_hm(t_hashmap *hm, int idx,
				      t_hashmap_opts *opts)
{
  t_hashmap	*new_hm;

  if (!(new_hm = hashmap_create(MAX(hm->size / 2, MIN_TAB_SIZE), hm->hfct)))
    return (-1);
  new_hm->dim = hm->dim + 1;
  hashmap_push(new_hm, (t_hashmap_opts) {.key = hm->tab[idx].uni.value.key,
	.key_len = hm->tab[idx].uni.value.key_len,
	.value = hm->tab[idx].uni.value.value,
	.opts = (!(hm->tab[idx].uni.value.free_opts & HM_KEY_NEED_FREE))
	| (hm->tab[idx].uni.value.free_opts & HM_VALUE_NEED_FREE),
	.value_len = 0});
  hm->tab[idx].type = HM_SUB_HASHMAP;
  hm->tab[idx].uni.sub = new_hm;
  idx = new_hm->hfct(opts->key, opts->key_len, new_hm->dim) % new_hm->size;
  if (new_hm->tab[idx].type == HM_EMPTY)
    return (__libmy_hm_setvalue(new_hm, idx, opts));
  else
    return (__libmy_push_sub_hm(new_hm, idx, opts));
}

static int		__libmy_push_sub_hm(t_hashmap *hm, int idx,
					    t_hashmap_opts *opts)
{
  if (hm->tab[idx].type == HM_SUB_HASHMAP)
    {
      hm = hm->tab[idx].uni.sub;
      idx = hm->hfct(opts->key, opts->key_len, hm->dim) % hm->size;
      if (hm->tab[idx].type == HM_EMPTY)
	return (__libmy_hm_setvalue(hm, idx, opts));
      else
	return (__libmy_push_sub_hm(hm, idx, opts));
    }
  else if (hm->tab[idx].type == HM_VALUE)
    {
      if (hm->tab[idx].uni.value.key_len != opts->key_len ||
	  my_memcmp(hm->tab[idx].uni.value.key, opts->key, opts->key_len))
	return (__libmy_create_sub_hm(hm, idx, opts));
      else if (opts->opts & HM_NO_OVERWR)
	return (-1);
      return (__libmy_hm_setvalue(hm, idx, opts));
    }
  else
    return (-2);
}

int	hashmap_push(t_hashmap *hm, t_hashmap_opts opts)
{
  int	idx;

  if (__libmy_hm_malloc(&opts) < 0)
    return (-1);
  idx = hm->hfct(opts.key, opts.key_len, hm->dim) % hm->size;
  if (hm->tab[idx].type == HM_EMPTY)
    return (__libmy_hm_setvalue(hm, idx, &opts));
  else
    return (__libmy_push_sub_hm(hm, idx, &opts));
}
