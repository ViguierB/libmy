/*
** my_printf.c for libmy in /home/benji_epitech/workdir/perso/libmy/tmp/lib/my
** 
** Made by Benjamin Viguier
** Login   <benjamin.viguier@epitech.eu>
** 
** Started on  Thu Feb 23 16:01:16 2017 Benjamin Viguier
** Last update Thu Feb 23 18:26:41 2017 Benjamin Viguier
*/

#include "internal.h"

int		__libmy_printf(t_pf_data *data)
{
  
}

int		my_printf(char *fmt, ...)
{
  t_pf_data	data;
  int		res;

  my_memset(&data, 0, sizeof(data));
  if (!(data->strbuilder = my_sb_init()))
    return (-1);
  data.fd = my_fdin();
  va_start(data->va, fmt);
  res = __libmy_printf(&data);
  va_end(data->va);
  if (res < 0)
    return (res);
  return (0);
}

int		my_fprintf(t_my_fd *fd, char *fmt, ...)
{
  t_pf_data	data;
  int		res;

  my_memset(&data, 0, sizeof(data));
  if (!(data->strbuilder = my_sb_init()))
    return (-1);
  data.fd = fd;
  va_start(data->va, fmt);
  res = __libmy_printf(&data);
  va_end(data->va);
  if (res < 0)
    return (res);
  return (0);
}

char		*my_sprintf(char *fmt, ...)
{
  t_pf_data	data;
  int		res;

  my_memset(&data, 0, sizeof(data));
  if (!(data->strbuilder = my_sb_init()))
    return (NULL);
  data.is_strbuffer = 1;
  va_start(data->va, fmt);
  res = __libmy_printf(&data);
  va_end(data->va);
  if (res < 0)
    return (NULL);
  return (my_sb_get_str(data.strbuilder));
}
