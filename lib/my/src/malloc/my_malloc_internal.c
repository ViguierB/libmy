/*
** my_malloc_internal.c for libmy in /home/benji_epitech/workdir/perso/libmy/tmp/lib/my/src/malloc
** 
** Made by Benjamin Viguier
** Login   <benjamin.viguier@epitech.eu>
** 
** Started on  Wed Apr 26 15:06:48 2017 Benjamin Viguier
** Last update Wed Apr 26 18:02:25 2017 Benjamin Viguier
*/

#include <stdlib.h>
#include "libmy_hash.h"
#include "internal_malloc.h"

static t_mem_header	*memory_grb = NULL;

void		__libmy_create_header(t_mem_header *res, size_t len)
{
  res->next = NULL;
  if (memory_grb)
    {
      memory_grb->next = res;
      res->prev = memory_grb;
    }
  else
    res->prev = NULL;
  memory_grb = res;
  res->data.magic = MLC_MAGIC;
  res->data.len = len;
  res->data.magic  = murmur3_32(&(res->data), sizeof(t_mem_header_data), 0);
}

void		__libmy_remove_header(t_mem_header *ptr)
{
  if (memory_grb == ptr)
    memory_grb = ptr->prev;
  if (ptr->next)
    ptr->next->prev = ptr->prev;
  if (ptr->prev)
    ptr->prev->next = ptr->next;
}

void		*__libmy_verif_ptr(void *tptr)
{
  t_mem_header	*ptr;
  uint32_t	magic;

  ptr = tptr;
  ptr--;
  magic = ptr->data.magic;
  ptr->data.magic = MLC_MAGIC;
  ptr->data.magic  = murmur3_32(&(ptr->data), sizeof(t_mem_header_data), 0);
  if (ptr->data.magic == magic)
    return (ptr);
  return (NULL);
}

void		free_all(void)
{
  t_mem_header	*next;
  void		*to_free;

  next = memory_grb;
  while (next)
    {
      to_free = next;
      next = next->next;
      free(to_free);
    }
  memory_grb = NULL;
}
