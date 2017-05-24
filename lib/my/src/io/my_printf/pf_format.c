/*
** pf_format.c for libmy in /home/benji_epitech/workdir/perso/libmy/tmp/lib/my
** 
** Made by Benjamin Viguier
** Login   <benjamin.viguier@epitech.eu>
** 
** Started on  Mon Feb 27 12:21:52 2017 Benjamin Viguier
** Last update Wed May 24 13:53:34 2017 Benjamin Viguier
*/

#include "internal.h"

static t_pf_fct	g_pf_table[] =
  {
    &__pf_hexaflt, &__pf_bin, NULL, NULL, &__pf_scflt,
    /*   A              B      C     D         E  */
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
      if (fct)
	return (fct(data, prm));
    }
  __pf_putchar(data, '%');
  data->fmt = ((prm->type == '%') ? data->fmt : prm->save);
  return (0);
}

int	__pf_hexaflt(t_pf_data *pf, t_pf_prm *fmt)
{
  (void) pf;
  (void) fmt;
  my_printf("%s\n", __func__);
  return (0);
}

int	__pf_scflt(t_pf_data *pf, t_pf_prm *fmt)
{
  (void) pf;
  (void) fmt;
  my_printf("%s\n", __func__);
  return (0);
}

int	__pf_flt(t_pf_data *pf, t_pf_prm *fmt)
{
  (void) pf;
  (void) fmt;
  my_printf("%s\n", __func__);
  return (0);
}

int	__pf_shtflt(t_pf_data *pf, t_pf_prm *fmt)
{
  (void) pf;
  (void) fmt;
  my_printf("%s\n", __func__);
  return (0);
}
