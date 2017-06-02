/*
** my_strlen.c for libmy in /home/benji_epitech/System_Unix/PSU_2016_minishell1
** 
** Made by Benjamin Viguier
** Login   <benjamin.viguier@epitech.eu>
** 
** Started on  Thu Jan 19 14:02:45 2017 Benjamin Viguier
** Last update Fri Jun  2 11:05:24 2017 Benjamin Viguier
*/

#include <sys/types.h>
#include <stdint.h>
#include <unistd.h>
#include "internal.h"
#include "macro.h"

size_t	my_basic_strlen(char *str)
{
  char	*ptr;

  ptr = str;
  while (*(ptr))
    ++ptr;
  return (ptr - str);
}

ssize_t		__libmy_strlen_result(const char *str, const char *p)
{
  if (p[0] == '\0')
    return (p - str + 0);
  if (p[1] == '\0')
    return (p - str + 1);
  if (p[2] == '\0')
    return (p - str + 2);
  if (p[3] == '\0')
    return (p - str + 3);
#ifdef LMY_WORDSIZE_64
  if (p[4] == '\0')
    return (p - str + 4);
  if (p[5] == '\0')
    return (p - str + 5);
  if (p[6] == '\0')
    return (p - str + 6);
  if (p[7] == '\0')
    return (p - str + 7);
#endif
  return (-1);
}

size_t			my_strlen(const char *str)
{
  const char		*p;
  const unsigned long	*lp;
  ssize_t		res;

  p = str;
  while ((uintptr_t) p & (sizeof(long) - 1))
    {
      if (*p == '\0')
	return (p - str);
      p++;
    }
  lp = (const unsigned long *) p;
  while (1)
    {
      if ((*lp - MASK01) & MASK80)
	{
	  p = (const char *)(lp);
	  res = __libmy_strlen_result(str, p);
	  if (res >= 0)
	    return ((size_t) res);
	}
      lp++;
    }
  return (0);
}

static const char	*__libmy_ext_strnlen(const char *p, size_t n)
{
  while (n-- && *p)
    p++;
  return (p);
}

size_t			my_strnlen(const char *str, size_t n)
{
  const char	       	*p;
  const unsigned long	*lp;
  ssize_t		res;

  p = str;
  while ((uintptr_t) p & (sizeof(long) - 1))
    {
      if (*p == '\0' || !(n--))
	return (p - str);
      p++;
    }
  lp = (const unsigned long *) p;
  while (n > sizeof(*lp))
    {
      if ((*lp - MASK01) & MASK80)
	{
	  p = (const char *)(lp);
	  res = __libmy_strlen_result(str, p);
	  if (res >= 0)
	    return ((size_t) res);
	}
      lp++;
      n -= sizeof(*lp);
    }
  return (__libmy_ext_strnlen((const char*) lp, n) - str);
}
