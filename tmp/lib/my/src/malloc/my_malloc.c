/*
** my_malloc.c for libmy in /home/benji_epitech/workdir/perso/libmy/tmp/lib/my/src/malloc
** 
** Made by Benjamin Viguier
** Login   <benjamin.viguier@epitech.eu>
** 
** Started on  Wed Apr 26 14:35:54 2017 Benjamin Viguier
** Last update Wed Apr 26 17:14:54 2017 Benjamin Viguier
*/

#include <unistd.h>
#include <stdlib.h>
#include "internal_malloc.h"
#include "libmy.h"

void	*my_malloc(size_t len)
{
  void*	res;

  if (!(res = malloc(len + sizeof(t_mem_header))))
    return (NULL);
  __libmy_create_header(res, len);
  return (res + sizeof(t_mem_header));
}

int	my_free(void *ptr)
{
  if (!(ptr = __libmy_verif_ptr(ptr)))
    return (-1);
  __libmy_remove_header(ptr);
  free(ptr);
  return (0);
}

void		*my_realloc(void *old, size_t len)
{
  void		*res;
  t_mem_header	*header;

  if (!(header = __libmy_verif_ptr(old)))
    return (NULL);
  else
    {
      res = my_malloc(len);
      my_memcpy(res, old, MIN(header->data.len, len));
      my_free(old);
      return (res);
    }
}
