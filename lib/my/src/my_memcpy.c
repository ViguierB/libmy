/*
** my_memcpy.c for libmy in /home/benji_epitech/C_Graph_Prog/wolf3d/bonus/src
** 
** Made by Benjamin Viguier
** Login   <benjamin.viguier@epitech.eu>
** 
** Started on  Fri Jan 20 13:13:17 2017 Benjamin Viguier
** Last update Fri May 12 16:46:40 2017 Benjamin Viguier
*/

#include <unistd.h>
#include "macro.h"

void		*my_memcpy(void *dptr, void *fptr, size_t size)
{
  char		*dest;
  char		*from;
  LMY_WORD	*ldest;
  LMY_WORD	*lfrom;

  lfrom = fptr;
  ldest = dptr;
  while (size >= sizeof(LMY_WORD))
    {
      *(ldest++) = *(lfrom++);
      size -= sizeof(LMY_WORD);
    }
  dest = (char*) ldest;
  from = (char*) lfrom;
  while (size--)
    *(dest++) = *(from++);
  return (dptr);
}
