/*
** my_fd_write.c for libmy in /home/benji_epitech/workdir/perso/libmy/tmp/lib/my
** 
** Made by Benjamin Viguier
** Login   <benjamin.viguier@epitech.eu>
** 
** Started on  Thu Feb 23 16:11:05 2017 Benjamin Viguier
** Last update Sat Oct 14 16:55:31 2017 Benjamin Viguier
*/

#include <unistd.h>
#include "internal.h"

int	my_fflush(t_io *io)
{
  if (io->wlen)
  {
    if (write(io->fd, io->wbuf, io->wlen) < 0)
	    return (-1);
    io->wlen = 0;
  }
  return (0);
}

int	__libmy_io_need_flush(t_io *io)
{
  if (!(io->wlen < IO_BUFF_LEN))
    return (my_fflush(io));
  return (0);
}

ssize_t		my_fwrite(t_io *io, void *ptr, size_t size)
{
  char		*str;
  size_t	i;
  int		need_flush;
  
  str = (char*) ptr;
  i = 0;
  need_flush = 0;
  while (i < size)
  {
    if (__libmy_io_need_flush(io) < 0)
    return (-1);
    io->wbuf[io->wlen] = str[i];
    if (io->auto_flush && str[i] == '\n')
    need_flush = 1;
    i++;
    (io->wlen)++;
  }
  if (need_flush)
    return (my_fflush(io));
  return (0);
}

#ifdef ALLOW_LSEEK
off_t	my_io_seek(t_io *io, off_t offset, int whence)
{
  if (my_fflush(io) < 0)
  return (-1);
  return (lseek(io->fd, offset, whence));
}
#endif /* !ALLOW_LSEEK */
