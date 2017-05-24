/*
** pf_hexa.c for libmy in /home/ben/epitech/libmy/tmp/lib/my
** 
** Made by Benjamin Viguier
** Login   <benjamin.viguier@epitech.eu>
** 
** Started on  Sat May 20 23:17:52 2017 Benjamin Viguier
** Last update Mon May 22 15:29:18 2017 Benjamin Viguier
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
  char		buffer[PF_NBR_BUF_LEN];
  char		*ptr;
  size_t	len;
  char		*header;
  t_wandp_ud	wandp;

  my_memset(&wandp, 0, sizeof(t_wandp_ud));
  if (fmt->flag & PF_FLAG_DEZ)
    header = ((fmt->type == 'X') ? "0X" : "0x");
  else
    header = "";
  ptr = __pf_uint_to_hexa(buffer, sizeof(buffer),
			  ((fmt->type == 'X') ? bpatern : patern),
			  fmt->myvar.ud);
  len = my_strlen(ptr);
  wandp.buffer = ptr;
  wandp.header = header;
  __pf_wandp_ud(fmt, len, my_strlen(header), &wandp);
  __pf_ud_print(pf, fmt, &wandp);
  return (0);
}

int	__pf_ptr(t_pf_data *pf, t_pf_prm *fmt)
{
  fmt->flag |= PF_FLAG_DEZ;
  fmt->pat = "l";
  fmt->type = 'x';
  return (__pf_hexa(pf, fmt));
}
