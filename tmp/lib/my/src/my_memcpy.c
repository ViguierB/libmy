/*
** my_memcpy.c for libmy in /home/benji_epitech/C_Graph_Prog/wolf3d/bonus/src
** 
** Made by Benjamin Viguier
** Login   <benjamin.viguier@epitech.eu>
** 
** Started on  Fri Jan 20 13:13:17 2017 Benjamin Viguier
** Last update Sun Mar 26 16:35:35 2017 Benjamin Viguier
*/

#include <unistd.h>
#include <libmy.h>

static void*	__libmy_memcpy_s(void *dptr, void *fptr, size_t size)
{
  short		*dest;
  short		*from;
  size_t	i;

  dest = (short*) dptr;
  from = (short*) fptr;
  i = 0;
  while (i < size)
    {
      *(dest++) = *(from++);
      i += sizeof(short);
    }
  return (dptr);
}

static void*	__libmy_memcpy_i(void *dptr, void *fptr, size_t size)
{
  int		*dest;
  int		*from;
  size_t	i;

  dest = (int*) dptr;
  from = (int*) fptr;
  i = 0;
  while (i < size)
    {
      *(dest++) = *(from++);
      i += sizeof(int);
    }
  return (dptr);
}

static void*	__libmy_memcpy_l(void *dptr, void *fptr, size_t size)
{
  long int	*dest;
  long int	*from;
  size_t	i;

  dest = (long int*) dptr;
  from = (long int*) fptr;
  i = 0;
  while (i < size)
    {
      *(dest++) = *(from++);
      i += sizeof(long int);
    }
  return (dptr);
}

static void*	__libmy_memcpy_ll(void *dptr, void *fptr, size_t size)
{
  long long int	*dest;
  long long int	*from;
  size_t	i;

  dest = (long long int*) dptr;
  from = (long long int*) fptr;
  i = 0;
  while (i < size)
    {
      *(dest++) = *(from++);
      i += sizeof(long long int);
    }
  return (dptr);
}

void		*my_memcpy(void *dptr, void *fptr, size_t size)
{
  char		*dest;
  char		*from;
  size_t	i;

  if (!(size % sizeof(long long int)))
    return (__libmy_memcpy_ll(dptr, fptr, size));
  if (!(size % sizeof(long int)))
    return (__libmy_memcpy_l(dptr, fptr, size));
  if (!(size % sizeof(int)))
    return (__libmy_memcpy_i(dptr, fptr, size));
  if (!(size % sizeof(short)))
    return (__libmy_memcpy_s(dptr, fptr, size));
  dest = (char*) dptr;
  from = (char*) fptr;
  i = 0;
  while (i < size)
    {
      dest[i] = from[i];
      i++;
    }
  return (dptr);
}
