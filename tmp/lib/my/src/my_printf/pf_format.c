/*
** pf_format.c for libmy in /home/benji_epitech/workdir/perso/libmy/tmp/lib/my
** 
** Made by Benjamin Viguier
** Login   <benjamin.viguier@epitech.eu>
** 
** Started on  Mon Feb 27 12:21:52 2017 Benjamin Viguier
** Last update Thu May 18 01:33:07 2017 Benjamin Viguier
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
  
  if (prm->size == 0)
    {
      __pf_putchar(data, '%');
      data->fmt = ((*(prm->save) == '%') ? (prm->save + 1) : prm->save);
      return (0);
    }
  if (prm->type >= 'A' && prm->type <= 'z')
    {
      fct = g_pf_table[prm->type - 'A'];
      printf("%c %d %d %d %d %s %p %d %p %s\n", prm->type, prm->width, prm->preci, prm->flag, prm->size, prm->pat, fct, prm->type - 'A', prm->myvar.s, prm->myvar.s);
      if (fct)
	return (fct(data, prm));
    }
  data->fmt = prm->save;
  __pf_putchar(data, '%');
  if (*(data->fmt) == '%')
    (data->fmt)++;
  return (0);
}

int	__pf_hexaflt(t_pf_data *pf, t_pf_prm *fmt)
{

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

int	__pf_dec(t_pf_data *pf, t_pf_prm *fmt) 
{

}

int	__pf_hexa(t_pf_data *pf, t_pf_prm *fmt)
{

}

int	__pf_bin(t_pf_data *pf, t_pf_prm *fmt)
{

}

int	__pf_char(t_pf_data *pf, t_pf_prm *fmt)
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

int	__pf_udec(t_pf_data *pf, t_pf_prm *fmt)
{

}
