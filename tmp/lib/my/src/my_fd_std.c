/*
** my_fd_std.c for libmy in /home/benji_epitech/workdir/perso/libmy/tmp/lib/my
** 
** Made by Benjamin Viguier
** Login   <benjamin.viguier@epitech.eu>
** 
** Started on  Thu Feb 23 18:01:04 2017 Benjamin Viguier
** Last update Thu Feb 23 18:06:21 2017 Benjamin Viguier
*/

#include "internal.h"

t_my_fd			*my_fdin(void)
{
  static int		init;
  static t_my_fd	*in;

  if (!init)
    in = my_fd_from_fd(S_IN);
  return (in);
}

t_my_fd			*my_fdout(void)
{
  static int		init;
  static t_my_fd	*in;

  if (!init)
    in = my_fd_from_fd(S_OUT);
  return (in);
}

t_my_fd			*my_fderr(void)
{
  static int		init;
  static t_my_fd	*in;

  if (!init)
    in = my_fd_from_fd(S_ERR);
  return (in);
}
