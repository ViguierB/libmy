/*
** my_fd.c for libmy in /home/benji_epitech/C_Graph_Prog/wolf3d/lib/my
** 
** Made by Benjamin Viguier
** Login   <benjamin.viguier@epitech.eu>
** 
** Started on  Thu Dec 22 16:23:15 2016 Benjamin Viguier
** Last update Fri Mar  3 13:53:24 2017 Benjamin Viguier
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdarg.h>
#include "internal.h"

#ifdef ALLOW_OPEN
t_my_fd		*my_fopen(char *path, int flags, ...)
{
  t_my_fd	*res;
  va_list	va;
  mode_t	mode;

  res = malloc(sizeof(t_my_fd));
  if (!res)
    return (NULL);
  my_memset(res, 0, sizeof(t_my_fd));
  if (flags & O_CREAT)
    {
      va_start(va, flags);
      mode = va_arg(va, mode_t);
      res->fd = open(path, flags, mode);
    }
  else
    res->fd = open(path, flags);
  if (res->fd < 0)
    return (NULL);
  return (res);
}

void	my_fclose(t_my_fd *to_free)
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

t_my_fd		*my_fd_from_fd(const int fd)
{
  t_my_fd	*res;

  res = malloc(sizeof(t_my_fd));
  if (!res)
    return (NULL);
  my_memset(res, 0, sizeof(t_my_fd));
  res->fd = fd;
  if (res->fd < 0)
    return (NULL);
  return (res);
}
