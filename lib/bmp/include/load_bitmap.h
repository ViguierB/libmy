/*
** load_bitmap.h for wolf3d in /home/benji_epitech/C_Graph_Prog/wolf3d/bonus/src
** 
** Made by Benjamin Viguier
** Login   <benjamin.viguier@epitech.eu>
** 
** Started on  Thu Jan 12 14:02:26 2017 Benjamin Viguier
** Last update Fri Jan 13 20:25:50 2017 Benjamin Viguier
*/

#ifndef LOAD_BITMAP_H_
# define LOAD_BITMAP_H_

# ifndef WOLF_H_
#  pragma pack(push, 1)
# endif /* !WOLF_H_ */

# define TYPE_BMP (0x4D42)

typedef	struct		s_bmpfileheader
{
  unsigned short	bf_type;
  unsigned int		bf_size;
  unsigned short	bf_reserved1;
  unsigned short	bf_reserved2;
  unsigned int		bf_offbit;
}			t_bmpfileheader;

typedef	struct		s_bmpmapheader
{
  unsigned int		bm_size;
  unsigned int		bm_w;
  unsigned int		bm_h;
  unsigned short	bm_planes;
  unsigned short	bm_bitcount;
  unsigned int		bm_compression;
  unsigned int		bm_imgsize;
  unsigned int		bm_xppm;
  unsigned int		bm_yppm;
  unsigned int		bm_clrused;
  unsigned int		bm_clrimp;
}			t_bmpmapheader;

typedef struct		s_my_bmp
{
  t_bmpmapheader	header;
  char			*palette;
  char			*buffer;
}			t_my_bmp;

int	load_bitmap(char *path, t_my_bmp *bmp);
int	free_bitmap(t_my_bmp *bmp);

#endif /* !LOAD_BITMAP_H_ */
