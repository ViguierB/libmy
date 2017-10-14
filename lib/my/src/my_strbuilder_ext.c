/*
** my_strbuilder_ext.c for libmy in /home/benji_epitech/workdir/perso/libmy/tmp/lib/my/src
** 
** Made by Benjamin Viguier
** Login   <benjamin.viguier@epitech.eu>
** 
** Started on  Thu Feb 23 14:58:19 2017 Benjamin Viguier
** Last update Sat Oct 14 16:51:29 2017 Benjamin Viguier
*/

#include "libmy.h"
#include "internal.h"

int	__libmy_sb_flush(t_strbuilder *sb)
{
  char		*res;
  size_t	i;
  size_t	j;

  res = malloc(sizeof(char) * (sb->res_len + sb->len + 1));
  if (!res)
    return (-1);
  my_memcpy(res, sb->res, sb->pos);
  i = sb->pos;
  j = 0;
  while (j < sb->len)
    {
      res[i] = sb->buf[j];
      j++;
      i++;
    }
  my_memcpy(res + i - 1, sb->res + sb->pos, sb->res_len - sb->pos);
  sb->res_len = sb->res_len + sb->len;
  sb->pos += j;
  sb->len = 0;
  res[sb->res_len + sb->len] = '\0';
  free(sb->res);
  sb->res = res;
  return (0);
}

int	__libmy_sb_need_flush(t_strbuilder *sb)
{
  if (!(sb->len < IO_BUFF_LEN))
    {
      return (__libmy_sb_flush(sb));
    }
  return (0);
}
