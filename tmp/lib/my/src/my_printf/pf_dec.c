/*
** pf_dec.c for libmy in /home/ben/epitech/libmy/tmp/lib/my
** 
** Made by Benjamin Viguier
** Login   <benjamin.viguier@epitech.eu>
** 
** Started on  Sat May 20 21:14:42 2017 Benjamin Viguier
** Last update Sat May 20 21:18:01 2017 Benjamin Viguier
*/

#include "internal.h"

static char	*__pf_int_to_char(char buffer[], size_t len, long long int d)
{
  char		*ptr;

  ptr = buffer + (len - 1);
  *ptr = '\0';
  while (d)
    {
      *(--ptr) = ABS(d % 10) + '0';
      d /= 10;
    }
  return (ptr);
}

int	__pf_dec(t_pf_data *pf, t_pf_prm *fmt) 
{
  char	buffer[50];
  char	*ptr;
  int	local;
  int	len;
  char	to_print;
  

  local = fmt->width - 1;
  if (fmt->myvar.d < 0)
    __pf_putchar(pf, '-');
  else if (fmt->flag & PF_FLAG_ADD)
    __pf_putchar(pf, '+');
  else if (fmt->flag & PF_FLAG_SPACE)
    __pf_putchar(pf, ' ');
  else
    local++;
  ptr = __pf_int_to_char(buffer, sizeof(buffer), fmt->myvar.d);
  len = my_strlen(ptr);
  to_print = ((fmt->flag & PF_FLAG_ZERO) ? '0' : ' ');
  if ((local -= len) > 0)
    while (local--)
      __pf_putchar(pf, to_print);
  __pf_write(pf, ptr, len);
  return (0);
}

static char	*__pf_uint_to_char(char buffer[], size_t len,
				  unsigned long long int d)
{
  char		*ptr;

  ptr = buffer + (len - 1);
  *ptr = '\0';
  while (d)
    {
      *(--ptr) = d % 10 + '0';
      d /= 10;
    }
  return (ptr);
}

int	__pf_udec(t_pf_data *pf, t_pf_prm *fmt)
{
  char	buffer[50];
  char	*ptr;
  int	local;
  int	len;
  char	to_print;

  local = fmt->width;
  ptr = __pf_uint_to_char(buffer, sizeof(buffer), fmt->myvar.ud);
  len = my_strlen(ptr);
  to_print = ((fmt->flag & PF_FLAG_ZERO) ? '0' : ' ');
  if ((local -= len) > 0)
    while (local--)
      __pf_putchar(pf, to_print);
  __pf_write(pf, ptr, len);
  return (0);
}
