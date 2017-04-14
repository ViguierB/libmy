/*
** my_garbage.c for libmy in /home/benji_epitech/workdir/perso/libmy/tmp/lib/my/src
** 
** Made by Benjamin Viguier
** Login   <benjamin.viguier@epitech.eu>
** 
** Started on  Mon Apr 10 13:07:50 2017 Benjamin Viguier
** Last update Fri Apr 14 18:53:46 2017 Benjamin Viguier
*/

#include <stdlib.h>
#include "internal.h"
#include "libmy.h"

t_clist			**__libmy_basic_grabage(void)
{
  static t_clist	*list;

  return (&list);
}

void		*my_gcmalloc(t_clist **list, size_t size)
{
  void		*res;
  t_mem_header	head;

  if (!(res = malloc(size + sizeof(t_mem_header))))
    return (NULL);
  if (list)
    {
      *list = clist_push(*list, res);
      head.node = list->prev;
    }
  else
    head.node = NULL;
  head.len = size;
  head.magic = GC_MAGIC;
  head.magic = (int) murmur3_32((void*) &head, sizeof(t_mem_header), 0);
  my_memcpy(res, &head, sizeof(t_mem_header));
  return (res + sizeof(t_mem_header));
}

void		*my_malloc(size_t size)
{
  t_clist	**list;

  list = __libmy_basic_grabage();
  return (my_gcmalloc(list, size));
}

int	my_gcfree(t_clist **list, void *ptr)
{
  t_mem_header	head;
  int		magic;

  ptr -= sizeof(t_mem_header);
  my_memcpy(&head, ptr, sizeof(t_mem_header));
  magic = head.magic;
  head.magic = GC_MAGIC;
  if (magic != head.magic)
    return (-1);
  if (head.node != NULL)
    {

    }
  free(ptr);
  return (0);
}
