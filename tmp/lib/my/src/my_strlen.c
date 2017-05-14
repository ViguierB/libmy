/*
** my_strlen.c for libmy in /home/benji_epitech/System_Unix/PSU_2016_minishell1
** 
** Made by Benjamin Viguier
** Login   <benjamin.viguier@epitech.eu>
** 
** Started on  Thu Jan 19 14:02:45 2017 Benjamin Viguier
** Last update Sun May 14 13:35:03 2017 Benjamin Viguier
*/

#include <unistd.h>
#include "internal.h"
#include "macro.h"

static ssize_t	__libmy_get_bz(const unsigned long *longword_ptr,
			       char *str, unsigned long longword)
{
  const char	*cp = (const char *) (longword_ptr - 1);

  if (cp[0] == 0)
    return (cp - str);
  if (cp[1] == 0)
    return (cp - str + 1);
  if (cp[2] == 0)
    return (cp - str + 2);
  if (cp[3] == 0)
    return (cp - str + 3);
  if (sizeof(longword) > 4)
    {
      if (cp[4] == 0)
	return (cp - str + 4);
      if (cp[5] == 0)
	return (cp - str + 5);
      if (cp[6] == 0)
	return (cp - str + 6);
      if (cp[7] == 0)
	return (cp - str + 7);
    }
  return (-1);
}

static size_t	__libmy_ending_strlen(char *str,
				      const unsigned long *longword_ptr,
				      unsigned long longword,
				      t_strlen_magic magic)
{
  ssize_t	res;

  while (1)
    {
      longword = *(longword_ptr++);
      if (((longword - magic.lo) & ~longword & magic.hi) != 0)
	if ((res = __libmy_get_bz(longword_ptr, str, longword)) >= 0)
	  return ((size_t) res);
    }
}

size_t			my_strlen(char *str)
{
  const char		*char_ptr;
  const unsigned long	*longword_ptr;
  unsigned long		longword;
  t_strlen_magic	magic;

  char_ptr = str;
  while (((unsigned long int) char_ptr
	  & (sizeof(longword) - 1)) != 0)
    {
      if (*char_ptr == '\0')
	return (char_ptr - str);
      ++char_ptr;
    }
  longword_ptr = (unsigned long int *) char_ptr;
  magic.hi = 0x80808080L;
  magic.lo = 0x01010101L;
  if (sizeof(longword) > 4)
    {
      magic.hi = (magic.hi << 32) | magic.hi;
      magic.lo = (magic.lo << 32) | magic.lo;
    }
  if (sizeof(longword) > 8)
    return (0);
  return (__libmy_ending_strlen(str, longword_ptr, longword, magic));
}
