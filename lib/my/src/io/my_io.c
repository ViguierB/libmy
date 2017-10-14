/*
** my_fd.c for libmy in /home/benji_epitech/C_Graph_Prog/wolf3d/lib/my
** 
** Made by Benjamin Viguier
** Login   <benjamin.viguier@epitech.eu>
** 
** Started on  Thu Dec 22 16:23:15 2016 Benjamin Viguier
** Last update Sat Oct 14 16:50:43 2017 Benjamin Viguier
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdarg.h>
#include "internal.h"

#ifdef ALLOW_OPEN
t_io		*my_fopen(char *path, int flags, ...)
{
  t_io	*res;
  va_list	va;
  mode_t	mode;

  res = malloc(sizeof(t_io));
  if (!res)
    return (NULL);
  my_memset(res, 0, sizeof(t_io));
  if (flags & O_CREAT)
    {
      va_start(va, flags);
      mode = va_arg(va, int);
      res->fd = open(path, flags, mode);
    }
  else
    res->fd = open(path, flags);
  if (res->fd < 0)
    return (NULL);
  return (res);
}

void	my_fclose(t_io *to_free)
{
  if (to_free)
    {
      if (to_free->wlen)
        my_fflush(to_free);
      close(to_free->fd);
      free(to_free);
    }
}
#endif /* !ALLOW_OPEN */

t_io		*my_io_from_fd(const int fd)
{
  t_io	*res;

  res = malloc(sizeof(t_io));
  if (!res)
    return (NULL);
  my_memset(res, 0, sizeof(t_io));
  res->fd = fd;
  if (res->fd < 0)
    return (NULL);
  return (res);
}
