/*
** pf_str.c for libmy in /home/ben/epitech/libmy/tmp/lib/my
** 
** Made by Benjamin Viguier
** Login   <benjamin.viguier@epitech.eu>
** 
** Started on  Thu May 18 01:22:12 2017 Benjamin Viguier
** Last update Thu Jun  1 17:31:31 2017 Benjamin Viguier
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
  while (local && *str)
    {
      __pf_write(pf, str++, 1);
      --local;
    }
  return (local);
}

static void	__pf_do_strwidth(t_pf_data *pf, int local)
{
  int	width;

  width = MAX(local, 0);
  while (width--)
    __pf_putchar(pf, ' ');
}

int		__pf_str(t_pf_data *pf, t_pf_prm *fmt)
{
  int		wlocal;
  int		plocal;
  char		*str;
  size_t	my_len;

  if (fmt->myvar.s == NULL)
    fmt->myvar.s = "(null)";
  str = fmt->myvar.s;
  my_len = ((fmt->preci < 0) ? my_strlen(str) : my_strnlen(str, (size_t) fmt->preci));
  plocal = ((fmt->preci < 0) ? my_len : MIN((size_t) fmt->preci, my_len));
  wlocal = __pf_wisneg(fmt, fmt->width) - plocal;
  if (!(fmt->flag & PF_FLAG_SUB))
    __pf_do_strwidth(pf, wlocal);
  while (plocal-- && *str)
    __pf_write(pf, str++, 1);
  if (fmt->flag & PF_FLAG_SUB)
    __pf_do_strwidth(pf, wlocal);
  return (0);
}

static size_t	__pf_extstrlen(char *str)
{
  size_t	res;

  res = 0;
  while (*str)
    {
      if (ISPRINTABLE(*str))
	res++;
      else
	res += 4;
      str++;
    }
  return (res);
}

static size_t	__pf_extstrnlen(char *str, size_t n)
{
  size_t	res;

  res = n;
  while (*str)
    {
      if (ISPRINTABLE(*str))
	res--;
      else
	res -= 4;
      str++;
    }
  return (n - MAX(res, 0));
}

int	__pf_extstr(t_pf_data *pf, t_pf_prm *fmt)
{
  int		wlocal;
  int		plocal;
  char		*str;
  size_t	my_len;

  if (fmt->myvar.s == NULL)
    fmt->myvar.s = "(null)";
  str = fmt->myvar.s;
  my_len = ((fmt->preci < 0) ? __pf_extstrlen(str) : __pf_extstrnlen(str, (size_t) fmt->preci));
  plocal = ((fmt->preci < 0) ? my_len : MIN((size_t) fmt->preci, my_len));
  wlocal = __pf_wisneg(fmt, fmt->width) - plocal;
  if (!(fmt->flag & PF_FLAG_SUB))
    __pf_do_strwidth(pf, wlocal);
  while (plocal && *str)
    if (ISPRINTABLE(*str))
      {
	__pf_write(pf, str++, 1);
	--plocal;
      }
    else
      plocal = __pf_putstr_octal(pf, *(str++), plocal);
  if (fmt->flag & PF_FLAG_SUB)
    __pf_do_strwidth(pf, wlocal);
  return (0);
}
