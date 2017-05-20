/*
** pf_oct.c for libmy in /home/ben/epitech/libmy/tmp/lib/my
** 
** Made by Benjamin Viguier
** Login   <benjamin.viguier@epitech.eu>
** 
** Started on  Sun May 21 01:44:03 2017 Benjamin Viguier
** Last update Sun May 21 01:44:17 2017 Benjamin Viguier
*/

#include "internal.h"

static char	*__pf_uint_to_oct(char buffer[], size_t len,
				  unsigned long long int u)
{
  char		*ptr;

  ptr = buffer + (len - 1);
  *ptr = '\0';
  while (u)
    {
      *(--ptr) = (u & 0b111) + '0';
      u >>= 3;
    }
  return (ptr);
}

int	__pf_oct(t_pf_data *pf, t_pf_prm *fmt)
{
  char		buffer[PF_NBR_BUF_LEN];
  char		*ptr;
  size_t	len;
  char		*extra;

  extra = "";
  ptr = __pf_uint_to_oct(buffer, sizeof(buffer),
			  fmt->myvar.ud);
  len = my_strlen(ptr);
  if (fmt->preci <= (int) len ||
      (fmt->width <= (int) len && (fmt->flag & PF_FLAG_ZERO)))
    {
      extra = "0";
      fmt->width -= 1;
    }
  __pf_wandp_nbr(pf, fmt, len, "");
  __pf_write(pf, extra, my_strlen(extra));
  __pf_write(pf, ptr, len);
  return (0);
}
