/*
** pf_wandp_format.c for libmy in /home/ben/epitech/libmy/tmp/lib/my
** 
** Made by Benjamin Viguier
** Login   <benjamin.viguier@epitech.eu>
** 
** Started on  Sun May 21 03:37:38 2017 Benjamin Viguier
** Last update Sun May 21 16:22:13 2017 Benjamin Viguier
*/

#include "internal.h"

static void	__pf_wandp_nbr_ext(t_pf_data *pf, int wlocal, int plocal)
{
  while (plocal > 0 || wlocal > 0)
    {
      __pf_putchar(pf, '0');
      wlocal--;
      plocal--;
    }
}

static int	__pf_wandp_preformat(t_pf_data *pf, int wlocal,
				     int plocal, size_t len)
{
  while (plocal != -1 && len < (unsigned) wlocal &&
	 wlocal > plocal && (wlocal - len) > 0)
    {
      __pf_putchar(pf, ' ');
      wlocal--;
    }
  return (wlocal);
}

void	__pf_wandp_nbr(t_pf_data *pf, t_pf_prm *fmt,
		       char *buffer, char *extra)
{
  int	        dez_len;
  int		wlocal;
  int		plocal;
  size_t	len;

  wlocal = fmt->width;
  plocal = fmt->preci;
  dez_len = my_strlen(extra);
  len = my_strlen(buffer);
  wlocal = __pf_wandp_preformat(pf, wlocal - dez_len, plocal, len);
  if (fmt->flag & PF_FLAG_DEZ && fmt->flag & PF_FLAG_ZERO)
    __pf_write(pf, extra, dez_len);
  wlocal -= len;
  while (wlocal > 0 && plocal == -1)
    {
      __pf_putchar(pf, ((fmt->flag & PF_FLAG_ZERO) ? '0' : ' '));
      wlocal--;
    }
  if (fmt->flag & PF_FLAG_DEZ && !(fmt->flag & PF_FLAG_ZERO))
    __pf_write(pf, extra, dez_len);
  __pf_wandp_nbr_ext(pf, wlocal, plocal - len);
  pf_write(pf, buffer, len);
}
