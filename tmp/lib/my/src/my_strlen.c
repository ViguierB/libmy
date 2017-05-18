/*
** my_strlen.c for libmy in /home/benji_epitech/System_Unix/PSU_2016_minishell1
** 
** Made by Benjamin Viguier
** Login   <benjamin.viguier@epitech.eu>
** 
** Started on  Thu Jan 19 14:02:45 2017 Benjamin Viguier
** Last update Thu May 18 14:41:59 2017 Benjamin Viguier
*/

#include <sys/types.h>
#include <stdint.h>
#include <unistd.h>
#include "internal.h"
#include "macro.h"

#ifdef LMY_WORDSIZE_32
static const unsigned long	g_mask01 = 0x01010101;
static const unsigned long	g_mask80 = 0x80808080;
#else
# ifdef LMY_WORDSIZE_64
static const unsigned long	g_mask01 = 0x0101010101010101;
static const unsigned long	g_mask80 = 0x8080808080808080;
# else
#error Unsupported word size
# endif
#endif

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
      if ((*lp - g_mask01) & g_mask80)
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
