/*
** load_bitmap.c for wolf3d in /home/benji_epitech/C_Graph_Prog/wolf3d/bonus/src
** 
** Made by Benjamin Viguier
** Login   <benjamin.viguier@epitech.eu>
** 
** Started on  Fri Jan 13 09:22:48 2017 Benjamin Viguier
** Last update Thu Feb  9 16:13:49 2017 Benjamin Viguier
*/

#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "libmy.h"
#include "load_bitmap.h"

int			itnl_load_bitmap(char *path,
					 t_bmpdata *data)
{
  int			fd;
  t_bmpfileheader	fh;

  my_memset(data, 0, sizeof(t_bmpdata));
  if ((fd = open(path, O_RDONLY)) < 0)
    return (-1);
  if (read(fd, &fh, sizeof(fh)) != sizeof(fh))
    return (-2);
  lseek(fd, fh.offbit, SET_BEG);
}
