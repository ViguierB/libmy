/*
** pf_str.c for libmy in /home/ben/epitech/libmy/tmp/lib/my
** 
** Made by Benjamin Viguier
** Login   <benjamin.viguier@epitech.eu>
** 
** Started on  Thu May 18 01:22:12 2017 Benjamin Viguier
** Last update Thu May 18 01:22:13 2017 Benjamin Viguier
*/

#include "internal.h"

static int	__pf_putstr_octal(t_pf_data *pf, unsigned char c, int local)
{
  char		buffer[5];
  char		*str;
  int		i;

  my_memset(buffer, '0', sizeof(buffer));
  buffer[4] = '\0';
  buffer[0] = '\\';
  i = 4;
  while (--i)
    {
      buffer[i] = (c & 0b0111) + '0';
      c = c >> 3;
    }
  str = buffer;
  local++;
  while (--local && *str)
    __pf_putchar(pf, *(str++));
  return (local);
}

int	__pf_extstr(t_pf_data *pf, t_pf_prm *fmt)
{
  int	local;
  int	width;
  char	*str;

  local = fmt->preci;
  str = fmt->myvar.s;
  width = 0;
  if (local >= 0)
    width = MAX(fmt->width - local, 0);
  while (width--)
    __pf_putchar(pf, ' ');
  while (local-- && *str)
    if (ISPRINTABLE(*str))
      __pf_putchar(pf, *(str++));
    else
      local = __pf_putstr_octal(pf, *(str++), local + 1);
  return (0);
}

int	__pf_str(t_pf_data *pf, t_pf_prm *fmt)
{
  int	local;
  int	width;
  char	*str;

  local = fmt->preci;
  str = fmt->myvar.s;
  width = 0;
  if (local >= 0)
    width = MAX(fmt->width - local, 0);
  while (width--)
    __pf_putchar(pf, ' ');
  while (local-- && *str)
    __pf_putchar(pf, *(str++));
  return (0);
}
