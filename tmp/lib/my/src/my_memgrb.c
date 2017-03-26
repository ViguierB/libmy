/*
** my_memgrb.c for libmy in /home/benji_epitech/workdir/perso/libmy/tmp/lib/my
** 
** Made by Benjamin Viguier
** Login   <benjamin.viguier@epitech.eu>
** 
** Started on  Sat Mar 25 17:02:50 2017 Benjamin Viguier
** Last update Sun Mar 26 22:12:52 2017 Benjamin Viguier
*/

#include "libmy.h"
#include "hash_table.h"

t_memgrb	*init_grb(size_t hash_table_size)
{
  t_memgrb	*mem;

  if (!hash_table_size)
    hash_table_size = BASIC_HT_SIZE;
  mem = init_ht(hash_table_size, &jenkins_hash_ptr);
  if (!mem)
    return (NULL);
  return (mem);
}

void		*mg_malloc(t_memgrb *memg, size_t size)
{
  void		*res;
  size_t	*ptr;

  res = malloc(size + sizeof(size_t));
  if (!res)
    return (NULL);
  ptr = (size_t*) res;
  *ptr = size;
  res += sizeof(size_t);
  if (set_ht_value((t_ht*) memg, res, res) != SUCCESS)
    return (NULL);
  return (res);
}

void	mg_free(t_memgrb *memg, void *ptr)
{
  if (remove_ht_value((t_ht*) memg, ptr, ptr) == SUCCESS)
    {
      ptr -= sizeof(size_t);
      free(ptr);
    }
}

int		mg_ismalloc(t_memgrb *memg, void *ptr)
{
  t_ht_elm	*elm;

  elm = get_ht_value((t_ht*) memg, ptr);
  return (elm != NULL);
}
