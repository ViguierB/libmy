/*
** my_getline.c for libmy in /home/benji_epitech/workdir/perso/libmy/lib/my
** 
** Made by Benjamin Viguier
** Login   <benjamin.viguier@epitech.eu>
** 
** Started on  Sat May 27 16:48:47 2017 Benjamin Viguier
** Last update Sat May 27 16:49:17 2017 Benjamin Viguier
*/

#include "libmy.h"

char	*my_getline(t_my_fd *pack)
{
  return (my_getdelim(pack, '\n'));
}
