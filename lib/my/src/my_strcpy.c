/*
** my_strcpy.c for libmy in /home/benji_epitech/System_Unix/PSU_2016_minishell1
** 
** Made by Benjamin Viguier
** Login   <benjamin.viguier@epitech.eu>
** 
** Started on  Thu Jan 19 14:02:19 2017 Benjamin Viguier
** Last update Sat Oct 14 16:42:49 2017 Benjamin Viguier
*/

char *my_strcpy(char *dest, char *src)
{
  if (src[0] == '\0')
    dest[0] = '\0';
  else
    {
      my_strcpy(dest + 1, src + 1);
      dest[0] = src[0];
    }
  return (dest);
}

char *my_strncpy(char *dest, char *src, int n)
{
  int	i;

  i = 0;
  while (i < n && (src[i] != '\0'))
    {
      dest[i] = src[i];
      i += 1;
    }
  dest[i] = '\0';
  return (dest);
}