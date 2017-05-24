/*
** pf_modifier.c for libmy in /home/benji_epitech/workdir/perso/libmy/tmp/lib/my
** 
** Made by Benjamin Viguier
** Login   <benjamin.viguier@epitech.eu>
** 
** Started on  Fri Feb 24 11:45:51 2017 Benjamin Viguier
** Last update Wed May 24 11:57:54 2017 Benjamin Viguier
*/

#include <unistd.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdint.h>
#include <wchar.h>
#include "internal.h"
#include "pf_modif.h"

static const char	*g_all_pat[] =
  {
    PAT_HH,
    PAT_LL,
    PAT_H,
    PAT_L,
    PAT_J,
    PAT_Z,
    PAT_T,
    PAT_GL,
    NULL
  };

static const t_pf_sprm	g_int_tab[] =
  {
    {PAT_HH, sizeof(char)},
    {PAT_LL, sizeof(long long int)},
    {PAT_H, sizeof(short int)},
    {PAT_L, sizeof(long int)},
    {PAT_J, sizeof(intmax_t)},
    {PAT_Z, sizeof(size_t)},
    {PAT_T, sizeof(ptrdiff_t)},
    {NULL, sizeof(int)}
  };

static const t_pf_sprm	g_uint_tab[] =
  {
    {PAT_HH, sizeof(unsigned char)},
    {PAT_LL, sizeof(unsigned long long int)},
    {PAT_H, sizeof(unsigned short int)},
    {PAT_L, sizeof(unsigned long int)},
    {PAT_J, sizeof(intmax_t)},
    {PAT_Z, sizeof(size_t)},
    {PAT_T, sizeof(ptrdiff_t)},
    {NULL, sizeof(unsigned int)}
  };

static const t_pf_sprm	g_fl_tab[] =
  {
    {PAT_GL, sizeof(long double)},
    {NULL, sizeof(double)}
  };

static const t_pf_sprm	g_char_tab[] =
  {
    {PAT_L, sizeof(t_wint)},
    {NULL, sizeof(int)}
  };

static const t_pf_sprm	g_str_tab[] =
  {
    {PAT_L, sizeof(wchar_t*)},
    {NULL, sizeof(char*)}
  };

static const t_pf_sprm	g_ptr_tab[] =
  {
    {NULL, sizeof(void*)}
  };

static const t_pf_sprm	g_n_tab[] =
  {
    {PAT_HH, sizeof(char)},
    {PAT_LL, sizeof(long long int)},
    {PAT_H, sizeof(short int)},
    {PAT_L, sizeof(long int)},
    {PAT_J, sizeof(intmax_t)},
    {PAT_Z, sizeof(size_t)},
    {PAT_T, sizeof(ptrdiff_t)},
    {NULL, sizeof(int)}
  };

static const t_pf_type	g_type_pat[] =
    {
      {"uoxXbB", g_uint_tab},
      {"id", g_int_tab},
      {"fFeEgGaA", g_fl_tab},
      {"c", g_char_tab},
      {"sS", g_str_tab},
      {"p", g_ptr_tab},
      {"n", g_n_tab},
      {NULL, NULL}
    };

void	__pf_get_var(va_list va, t_pf_prm *prm, int i)
{
  if (i == 0)
    __pf_getud(va, prm);
  else if (i == 1)
    __pf_getd(va, prm);
  else if (i == 2)
    __pf_getrest(va, prm, TYPE_FLT);
  else if (i == 3)
    __pf_getrest(va, prm, TYPE_CHAR);
  else if (i == 4)
    __pf_getrest(va, prm, TYPE_STR);
  else
    __pf_getrest(va, prm, TYPE_OTHER);
}

void		__pf_get_modsize(va_list va, t_pf_prm *prm)
{
  t_pf_sprm	*sprm_cur;
  t_pf_type	*cur;
  int		i;

  cur = (t_pf_type*) g_type_pat;
  while (cur->pat)
    {
      i = 0;
      sprm_cur = (t_pf_sprm*) cur->sprm;
      while (cur->pat[i])
	{
	  if (cur->pat[i] == prm->type)
	    {
	      prm->size = sprm_cur[i].size;
	      __pf_get_var(va, prm, cur - g_type_pat);
	      return;
	    }
	  i++;
	}
      cur++;
    }
}

int	__pf_verif_len(t_pf_data *data, int len)
{
  int	i;

  i = 0;
  while (i < len)
    {
      if (data->fmt[i] == '\0')
	return (0);
      i++;
    }
  return (1);
}

int	__pf_get_modpat(t_pf_data *data, t_pf_prm *prm)
{
  char	**cur;
  int	len;

  cur = (char**) g_all_pat;
  while (*cur)
    {
      len = my_strlen(*cur);
      if (__pf_verif_len(data, len) &&
	  my_memcmp(data->fmt, *cur, len) == 0)
	{
	  data->fmt += len;
	  prm->pat = *cur;
	  break;
	}
      cur++;
    }
  prm->type = *(data->fmt);
  (data->fmt)++;
  if (prm->type != '%')
    __pf_get_modsize(data->va, prm);
  if (*(data->fmt) == '\0')
    return (0);
  return (1);
}
