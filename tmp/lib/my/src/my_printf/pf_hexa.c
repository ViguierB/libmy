/*
** pf_hexa.c for libmy in /home/ben/epitech/libmy/tmp/lib/my
** 
** Made by Benjamin Viguier
** Login   <benjamin.viguier@epitech.eu>
** 
** Started on  Sat May 20 23:17:52 2017 Benjamin Viguier
** Last update Sun May 21 00:13:55 2017 Benjamin Viguier
*/

#include "internal.h"

static char	*__pf_uint_to_hexa(char buffer[], size_t len,
				   const char patern[],
				   unsigned long long int u)
{
  char		*ptr;

  ptr = buffer + (len - 1);
  *ptr = '\0';
  while (u)
    {
      *(--ptr) = patern[u & 0b1111];
      u >>= 4;
    }
  return (ptr);
}

int		__pf_hexa(t_pf_data *pf, t_pf_prm *fmt)
{
  const char	bpatern[] = "0123456789ABCDEF";
  const char	patern[] = "0123456789abcdef";
  char		buffer[sizeof(long long int) * 8];
  char		*ptr;
  size_t	len;
  char		*extra;

  if (fmt->flag & PF_FLAG_DEZ)
    extra = ((fmt->type == 'X') ? "0X" : "0x");
  else
    extra = "";
  ptr = __pf_uint_to_hexa(buffer, sizeof(buffer),
			  ((fmt->type == 'X') ? bpatern : patern),
			  fmt->myvar.ud);
  len = my_strlen(ptr);
  __pf_wandp_nbr(pf, fmt, len, extra);
  __pf_write(pf, ptr, len);
  return (0);
}
