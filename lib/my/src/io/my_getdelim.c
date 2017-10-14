/*
** my_getline.c for libmy in /home/benji_epitech/C_Graph_Prog/wolf3d/lib/my
** 
** Made by Benjamin Viguier
** Login   <benjamin.viguier@epitech.eu>
** 
** Started on  Thu Dec 22 12:46:31 2016 Benjamin Viguier
** Last update Sat Oct 14 16:47:10 2017 Benjamin Viguier
*/

#include <unistd.h>
#include <stdlib.h>
#include "libmy.h"

static int	init_values(t_io *pack, int *on_nl)
{
  int		i;
  char		delim;

  i = pack->rest;
  delim = *on_nl;
  while (pack->buf[i] != delim && i < pack->len)
    i++;
  if (pack->buf[i] == delim)
    {
      *on_nl = 0;
      i += 1;
    }
  return (i);
}

static char	*copy_now(t_io *pack, int cur_len,
			  char *res, int new_len)
{
  int		j;
  int		k;
  char		*new_str;

  new_str = malloc(sizeof(char) * (new_len));
  if (!new_str)
    return (NULL);
  j = 0;
  k = pack->rest;
  while (j < new_len - 1)
    {
      if (j < cur_len)
	new_str[j] = res[j];
      else
	{
	  new_str[j] = pack->buf[k];
	  k += 1;
	}
      j += 1;
    }
  new_str[j] = '\0';
  return (new_str);
}

static int	cpy_to_delim(char **res, t_io *pack,
			     int *cur_len, int *on_nl)
{
  char		*new_str;
  int		new_len;
  int		i;

  i = init_values(pack, on_nl);
  new_len = *cur_len + (i - pack->rest) + 1 - (*on_nl != 0);
  new_str = copy_now(pack, *cur_len, *res, new_len);
  if (!new_str)
    return (-1);
  pack->rest = i;
  if (*res)
    free(*res);
  *cur_len = new_len - 1;
  *res = new_str;
  if (i == pack->len)
    {
      pack->len = 0;
      pack->rest = 0;
    }
  return (0);
}

char	*my_getdelim(t_io *pack, char delim)
{
  char	*res;
  int	cur_len;
  int	on_nl;

  res = NULL;
  cur_len = 0;
  on_nl = delim;
  if (pack->rest != pack->len)
    if (cpy_to_delim(&res, pack, &cur_len, &on_nl) < 0)
      return (NULL);
  while (on_nl)
    {
      pack->len = read(pack->fd, pack->buf, IO_BUFF_LEN);
      if (pack->len == 0)
	return (res);
      else if (pack->len < 0)
	return (NULL);
      if (cpy_to_delim(&res, pack, &cur_len, &on_nl) < 0)
	return (NULL);
    }
  return (res);
}
