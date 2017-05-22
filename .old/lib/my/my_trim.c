/*
** my_trim.c for libmy in /home/benji_epitech/System_Unix/PSU_2016_my_ls/lib/my
** 
** Made by Benjamin Viguier
** Login   <benjamin.viguier@epitech.eu>
** 
** Started on  Thu Nov 24 14:03:37 2016 Benjamin Viguier
** Last update Thu Nov 24 14:12:52 2016 Benjamin Viguier
*/

#include "my.h"

char	*my_trim(char *str)
{
  char	*res;
  int	first;
  int	last;
  int	i;

  first = 0;
  last = my_strlen(str) - 1;
  while (str[first] == ' ')
    first += 1;
  while (str[last] == ' ')
    last -= 1;
  res = malloc(sizeof(char) * (last - first + 1));
  if (res == NULL)
    return (NULL);
  i = 0;
  while (first < last)
    {
      res[i] = str[first];
      i += 1;
      first += 1;
    }
  res[i] = '\0';
  return (res);
}
