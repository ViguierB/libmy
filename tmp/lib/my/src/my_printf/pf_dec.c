/*
** pf_dec.c for libmy in /home/ben/epitech/libmy/tmp/lib/my
** 
** Made by Benjamin Viguier
** Login   <benjamin.viguier@epitech.eu>
** 
** Started on  Sat May 20 21:14:42 2017 Benjamin Viguier
** Last update Mon May 22 15:27:55 2017 Benjamin Viguier
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

int		__pf_dec(t_pf_data *pf, t_pf_prm *fmt)
{
  char		buffer[PF_NBR_BUF_LEN];
  char		*ptr;
  int		len;
  char		*header;
  t_wandp_ud	wandp;

  my_memset(&wandp, 0, sizeof(t_wandp_ud));
  if (fmt->myvar.d < 0)
    header = "-";
  else if (fmt->flag & PF_FLAG_ADD)
    header = "+";
  else if (fmt->flag & PF_FLAG_SPACE)
    header = " ";
  else
    header = "";
  ptr = __pf_int_to_char(buffer, sizeof(buffer), fmt->myvar.d);
  len = my_strlen(ptr);
  wandp.buffer = ptr;
  wandp.header = header;
  __pf_wandp_ud(fmt, len, my_strlen(header), &wandp);
  __pf_ud_print(pf, fmt, &wandp);
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
  char		buffer[PF_NBR_BUF_LEN];
  char		*ptr;
  int		len;
  t_wandp_ud	wandp;

  my_memset(&wandp, 0, sizeof(t_wandp_ud));
  ptr = __pf_uint_to_char(buffer, sizeof(buffer), fmt->myvar.ud);
  len = my_strlen(ptr);
  wandp.buffer = ptr;
  wandp.header = "";
  __pf_wandp_ud(fmt, len, 0, &wandp);
  __pf_ud_print(pf, fmt, &wandp);
  return (0);
}
