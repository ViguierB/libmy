/*
** my_strconca.c for libmy in /home/benji_epitech/System_Unix/PSU_2016_my_ls
** 
** Made by Benjamin Viguier
** Login   <benjamin.viguier@epitech.eu>
** 
** Started on  Thu Nov 24 15:24:14 2016 Benjamin Viguier
** Last update Sun May 21 01:50:17 2017 Benjamin Viguier
*/

#include <unistd.h>
#include <stdarg.h>
#include "libmy.h"

char	*my_strconca(char *str1, char *str2)
{
  char	*res;
  int	i;
  int	j;

  i = 0;
  j = 0;
  res = malloc(sizeof(char) * (my_strlen(str1) + my_strlen(str2) + 1));
  if (res == NULL)
    return (NULL);
  while (str1[i])
    {
      res[i] = str1[i];
      i += 1;
    }
  while (str2[j])
    {
      res[i] = str2[j];
      i += 1;
      j += 1;
    }
  res[i] = '\0';
  return (res);
}
