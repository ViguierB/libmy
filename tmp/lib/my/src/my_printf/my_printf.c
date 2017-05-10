/*
** my_printf.c for libmy in /home/benji_epitech/workdir/perso/libmy/tmp/lib/my
** 
** Made by Benjamin Viguier
** Login   <benjamin.viguier@epitech.eu>
** 
** Started on  Thu Feb 23 16:01:16 2017 Benjamin Viguier
** Last update Wed May 10 20:55:17 2017 Benjamin Viguier
*/

#include "internal.h"

int	__libmy_printf(t_pf_data *data)
{
  t_pf_prm	cur;
  int		fres;

  while (*(data->fmt))
    {
      if (*(data->fmt) == '%')
	{
	  (data->fmt)++;
	  if ((fres = __pf_get_flags(data, &cur)) < 0)
	    return (fres);
	  if ((fres = __pf_format(data, &cur)) < 0)
	    return (fres);
	}
      else
	{
	  if ((fres = __pf_putchar(data, *(data->fmt))) < 0)
	    return (fres);
	  (data->fmt)++;
	}
    }
  return (0);
}

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
  t_pf_data	data;
  int		res;

  my_memset(&data, 0, sizeof(data));
  if (!(data.sb = my_sb_init()))
    return (-1);
  data.fmt = fmt;
  data.fd = my_fdin;
  va_start(data.va, fmt);
  res = __libmy_printf(&data);
  va_end(data.va);
  free(data.sb->res);
  free(data.sb);
  if (res < 0)
    return (res);
  return (0);
}

int		my_fprintf(t_my_fd *fd, char *fmt, ...)
{
  t_pf_data	data;
  int		res;

  my_memset(&data, 0, sizeof(data));
  if (!(data.sb = my_sb_init()))
    return (-1);
  data.fd = fd;
  data.fmt = fmt;
  va_start(data.va, fmt);
  res = __libmy_printf(&data);
  va_end(data.va);
  free(data.sb->res);
  free(data.sb);
  if (res < 0)
    return (res);
  return (0);
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
