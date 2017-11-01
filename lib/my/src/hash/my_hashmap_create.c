/*
** my_hashmap_create.c for libmy in /home/benji_epitech/workdir/perso/libmy/tmp/lib/my
** 
** Made by Benjamin Viguier
** Login   <benjamin.viguier@epitech.eu>
** 
** Started on  Thu Apr 27 16:42:10 2017 Benjamin Viguier
** Last update Wed Nov 01 20:10:06 2017 Benjamin Viguier
*/

#include <stdlib.h>
#include <stdarg.h>
#include "libmy.h"
#include "libmy_hash.h"

static int  get_opts(t_hashmap *hm, const char *opts, va_list va)
{
  hm->hash_fct = &murmur3_32;
  hm->load_factor = DEFAULT_FACTOR;
  hm->size = DEFAULT_MAP_SIZE;
  while (opts) {
    if (*opts == 'f')
      hm->hash_fct = va_arg(va, t_hash_fct);
    else if (*opts == 'l')
      hm->load_factor = (float) va_arg(va, double);
    else if (*opts == 's')
      hm->size = va_arg(va, size_t);
    opts++;
  }
  hm->initial_size = hm->size;
  hm->used = 0;
  return (0);
}

/*
**  Create a new HashMap
**  opts are options like libc fopen, it is a string. exemple :
**    hashmap_create("lf", 0.60, my_hash_function)
**    'l' for load factor
**    'f' for the hash function
**    's' for the initial hashmap size
*/
t_hashmap	  *hashmap_create(const char *opts, ...)
{
  t_hashmap *hm_result;
  va_list   va;

  va_start(va, opts);
  hm_result = malloc(sizeof(t_hashmap));
  if (!hm_result) {
    return NULL;
  }
  get_opts(hm_result, opts, va);
  va_end(va);
  hm_result->bucket = malloc(sizeof(t_bucket_elem) * hm_result->size);
  if (!hm_result->bucket) {
    return NULL;
  }
  my_memset(hm_result->bucket, 0,
    sizeof(t_bucket_elem) * hm_result->size);
  return (hm_result);
}

t_hashmap_element *hm_f_ss(char *key, char *value)
{
  return (get_hashmap_element(key, my_strlen(key), value, my_strlen(value)));
}

t_hashmap_element *hm_f_sh(char *key, void *value, const size_t value_len)
{
  return (get_hashmap_element(key, my_strlen(key), value, value_len));
}