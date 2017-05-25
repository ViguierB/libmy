/*
** pf_write.c for libmy in /home/benji_epitech/workdir/perso/libmy/tmp/lib/my
** 
** Made by Benjamin Viguier
** Login   <benjamin.viguier@epitech.eu>
** 
** Started on  Fri Feb 24 10:51:48 2017 Benjamin Viguier
** Last update Sat May 20 19:52:20 2017 Benjamin Viguier
*/

#include "internal.h"

int	__pf_flush(t_pf_data *data)
{
  if (data->is_strbuffer)
    {
      return (__libmy_sb_flush(data->sb));
    }
  else
    {
      return (my_fflush(data->fd));
    }
}

int	__pf_write(t_pf_data *data, void *ptr, size_t size)
{
  data->pos += size;
  if (data->is_strbuffer)
    {
      return (my_sb_write(data->sb, ptr, size));
    }
  else
    {
      return (my_fwrite(data->fd, ptr, size));
    }
}

int	__pf_putchar(t_pf_data *data, char c)
{
  (data->pos)++;
  if (data->is_strbuffer)
    {
      return (my_sb_write(data->sb, &c, 1));
    }
  else
    {
      return (my_fwrite(data->fd, &c, 1));
    }
}
