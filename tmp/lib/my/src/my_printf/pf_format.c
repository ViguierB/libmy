/*
** pf_format.c for libmy in /home/benji_epitech/workdir/perso/libmy/tmp/lib/my
** 
** Made by Benjamin Viguier
** Login   <benjamin.viguier@epitech.eu>
** 
** Started on  Mon Feb 27 12:21:52 2017 Benjamin Viguier
** Last update Wed May 17 00:25:24 2017 Benjamin Viguier
*/

#include "internal.h"

static t_pf_fct	g_pf_table[] =
  {
    &__pf_hexaflt, NULL, NULL, NULL, &__pf_scflt,
    /*    A         B     C     D        E        */
    &__pf_flt, &__pf_shtflt, NULL, &__pf_dec, NULL,
    /*   F          G         H         I      K  */
    NULL, NULL, NULL, NULL, NULL, NULL, NULL, &__pf_extstr,
    /*L    M     N     O     P     Q     R      S */
    NULL, NULL, NULL, NULL, &__pf_hexa, NULL, NULL,
    /*T    U     V     W         X       Y     Z  */
    NULL, NULL, NULL, NULL, NULL, NULL, NULL,
    /*[    \     ]     ^    ' '    _     `        */
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
  fct = g_pf_table[prm->type - 'A'];
  printf("%c %d %d %d %d %s %p\n", prm->type, prm->width, prm->preci, prm->flag, prm->size, prm->pat, fct);
  if (fct)
    return (fct(data, prm));
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

int	__pf_extstr(t_pf_data *pf, t_pf_prm *fmt)
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

int	__pf_str(t_pf_data *pf, t_pf_prm *fmt)
{
  int	local;

  local = fmt->preci;
  while (
}

int	__pf_udec(t_pf_data *pf, t_pf_prm *fmt)
{

}
