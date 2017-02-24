/*
** internal.h for libmy.h in /home/benji_epitech/workdir/perso/libmy/tmp/lib/my/src
** 
** Made by Benjamin Viguier
** Login   <benjamin.viguier@epitech.eu>
** 
** Started on  Thu Feb 23 15:09:08 2017 Benjamin Viguier
** Last update Fri Feb 24 13:24:24 2017 Benjamin Viguier
*/

#ifndef INTERNAL_H_
# define INTERNAL_H_

# include <stdarg.h>
# include "libmy.h"

/*
** my_printf struct, type & enum
*/
typedef struct	s_pf_data
{
  int		is_strbuffer;
  t_strbuilder	*sb;
  t_my_fd	*fd;
  int		pos;
  char		*fmt;
  va_list	va;
}		t_pf_data;

typedef struct	s_pf_prm
{
  int		type;
  int		width;
  int		preci;
  int		flag;
  char		*pat;
  size_t	size;
}		t_pf_prm;

enum
  {
    
    PF_NO_FLAG		= 0x0,
    PF_FLAG_SUB		= 0x1,
    PF_FLAG_ADD		= 0x2,
    PF_FLAG_SPACE	= 0x4,
    PF_FLAG_ZERO	= 0x8
  }

typedef struct	s_pf_prmflag
{
  int		type;
  char		c;
}		t_pf_prmflag;

typedef struct	s_pf_sprm
{
  char		*pat;
  size_t	size;
}		t_pf_sprm;

typedef struct	s_pf_type
{
  char		*pat;
  t_pf_sprm	*sprm;
}		t_pf_type;

/*
** my_printf global
*/
const t_pf_sprm	g_uint_tab[];
const t_pf_sprm	g_int_tab[];
const t_pf_sprm	g_fl_tab[];
const t_pf_sprm	g_char_tab[];
const t_pf_sprm	g_str_tab[];
const t_pf_sprm	g_ptr_tab[];
const t_pf_sprm	g_n_tab[];

/*
** libmy internal functions
*/
int	__libmy_sb_flush(t_strbuilder *sb);
int	__libmy_sb_need_flush(t_strbuilder *sb);
int	__libmy_fd_need_flush(t_my_fd *fd);

/*
** my_print internal functions
*/
int	__pf_putchar(t_pf_data *data, char c);
void	__pf_flush(t_pf_data *data);
int	__pf_get_flags(t_pf_data *data, t_pf_prm *prm);
void	__pf_get_modpat(s_pf_data *data, s_pf_prm *prm);

#endif /* !INTERNAL_H_ */
