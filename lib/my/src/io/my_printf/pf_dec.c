/*
** pf_dec.c for libmy in /home/ben/epitech/libmy/tmp/lib/my
** 
** Made by Benjamin Viguier
** Login   <benjamin.viguier@epitech.eu>
** 
** Started on  Sat May 20 21:14:42 2017 Benjamin Viguier
** Last update Sat Jun  3 15:45:33 2017 Benjamin Viguier
*/

#include "internal.h"

static char	*__pf_int_to_char(char buffer[], size_t len, long long int d)
{
  char		*ptr;

  ptr = buffer + (len - 1);
  *ptr = '\0';
  while (1)
    {
      *(--ptr) = ABS(d % 10) + '0';
      d /= 10;
      if (!d)
	break;
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
				  unsigned long long int u)
{
  char		*ptr;

  ptr = buffer + (len - 1);
  *ptr = '\0';
  while (1)
    {
      *(--ptr) = u % 10 + '0';
      u /= 10;
      if (!u)
	break;
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
