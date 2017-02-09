/*
** load_bitmap.c for wolf3d in /home/benji_epitech/C_Graph_Prog/wolf3d/bonus/src
** 
** Made by Benjamin Viguier
** Login   <benjamin.viguier@epitech.eu>
** 
** Started on  Fri Jan 13 09:22:48 2017 Benjamin Viguier
** Last update Fri Jan 20 14:23:34 2017 Benjamin Viguier
*/

#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "load_bitmap.h"

int	close_now(int fd, int error_code)
{
  close(fd);
  return (error_code);
}

int	my_seek(int fd, int to_read)
{
  char	*buffer;

  buffer = malloc(sizeof(char) * to_read);
  if (!buffer)
    return (-1);
  read(fd, buffer, to_read);
  free(buffer);
  return (0);
}

int	read_bitmap_data(t_my_bmp *bmp, t_bmpfileheader *fhead,
			 int fd, int offset)
{
  if (bmp->header.bm_clrused)
    {
      bmp->pal_len = bmp->header.bm_clrused * 4;
      bmp->palette = malloc(sizeof(char) * bmp->pal_len);
      if (!(bmp->palette))
	return (close_now(fd, -1));
      if (!read(fd, &(bmp->palette), bmp->header.bm_clrused))
	return (close_now(fd, -5));
      offset += bmp->header.bm_clrused;
    }
  if (my_seek(fd, fhead->bf_offbit - offset))
    return (close_now(fd, -1));
  bmp->buffer = malloc(sizeof(char) * bmp->header.bm_imgsize);
  if (!(bmp->buffer))
    return (close_now(fd, -1));
  if (!read(fd, bmp->buffer, bmp->header.bm_imgsize))
    return (close_now(fd, -5));
  close(fd);
  return (0);
}

  

int			load_bitmap(char *path, t_my_bmp *bmp)
{
  t_bmpfileheader	fhead;
  int			fd;
  int			offset;

  offset = 0;
  fd = open(path, O_RDONLY);
  if (fd < 0)
    return (-2);
  if (!read(fd, &fhead, sizeof(t_bmpfileheader)))
    return (close_now(fd, -5));
  offset += sizeof(t_bmpfileheader);
  if (fhead.bf_type != TYPE_BMP)
    return (close_now(fd, -4));
  if (!read(fd, &(bmp->header), sizeof(t_bmpmapheader)))
    return (close_now(fd, -5));
  offset += sizeof(t_bmpmapheader);
  return (read_bitmap_data(bmp, &fhead, fd, offset));
}
