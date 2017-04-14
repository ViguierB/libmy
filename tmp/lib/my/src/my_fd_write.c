/*
** my_fd_write.c for libmy in /home/benji_epitech/workdir/perso/libmy/tmp/lib/my
** 
** Made by Benjamin Viguier
** Login   <benjamin.viguier@epitech.eu>
** 
** Started on  Thu Feb 23 16:11:05 2017 Benjamin Viguier
** Last update Fri Apr 14 18:53:10 2017 Benjamin Viguier
*/

#include <unistd.h>
#include "internal.h"

int	my_fflush(t_my_fd *fd)
{
  if (fd->wlen)
    {
      if (write(fd->fd, fd->wbuf, fd->wlen) < 0)
	return (-1);
      fd->wlen = 0;
    }
  return (0);
}

int	__libmy_fd_need_flush(t_my_fd *fd)
{
  if (!(fd->wlen < MY_FD_BUFF_LEN))
    return (my_fflush(fd));
  return (0);
}

ssize_t	my_fwrite(t_my_fd *fd, void *ptr, size_t size)
{
  char		*str;
  size_t	i;

  str = (char*) ptr;
  i = 0;
  while (i < size)
    {
      if (__libmy_fd_need_flush(fd) < 0)
	return (-1);
      fd->wbuf[fd->wlen] = str[i];
      i++;
      (fd->wlen)++;
    }
  return (0);
}

#ifdef ALLOW_LSEEK
off_t	my_fd_seek(t_my_fd *fd, off_t offset, int whence)
{
  if (my_fflush(fd) < 0)
    return (-1);
  return (lseek(fd->fd, offset, whence));
}
#endif /* !ALLOW_LSEEK */
