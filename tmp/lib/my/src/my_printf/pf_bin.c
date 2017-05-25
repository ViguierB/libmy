/*
** pf_bin.c for libmy in /home/ben/epitech/libmy/tmp/lib/my
** 
** Made by Benjamin Viguier
** Login   <benjamin.viguier@epitech.eu>
** 
** Started on  Sun May 21 01:24:39 2017 Benjamin Viguier
** Last update Sun May 21 16:20:50 2017 Benjamin Viguier
*/

#include "internal.h"

static char	*__pf_uint_to_bin(char buffer[], size_t len,
				  unsigned long long int u)
{
  char		*ptr;

  ptr = buffer + (len - 1);
  *ptr = '\0';
  while (u)
    {
      *(--ptr) = (u & 0b1) + '0';
      u >>= 1;
    }
  return (ptr);
}

int	__pf_bin(t_pf_data *pf, t_pf_prm *fmt)
{
  char		buffer[PF_NBR_BUF_LEN];
  char		*ptr;
  size_t	len;
  char		*extra;

  if (fmt->flag & PF_FLAG_DEZ)
    extra = ((fmt->type == 'B') ? "0B" : "0b");
  else
    extra = "";
  ptr = __pf_uint_to_bin(buffer, sizeof(buffer),
			  fmt->myvar.ud);
  __pf_wandp_nbr(pf, fmt, ptr, extra);
  __pf_write(pf, ptr, len);
  return (0);
}
