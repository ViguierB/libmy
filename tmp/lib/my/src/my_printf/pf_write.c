/*
** pf_write.c for libmy in /home/benji_epitech/workdir/perso/libmy/tmp/lib/my
** 
** Made by Benjamin Viguier
** Login   <benjamin.viguier@epitech.eu>
** 
** Started on  Fri Feb 24 10:51:48 2017 Benjamin Viguier
** Last update Fri Feb 24 11:37:05 2017 Benjamin Viguier
*/

#incude "internal.h"

void	__pf_flush(t_pf_data *data)
{
  if (data->is_strbuffer)
    {
      my_sb_flush(data->sb);
    }
  else
    {
      my_fflush(data->fd);
    }
}

void	__pf_putchar(t_pf_data *data, char c)
{
  (data->pos)++;
  if (data->is_strbuffer)
    {
      my_sb_write(data->sb, &c, 1);
    }
  else
    {
      my_fwrite(data->fd, &c, 1);
    }
}
