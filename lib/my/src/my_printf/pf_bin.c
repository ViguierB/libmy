/*
** pf_bin.c for libmy in /home/ben/epitech/libmy/tmp/lib/my
** 
** Made by Benjamin Viguier
** Login   <benjamin.viguier@epitech.eu>
** 
** Started on  Sun May 21 01:24:39 2017 Benjamin Viguier
** Last update Mon May 22 15:35:47 2017 Benjamin Viguier
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
  char		*header;
  t_wandp_ud	wandp;

  my_memset(&wandp, 0, sizeof(t_wandp_ud));
  if (fmt->flag & PF_FLAG_DEZ)
    header = ((fmt->type == 'B') ? "0B" : "0b");
  else
    header = "";
  ptr = __pf_uint_to_bin(buffer, sizeof(buffer),
			  fmt->myvar.ud);
  len = my_strlen(ptr);
  wandp.buffer = ptr;
  wandp.header = header;
  __pf_wandp_ud(fmt, len, my_strlen(header), &wandp);
  __pf_ud_print(pf, fmt, &wandp);
  return (0);
}
