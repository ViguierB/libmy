/*
** my_printf.c for libmy in /home/benji_epitech/workdir/perso/libmy/tmp/lib/my
** 
** Made by Benjamin Viguier
** Login   <benjamin.viguier@epitech.eu>
** 
** Started on  Thu Feb 23 16:01:16 2017 Benjamin Viguier
** Last update Sat Oct 14 16:51:10 2017 Benjamin Viguier
*/

#include "internal.h"

int		my_sbprintf(t_strbuilder *sb, char *fmt, ...)
{
  t_pf_data	data;
  int		res;

  my_memset(&data, 0, sizeof(data));
  if (!(data.sb = sb))
    return (-1);
  data.is_strbuffer = 1;
  data.fmt = fmt;
  va_start(data.va, fmt);
  res = __libmy_printf(&data);
  va_end(data.va);
  if (res < 0)
    return (res);
  return (0);
}

int		my_printf(char *fmt, ...)
{
  int		res;
  va_list	va;

  va_start(va, fmt);
  res = my_vfprintf(g_out, fmt, va);
  va_end(va);
  return (res);
}

int		my_dprintf(int fd, char *fmt, ...)
{
  t_pf_data	data;
  int		res;

  my_memset(&data, 0, sizeof(data));
  if (!(data.io_buf = my_io_from_fd(fd)))
    return (-1);
  data.fmt = fmt;
  va_start(data.va, fmt);
  res = __libmy_printf(&data);
  va_end(data.va);
  __pf_flush(&data);
  if (res < 0)
    return (res);
  return (0);
}

int		my_fprintf(t_io *io, char *fmt, ...)
{
  int		res;
  va_list	va;

  va_start(va, fmt);
  res = my_vfprintf(io, fmt, va);
  va_end(va);
  return (res);
}

char		*my_sprintf(char *fmt, ...)
{
  t_pf_data	data;
  int		res;

  my_memset(&data, 0, sizeof(data));
  if (!(data.sb = my_sb_init()))
    return (NULL);
  data.fmt = fmt;
  data.is_strbuffer = 1;
  va_start(data.va, fmt);
  res = __libmy_printf(&data);
  va_end(data.va);
  if (res < 0)
    return (NULL);
  return (my_sb_get_str(data.sb));
}
