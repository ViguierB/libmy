/*
** my_fd_std.c for libmy in /home/benji_epitech/workdir/perso/libmy/tmp/lib/my
** 
** Made by Benjamin Viguier
** Login   <benjamin.viguier@epitech.eu>
** 
** Started on  Thu Feb 23 18:01:04 2017 Benjamin Viguier
** Last update Thu Jun  1 11:31:17 2017 Benjamin Viguier
*/

#include <unistd.h>
#include "libmy.h"
#include "internal.h"

static t_my_fd	g_my_fd_buffer[3];
t_my_fd		*g_in;
t_my_fd		*g_out;
t_my_fd		*g_err;

LMY_CONSTRUCTOR static void	__libmy_init_stdfd(void)
{
  my_memset(g_my_fd_buffer, 0, sizeof(g_my_fd_buffer));
  g_in = g_my_fd_buffer;
  g_out = g_my_fd_buffer + 1;
  g_err = g_my_fd_buffer + 2;
  g_in->fd = (S_IN);
  g_out->fd = (S_OUT);
  g_err->fd = (S_ERR);
#ifdef ALLOW_ISATTY
  if (isatty(S_IN))
#endif
    g_in->auto_flush = LMY_TRUE;
#ifdef ALLOW_ISATTY
  if (isatty(S_OUT))
#endif
    g_out->auto_flush = LMY_TRUE;
#ifdef ALLOW_ISATTY
  if (isatty(S_ERR))
#endif
    g_err->auto_flush = LMY_TRUE;
}

LMY_DESTRUCTOR static void	__libmy_close_stdfd(void)
{
  my_fflush(g_in);
  my_fflush(g_out);
  my_fflush(g_err);
}
