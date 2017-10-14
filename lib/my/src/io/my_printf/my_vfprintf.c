/*
** my_vfprintf.c for libmy in /home/benji_epitech/workdir/perso/libmy/lib/my
** 
** Made by Benjamin Viguier
** Login   <benjamin.viguier@epitech.eu>
** 
** Started on  Fri Jun  2 21:33:37 2017 Benjamin Viguier
** Last update Sat Oct 14 16:33:12 2017 Benjamin Viguier
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

int		my_vfprintf(t_io *io_buffer, char *fmt, va_list va)
{
  t_pf_data	data;
  int		res;

  my_memset(&data, 0, sizeof(data));
  data.io_buf = io_buffer;
  data.fmt = fmt;
  *(data.va) = *va;
  res = __libmy_printf(&data);
  if (res < 0)
    return (res);
  return (0);
}
