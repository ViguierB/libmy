/*
** my_memset.c for libmy in /home/benji_epitech/System_Unix/PSU_2016_navy
** 
** Made by Benjamin Viguier
** Login   <benjamin.viguier@epitech.eu>
** 
** Started on  Mon Jan 30 11:36:38 2017 Benjamin Viguier
** Last update Fri May 12 14:09:21 2017 Benjamin Viguier
*/

#include <stdio.h>

#include <unistd.h>
#include "macro.h"

void		my_memset(void *ptr, int c, size_t size)
{
  LMY_WORD	cccc;
  LMY_WORD	*wptr;

  c = (char) c;
  if (size >= sizeof(LMY_WORD))
    {
      wptr = ptr;
      cccc = MEM_CLONE((LMY_WORD) c);
      while (size >= sizeof(LMY_WORD))
	{
	  *(wptr++) = cccc;
	  size -= sizeof(LMY_WORD);
	}
      ptr = wptr;
    }
  while (size--)
    *((char*) ptr++) = (char) c;
}
