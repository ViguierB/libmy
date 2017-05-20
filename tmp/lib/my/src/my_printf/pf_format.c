/*
** pf_format.c for libmy in /home/benji_epitech/workdir/perso/libmy/tmp/lib/my
** 
** Made by Benjamin Viguier
** Login   <benjamin.viguier@epitech.eu>
** 
** Started on  Mon Feb 27 12:21:52 2017 Benjamin Viguier
** Last update Sat May 20 21:11:49 2017 Benjamin Viguier
*/

#include "internal.h"

static t_pf_fct	g_pf_table[] =
  {
    &__pf_hexaflt, NULL, NULL, NULL, &__pf_scflt,
    /*   A          B     C     D         E       */
    &__pf_flt, &__pf_shtflt, NULL, &__pf_dec, NULL,
    /*   F          G         H         I      J  */
    NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
    /*K    L    M     N     O     P     Q     R   */
    &__pf_extstr, NULL, NULL, NULL, NULL, &__pf_hexa,
    /*   S         T     U     V     W         X  */
    NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
    /*Y    Z     [     \\    ]     ^     _     `  */
    &__pf_hexaflt, &__pf_bin, &__pf_char, &__pf_dec,
    /*   a              b          c           d  */
    &__pf_scflt, &__pf_flt, &__pf_shtflt, NULL,
    /*   e            f          g         h      */
    &__pf_dec, NULL, NULL, NULL, NULL, &__pf_getnbr,
    /*   i      j     k     l     m,        n     */
    &__pf_oct, &__pf_ptr, NULL, NULL, __pf_str,
    /*   o          p      q     r        s       */
    NULL, &__pf_udec, NULL, NULL, &__pf_hexa, NULL,
    /*t        u       v     w         x       y  */
    NULL
    /* z */
  };

int		__pf_format(t_pf_data *data, t_pf_prm *prm)
{
  t_pf_fct	fct;

  if (prm->type >= 'A' && prm->type <= 'z')
    {
      fct = g_pf_table[prm->type - 'A'];
      printf("%c %d %d %d %d %s %p %d\n", prm->type, prm->width, prm->preci, prm->flag, prm->size, prm->pat, fct, prm->type - 'A');
      if (fct)
	return (fct(data, prm));
    }
  __pf_putchar(data, '%');
  data->fmt = ((prm->type == '%') ? data->fmt : prm->save);
  return (0);
}

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
  char	buffer[50];
  char	*ptr;
  char	*nbr;
  int	local;
  int	len;
  char	to_print;
  

  local = fmt->width - 1;
  if (fmt->myvar.d < 0)
    __pf_putchar(pf, '-');
  else if (fmt->flag & PF_FLAG_ADD)
    __pf_putchar(pf, '+');
  else if (fmt->flag & PF_FLAG_SPACE)
    __pf_putchar(pf, ' ');
  else
    local++;
  ptr = __pf_int_to_char(buffer, sizeof(buffer), fmt->myvar.d);
  len = my_strlen(ptr);
  to_print = ((fmt->flag & PF_FLAG_ZERO) ? '0' : ' ');
  if ((local -= len) > 0)
    while (local--)
      __pf_putchar(pf, to_print);
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
  char	buffer[50];
  char	*ptr;
  char	*nbr;
  int	local;
  int	len;
  char	to_print;

  printf("test\n");
  local = fmt->width;
  ptr = __pf_uint_to_char(buffer, sizeof(buffer), fmt->myvar.ud);
  len = my_strlen(ptr);
  to_print = ((fmt->flag & PF_FLAG_ZERO) ? '0' : ' ');
  if ((local -= len) > 0)
    while (local--)
      __pf_putchar(pf, to_print);
  __pf_write(pf, ptr, len);
  return (0);
}

int	__pf_hexaflt(t_pf_data *pf, t_pf_prm *fmt)
{
  printf("%s\n", __func__);
  return (0);
}

int	__pf_scflt(t_pf_data *pf, t_pf_prm *fmt)
{

}

int	__pf_flt(t_pf_data *pf, t_pf_prm *fmt)
{

}

int	__pf_shtflt(t_pf_data *pf, t_pf_prm *fmt)
{

}

int	__pf_hexa(t_pf_data *pf, t_pf_prm *fmt)
{

}

int	__pf_bin(t_pf_data *pf, t_pf_prm *fmt)
{

}

int	__pf_getnbr(t_pf_data *pf, t_pf_prm *fmt)
{

}

int	__pf_oct(t_pf_data *pf, t_pf_prm *fmt)
{

}

int	__pf_ptr(t_pf_data *pf, t_pf_prm *fmt)
{
  
}
