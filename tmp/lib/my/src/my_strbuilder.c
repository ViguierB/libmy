/*
** my_strmaker.c for libmy in /home/benji_epitech/workdir/perso/libmy/tmp/lib/my/src
** 
** Made by Benjamin Viguier
** Login   <benjamin.viguier@epitech.eu>
** 
** Started on  Thu Feb 23 12:20:16 2017 Benjamin Viguier
** Last update Thu Feb 23 12:42:07 2017 Benjamin Viguier
*/

#include "libmy.h"

t_strbuilder	*my_sb_init(void)
{
  t_strbuider	*builder;

  if ((builder = malloc(sizeof(t_strbuilder))) == NULL)
    return (NULL);
  my_memset(builder, 0, sizeof(t_strbuilder));
  if ((builder->res = malloc(sizeof(char))) == NULL)
    return (0);
  *(builder->res) = '\0';
  return (builder);
}

static int	__libmy_bs_flush(t_strbuilder *sb)
{
  char		*res;
  int		i;
  int		j;

  res = malloc(sizeof(char) * (sb->res_len + sb->len + 1));
  if (!res)
    return (-1);
  my_memcpy(res, sb->res, sb->res_len);
  i = sb->res_len;
  sb->res_len += sb->len;
  sb->len = 0;
  j = 0;
  while (i < sf->res_len)
    {
      res[i] = sb->buf[j];
      i++;
      j++;
    }
  res[i] = '\0';
  free(sb->res);
  sb->res = res;
  return (0);
}

char	*my_sb_get_str(t_strbuilder *sb)
{
  char	*res;
  
  if (__libmy_bs_flush(sb) < 0)
    return (NULL);
  res = sb->res;
  free(sb);
  return (res);
}

static int	__libmy_sb_need_flush(t_strbuilder *sb)
{
  if (!(sb->len < MY_FD_BUFF_LEN))
    {
      return (__libmy_bs_flush(sb));
    }
  return (0);
}

int		my_sb_write(t_strbuilder *sb, void *ptr, size_t size)
{
  char		*str;
  size_t	i;

  str = (char*) ptr;
  i = 0;
  while (i < size)
    {
      if (__lib_my_need_flush(sb) < 0)
	return (-1);
      sb->buf[sb->len] = ptr[i];
      i++;
      (sb->len)++;
    }
  return (0);
}
