/*
** my_split.c for  in /home/benji_epitech/C_Graph_Prog/wireframe
** 
** Made by Benjamin Viguier
** Login   <benjamin.viguier@epitech.eu>
** 
** Started on  Wed Dec  7 11:25:33 2016 Benjamin Viguier
** Last update Thu Apr 13 16:43:44 2017 Benjamin Viguier
*/

#include "my.h"

static int	count_lines(char *inp, char sep, char **tmp)
{
  int		count;

  count = 1;
  while (*inp && *inp == sep)
    inp++;
  if (!(inp = my_strdup(inp)))
    return (0);
  *tmp = inp;
  if (*inp == '\0')
    return (0);
  while (*inp)
    {
      if (*inp == sep)
	{
	  *inp = '\0';
	  while (*(inp + 1) && *(inp + 1) == sep)
	    inp++;
	  if (*(inp + 1))
	    count++;
	}
      inp++;
    }
  return (count);
}

char	**my_split(char *inp, char sep, int *nb_lines)
{
  char	**res;
  char	*tmp;
  int	i;
  int	lines;

  i = 0;
  lines = count_lines(inp, sep, &tmp);
  res = malloc(sizeof(char*) * (lines + 1));
  if (!res || !tmp)
    return (NULL);
  if (nb_lines)
    *nb_lines = lines;
  while (i < lines)
    {
      res[i++] = tmp;
      if (!(i < lines))
	break;
      while (*tmp != '\0')
	tmp++;
      tmp++;
      while (*tmp == sep)
	tmp++;
    }
  res[i] = NULL;
  return (res);
}
