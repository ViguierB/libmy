/*
** my_strbuilder.c for libmy in /home/benji_epitech/workdir/perso/libmy/tmp/lib/my/src
** 
** Made by Benjamin Viguier
** Login   <benjamin.viguier@epitech.eu>
** 
** Started on  Thu Feb 23 12:20:16 2017 Benjamin Viguier
** Last update Thu Feb 23 16:47:25 2017 Benjamin Viguier
*/

#include "libmy.h"
#include "internal.h"

t_strbuilder	*my_sb_init(void)
{
  t_strbuilder	*builder;

  if ((builder = malloc(sizeof(t_strbuilder))) == NULL)
    return (NULL);
  my_memset(builder, 0, sizeof(t_strbuilder));
  if ((builder->res = malloc(sizeof(char))) == NULL)
    return (0);
  *(builder->res) = '\0';
  return (builder);
}

char	*my_sb_get_str(t_strbuilder *sb)
{
  char	*res;
  
  if (__libmy_sb_flush(sb) < 0)
    return (NULL);
  res = sb->res;
  free(sb);
  return (res);
}

int		my_sb_write(t_strbuilder *sb, void *ptr, size_t size)
{
  char		*str;
  size_t	i;

  str = (char*) ptr;
  i = 0;
  while (i < size)
    {
      if (__libmy_sb_need_flush(sb) < 0)
	return (-1);
      sb->buf[sb->len] = str[i];
      i++;
      (sb->len)++;
    }
  return (0);
}

off_t	my_sb_seek(t_strbuilder *sb, off_t offset, int whence)
{ 
  if (__libmy_sb_flush(sb) < 0)
    return (-1);
  if (whence == SBW_BEGIN)
    sb->pos = 0;
  else if (whence == SBW_END)
    sb->pos = sb->res_len;
  sb->pos += offset;
  return (sb->pos);
}
