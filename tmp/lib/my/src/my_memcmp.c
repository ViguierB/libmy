/*
** my_memcmp.c for libmy.c in /home/benji_epitech/System_Unix/PSU_2016_navy
** 
** Made by Benjamin Viguier
** Login   <benjamin.viguier@epitech.eu>
** 
** Started on  Mon Jan 30 12:30:05 2017 Benjamin Viguier
** Last update Fri May 12 16:58:34 2017 Benjamin Viguier
*/

#include <unistd.h>
#include "macro.h"

static int	my_mini_memcmp(void *ptr1, void *ptr2, size_t len)
{
  unsigned char	*cptr1;
  unsigned char	*cptr2;
  size_t	i;

  cptr1 = ptr1;
  cptr2 = ptr2;
  i = 0;
  while ((i < len) && (*cptr1 == *cptr2))
    {
      cptr1++;
      cptr2++;
      i++;
    }
  if (i == len)
    {
      cptr1--;
      cptr2--;
    }
  if (*cptr1 < *cptr2)
    return (-1);
  else if (*cptr1 > *cptr2)
    return (1);
  else
    return (0);
}

int	my_memcmp(void *sptr, void *ssptr, size_t size)
{
  LMY_WORD	*ls;
  LMY_WORD	*lss;

  ls = sptr;
  lss = ssptr;
  while (size > sizeof(LMY_WORD) &&
	 *ls == *lss)
    {
      ls++;
      lss++;
      size -= sizeof(LMY_WORD);
    }
  return (my_mini_memcmp(ls, lss, size));
}
