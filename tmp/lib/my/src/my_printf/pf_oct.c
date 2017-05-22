/*
** pf_oct.c for libmy in /home/ben/epitech/libmy/tmp/lib/my
** 
** Made by Benjamin Viguier
** Login   <benjamin.viguier@epitech.eu>
** 
** Started on  Sun May 21 01:44:03 2017 Benjamin Viguier
** Last update Mon May 22 15:53:34 2017 Benjamin Viguier
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
  char		*header;
  t_wandp_ud	wandp;

  my_memset(&wandp, 0, sizeof(t_wandp_ud));
  if (fmt->flag & PF_FLAG_DEZ)
    header = "0";
  else
    header = "";
  ptr = __pf_uint_to_oct(buffer, sizeof(buffer),
			  fmt->myvar.ud);
  len = my_strlen(ptr);
  wandp.buffer = ptr;
  wandp.header = header;
  __pf_wandp_ud(fmt, len, my_strlen(header), &wandp);
  if (fmt->flag & PF_FLAG_DEZ && wandp.zero_len)
    {
      if (len + wandp.zero_len + wandp.space_len <= fmt->width)
	wandp.space_len += 1;
      wandp.zero_len -= 1;
    }
  __pf_ud_print(pf, fmt, &wandp);
  return (0);
}
