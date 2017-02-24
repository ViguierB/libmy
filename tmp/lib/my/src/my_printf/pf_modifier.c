/*
** pf_modifier.c for libmy in /home/benji_epitech/workdir/perso/libmy/tmp/lib/my
** 
** Made by Benjamin Viguier
** Login   <benjamin.viguier@epitech.eu>
** 
** Started on  Fri Feb 24 11:45:51 2017 Benjamin Viguier
** Last update Fri Feb 24 13:14:38 2017 Benjamin Viguier
*/

#include <stdint.h>
#include "internal.h"

const char	*g_all_pat[] =
  {
    "hh",
    "ll",
    "h",
    "l",
    "j",
    "z",
    "t",
    "L",
    NULL
  };

const t_pf_sprm	g_int_tab[] =
  {
    {g_all_pat[0], sizeof(char)},
    {g_all_pat[1], sizeof(long long int)},
    {g_all_pat[2], sizeof(short int)},
    {g_all_pat[3], sizeof(long int)},
    {g_all_pat[4], sizeof(intmax_t)},
    {g_all_pat[5], sizeof(size_t)},
    {g_all_pat[6], sizeof(ptrdiff_t)},
    {NULL, sizeof(int)}
  };

const t_pf_sprm	g_uint_tab[] =
  {
    {g_all_pat[0], sizeof(unsigned char)},
    {g_all_pat[1], sizeof(unsigned long long int)},
    {g_all_pat[2], sizeof(unsigned short int)},
    {g_all_pat[3], sizeof(unsigned long int)},
    {g_all_pat[4], sizeof(intmax_t)},
    {g_all_pat[5], sizeof(size_t)},
    {g_all_pat[6], sizeof(ptrdiff_t)},
    {NULL, sizeof(unigned int)}
  };

const t_pf_sprm	g_fl_tab[] =
  {
    {g_all_pat[7], sizeof(long double)},
    {NULL, sizeof(double)}
  };

const t_pf_sprm	g_char_tab[] =
  {
    {g_all_pat[3], sizeof(wint_t)},
    {NULL, sizeof(int)}
  };

const t_pf_sprm	g_str_tab[] =
  {
    {g_all_pat[3], sizeof(wchar_t*)},
    {NULL, sizeof(char*)}
  };

const t_pf_sprm	g_ptr_tab[] =
  {
    {NULL, sizeof(void*)}
  };

const t_pf_sprm	g_n_tab[] =
  {
    {g_all_pat[0], sizeof(char*)},
    {g_all_pat[1], sizeof(long long int*)},
    {g_all_pat[2], sizeof(short int*)},
    {g_all_pat[3], sizeof(long int*)},
    {g_all_pat[4], sizeof(intmax_t*)},
    {g_all_pat[5], sizeof(size_t*)},
    {g_all_pat[6], sizeof(ptrdiff_t*)},
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

void		__pf_get_modsize(s_pf_data *data, s_pf_prm *prm)
{
  t_pf_sprm	*sprm_cur;
  t_pf_type	*cur;

  cur = (t_pf_type*) g_type_pat;
  while (pat[i]->)
    {
      
      i++;
    }
}

void	__pf_get_modpat(s_pf_data *data, s_pf_prm *prm)
{
  char	**cur;

  cur = (char**) g_all_pat;
  while (*cur)
    {
      if (my_strncpy(data->fmt, *cur, my_strlen(*cur)) == 0)
	{
	  prm->pat = *cur;
	  return;
	}
      cur++;
    }
}
