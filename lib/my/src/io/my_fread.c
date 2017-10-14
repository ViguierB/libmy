/*
** my_fread.c for libmy.c in /home/benji_epitech/System_Unix/PSU_2016_bstetris
** 
** Made by Benjamin Viguier
** Login   <benjamin.viguier@epitech.eu>
** 
** Started on  Tue Feb 21 09:59:48 2017 Benjamin Viguier
** Last update Sat Oct 14 16:46:58 2017 Benjamin Viguier
*/

#include <unistd.h>
#include <stdlib.h>
#include "libmy.h"

static char	*__libmy_cat_buf(char *inp, size_t cur_size,
				 char *buf, size_t b_len)
{
  char		*res;
  t_uint	i;

  res = malloc(sizeof(char) * (b_len + cur_size + 1));
  if (!res)
    return (NULL);
  i = 0;
  my_strncpy(res, inp, cur_size);
  while (i < b_len)
    {
      res[i + cur_size] = buf[i];
      i += 1;
    }
  if (inp)
    free(inp);
  return (res);
}

static void	__libmy_flush_io(t_io *pack, char *buffer,
				 size_t *idx, size_t size)
{
  while (pack->rest != pack->len && *idx < size)
    {
      buffer[*idx] = pack->buf[pack->rest];
      (pack->rest)++;
      (*idx)++;
    }
  if (pack->rest == pack->len)
    {
      pack->len = 0;
      pack->rest = 0;
    }
}

ssize_t		my_fread(t_io *pack, char *buffer, size_t size)
{
  size_t	idx;

  idx = 0;
  if (pack->rest != pack->len)
    __libmy_flush_io(pack, buffer, &idx, size);
  while (idx < size)
    {
      pack->len = read(pack->fd, pack->buf, IO_BUFF_LEN);
      if (pack->len == 0)
	return ((ssize_t) idx);
      else if (pack->len < 0)
	return (-1);
      __libmy_flush_io(pack, buffer, &idx, size);
    }
  return ((ssize_t) idx);
}

int		my_fread_to_end(t_io *io, char **res)
{
  char		buffer[IO_BUFF_LEN];
  ssize_t	len;
  size_t	cur_len;

  cur_len = 0;
  *res = NULL;
  len = my_fread(io, buffer, IO_BUFF_LEN);
  while (len)
    {
      *res = __libmy_cat_buf(*res, cur_len, buffer, (size_t) len);
      if (!(*res))
	return (-1);
      cur_len += (size_t) len;
      len = my_fread(io, buffer, IO_BUFF_LEN);
    }
  if (cur_len == 0)
    return (0);
  (*res)[cur_len] = '\0';
  return (cur_len);
}
