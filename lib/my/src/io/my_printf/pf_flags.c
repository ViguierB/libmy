/*
** pf_flags.c for libmy in /home/benji_epitech/workdir/perso/libmy/tmp/lib/my
** 
** Made by Benjamin Viguier
** Login   <benjamin.viguier@epitech.eu>
** 
** Started on  Fri Feb 24 11:03:35 2017 Benjamin Viguier
** Last update Thu May 25 02:40:48 2017 Benjamin Viguier
*/

#include "internal.h"

const t_pf_prmflag	g_prmf_tab[] =
  {
    {PF_FLAG_SUB, '-'},
    {PF_FLAG_ADD, '+'},
    {PF_FLAG_DEZ, '#'},
    {PF_FLAG_SPACE, ' '},
    {PF_FLAG_ZERO, '0'},
    {PF_NO_FLAG, '\0'},
  };

int	__pf_prm_nbr(t_pf_data *data, int *res)
{
  int	nbr;

  nbr = 0;
  if (*(data->fmt) == '\0')
	return (-1);
  if (*(data->fmt) == '*')
    {
      (data->fmt)++;
      *res = va_arg(data->va, int);
      return (0);
    }
  while (*(data->fmt) >= '0' && *(data->fmt) <= '9')
    {
      nbr *= 10;
      nbr += *(data->fmt) - '0';
      (data->fmt)++;
    }
  *res = nbr;
  return (0);
}

int	__pf_getfflag(t_pf_data *data, t_pf_prm *prm)
{
  t_pf_prmflag	*cur;
  int		found;

  found = 1;
  while (found)
    {
      found = 0;
      cur = (t_pf_prmflag*) g_prmf_tab;
      while (!found && cur->type != PF_NO_FLAG)
	{
	  if (cur->c == *(data->fmt))
	    {
	      prm->flag |= cur->type;
	      if (*(data->fmt) == '\0')
		return (0);
	      (data->fmt)++;
	      found = 1;
	    }
	  cur++;
	}
    }
  return (1);
}

int		__pf_get_flags(t_pf_data *data, t_pf_prm *prm)
{
  my_memset(prm, 0, sizeof(t_pf_prm));
  prm->preci = -1;
  prm->save = data->fmt;
  if (*(data->fmt) == '\0')
    return (0);
  if (__pf_getfflag(data, prm) == 0)
    return (0);
  if (__pf_prm_nbr(data, &(prm->width)))
    return (0);
  if (*(data->fmt) == '.')
    {
      (data->fmt)++;
      if (*(data->fmt) == '\0')
	return (0);
      if (__pf_prm_nbr(data, &(prm->preci)) < 0)
	return (0);
      if (*(data->fmt) == '\0' || prm->preci < 0)
	return (0);
    }
  return (__pf_get_modpat(data, prm));
}
