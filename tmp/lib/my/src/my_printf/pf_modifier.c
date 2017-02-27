/*
** pf_modifier.c for libmy in /home/benji_epitech/workdir/perso/libmy/tmp/lib/my
** 
** Made by Benjamin Viguier
** Login   <benjamin.viguier@epitech.eu>
** 
** Started on  Fri Feb 24 11:45:51 2017 Benjamin Viguier
** Last update Mon Feb 27 11:04:53 2017 Benjamin Viguier
*/

#include <unistd.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdint.h>
#include <wchar.h>
#include "internal.h"
#include "pf_modif.h"

const char const	*g_all_pat[] =
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

const t_pf_sprm	g_int_tab[] =
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

const t_pf_sprm	g_uint_tab[] =
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

const t_pf_sprm	g_fl_tab[] =
  {
    {PAT_GL, sizeof(long double)},
    {NULL, sizeof(double)}
  };

const t_pf_sprm	g_char_tab[] =
  {
    {PAT_L, sizeof(t_wint)},
    {NULL, sizeof(int)}
  };

const t_pf_sprm	g_str_tab[] =
  {
    {PAT_L, sizeof(wchar_t*)},
    {NULL, sizeof(char*)}
  };

const t_pf_sprm	g_ptr_tab[] =
  {
    {NULL, sizeof(void*)}
  };

const t_pf_sprm	g_n_tab[] =
  {
    {PAT_HH, sizeof(char*)},
    {PAT_LL, sizeof(long long int*)},
    {PAT_H, sizeof(short int*)},
    {PAT_L, sizeof(long int*)},
    {PAT_J, sizeof(intmax_t*)},
    {PAT_Z, sizeof(size_t*)},
    {PAT_T, sizeof(ptrdiff_t*)},
    {NULL, sizeof(int*)}
  };

const t_pf_type	g_type_pat[] =
    {
      {"uoxXb", g_uint_tab},
      {"id", g_int_tab},
      {"fFeEgGaA", g_fl_tab},
      {"c", g_char_tab},
      {"sS", g_str_tab},
      {"p", g_ptr_tab},
      {"n", g_n_tab},
      {NULL, NULL}
    };

void		__pf_get_modsize(t_pf_prm *prm)
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
	      i = 0;
	      while (sprm_cur[i].pat &&
		     my_strcmp(sprm_cur[i].pat, prm->pat) != 1)
		i++;
	      prm->size = sprm_cur[i].size;
	      return;
	    }
	  i++;
	}
      cur++;
    }
}

int	__pf_get_modpat(t_pf_data *data, t_pf_prm *prm)
{
  char	**cur;
  int	len;

  cur = (char**) g_all_pat;
  while (*cur)
    {
      len = my_strlen(*cur);
      if (my_memcmp(data->fmt, *cur, len) == 0)
	{
	  data->fmt += len;
	  if (*(data->fmt) == '\0')
	    return (0);
	  prm->pat = *cur;
	  prm->type = *(data->fmt);
	  (data->fmt)++;
	  if (*(data->fmt) == '\0')
	    return (0);
	  __pf_get_modsize(prm);
	  return (1);
	}
      cur++;
    }
  return (0);
}
