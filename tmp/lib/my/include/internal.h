/*
** internal.h for libmy.h in /home/benji_epitech/workdir/perso/libmy/tmp/lib/my/src
** 
** Made by Benjamin Viguier
** Login   <benjamin.viguier@epitech.eu>
** 
** Started on  Thu Feb 23 15:09:08 2017 Benjamin Viguier
** Last update Thu Feb 23 18:21:32 2017 Benjamin Viguier
*/

#ifndef INTERNAL_H_
# define INTERNAL_H_

# include <stdarg.h>
# include "libmy.h"

int	__libmy_sb_flush(t_strbuilder *sb);
int	__libmy_sb_need_flush(t_strbuilder *sb);
int	__libmy_fd_need_flush(t_my_fd *fd);
  
typedef struct	s_pf_data
{
  int		is_strbuffer;
  t_strbuilder	*sb;
  t_my_fd	*fd;
  int		pos;
  char		*fmt;
  va_list	va;
}		t_pf_data;

#endif /* !INTERNAL_H_ */
