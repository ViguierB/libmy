/*
** load_bitmap.h for wolf3d in /home/benji_epitech/C_Graph_Prog/wolf3d/bonus/src
** 
** Made by Benjamin Viguier
** Login   <benjamin.viguier@epitech.eu>
** 
** Started on  Thu Jan 12 14:02:26 2017 Benjamin Viguier
** Last update Thu Feb  9 16:09:05 2017 Benjamin Viguier
*/

#ifndef LOAD_BITMAP_H_
# define LOAD_BITMAP_H_

# define TYPE_BMP (0x4D42)

struct			s_bmpfileheader
{
  unsigned short	bf_type;
  unsigned int		bf_size;
  unsigned short	bf_reserved1;
  unsigned short	bf_reserved2;
  unsigned int		bf_offbit;
}			__attribute__ ((packed));
typedef s_bmpfileheader	t_bmpfileheader;

struct			s_bmpmapheader
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
}			__attribute__ ((packed));
typedef s_bmpmapheader	t_bmpmapheader;

typedef struct		s_bmpdata
{
  t_bmpmapheader	header;
  char			*palette;
  char			*buffer;
  char			*com;
}			t_bmpdata;

int	itnl_load_bitmap(char *path, t_bmpdata *bmp);

#endif /* !LOAD_BITMAP_H_ */
