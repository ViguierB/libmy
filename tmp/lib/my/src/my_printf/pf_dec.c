/*
** pf_dec.c for libmy in /home/ben/epitech/libmy/tmp/lib/my
** 
** Made by Benjamin Viguier
** Login   <benjamin.viguier@epitech.eu>
** 
** Started on  Sat May 20 21:14:42 2017 Benjamin Viguier
** Last update Sun May 21 01:24:19 2017 Benjamin Viguier
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
  char	buffer[PF_NBR_BUF_LEN];
  char	*ptr;
  int	len;
  char	*extra;

  if (fmt->myvar.d < 0)
    extra = "-";
  else if (fmt->flag & PF_FLAG_ADD)
    extra = "+";
  else if (fmt->flag & PF_FLAG_SPACE)
    extra = " ";
  else
    extra = "";
  ptr = __pf_int_to_char(buffer, sizeof(buffer), fmt->myvar.d);
  len = my_strlen(ptr);
  __pf_wandp_nbr(pf, fmt, len, extra);
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
  char	buffer[PF_NBR_BUF_LEN];
  char	*ptr;
  int	len;

  ptr = __pf_uint_to_char(buffer, sizeof(buffer), fmt->myvar.ud);
  len = my_strlen(ptr);
  __pf_wandp_nbr(pf, fmt, len, "");
  __pf_write(pf, ptr, len);
  return (0);
}
