/*
** pf_modif_va.c for libmy in /home/benji_epitech/workdir/perso/libmy/tmp/lib/my
** 
** Made by Benjamin Viguier
** Login   <benjamin.viguier@epitech.eu>
** 
** Started on  Mon Feb 27 13:25:31 2017 Benjamin Viguier
** Last update Fri Jun  2 11:40:57 2017 Benjamin Viguier
*/

#include <unistd.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdint.h>
#include <wchar.h>
#include "internal.h"
#include "pf_modif.h"

void	__pf_getd(va_list va, t_pf_prm *prm)
{
  if (!my_strcmp(prm->pat, PAT_L))
    prm->myvar.d = (long long int) (va_arg(va, long int));
  else if (!my_strcmp(prm->pat, PAT_LL))
    prm->myvar.d = (long long int) (va_arg(va, long long int));
  else if (!my_strcmp(prm->pat, PAT_J))
    prm->myvar.d = (long long int) (va_arg(va, intmax_t));
  else if (!my_strcmp(prm->pat, PAT_Z))
    prm->myvar.d = (long long int) (va_arg(va, size_t));
  else if (!my_strcmp(prm->pat, PAT_T))
    prm->myvar.d = (long long int) (va_arg(va, ptrdiff_t));
  else if (!my_strcmp(prm->pat, PAT_HH))
    prm->myvar.d = (long long int) ((char) va_arg(va, int));
  else if (!my_strcmp(prm->pat, PAT_H))
    prm->myvar.d = (long long int) ((short) va_arg(va, int));
  else
    prm->myvar.d = (long long int) (va_arg(va, int));
}

void	__pf_getud(va_list va, t_pf_prm *prm)
{
  if (!my_strcmp(prm->pat, PAT_L))
    prm->myvar.ud = (unsigned long long int)
      va_arg(va, unsigned long int);
  else if (!my_strcmp(prm->pat, PAT_LL))
    prm->myvar.ud = (unsigned long long int)
      va_arg(va, unsigned long long int);
  else if (!my_strcmp(prm->pat, PAT_J))
    prm->myvar.ud = (unsigned long long int)
      va_arg(va, intmax_t);
  else if (!my_strcmp(prm->pat, PAT_Z))
    prm->myvar.ud = (unsigned long long int)
      va_arg(va, size_t);
  else if (!my_strcmp(prm->pat, PAT_T))
    prm->myvar.ud = (unsigned long long int)
      va_arg(va, ptrdiff_t);
  else if (!my_strcmp(prm->pat, PAT_H))
    prm->myvar.ud = (unsigned long long int)
      ((unsigned short) va_arg(va, unsigned));
  else if (!my_strcmp(prm->pat, PAT_HH))
    prm->myvar.ud = (unsigned long long int)
      ((unsigned char) va_arg(va, unsigned));
  else
    prm->myvar.ud = (unsigned long long int)
      va_arg(va, unsigned int);
}

void	__pf_getrest(va_list va, t_pf_prm *prm, int type)
{
  if (type == TYPE_FLT)
    {
      if (!(prm->pat))
	prm->myvar.ld = (long double) va_arg(va, double);
      else if (*(prm->pat) == 'L')
	prm->myvar.ld = (long double) va_arg(va, long double);
      else
	prm->myvar.ld = (long double) va_arg(va, double);
    }
  else if (type == TYPE_CHAR)
    {
      if (!(prm->pat))
	prm->myvar.d = (long long int) ((char) va_arg(va, int));
      else if  (*(prm->pat) == 'l')
	prm->myvar.d = (long long int) (va_arg(va, t_wint));
      else
	prm->myvar.d = (long long int) ((char) va_arg(va, int));
    }
  else if (type == TYPE_STR)
    prm->myvar.s = va_arg(va, char*);
  else
    prm->myvar.ptr = va_arg(va, void*);
}
