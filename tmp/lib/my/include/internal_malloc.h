/*
** internal_malloc.h for libmy in /home/benji_epitech/workdir/perso/libmy/tmp/lib/my/src/malloc
** 
** Made by Benjamin Viguier
** Login   <benjamin.viguier@epitech.eu>
** 
** Started on  Wed Apr 26 14:37:34 2017 Benjamin Viguier
** Last update Wed Apr 26 15:52:25 2017 Benjamin Viguier
*/

#ifndef INTERNAL_MALLOC_H_
# define INTERNAL_MALLOC_H_

# include <unistd.h>
# include <stdint.h>

# define MLC_MAGIC	0x424242

typedef struct	s_mem_header_data
{
  size_t	len;
  uint32_t	magic;
}		t_mem_header_data;

typedef struct		s_mem_header
{
  struct s_mem_header	*next;
  struct s_mem_header	*prev;
  t_mem_header_data	data;
}			t_mem_header;

void	__libmy_create_header(t_mem_header *res, size_t len);
void	*__libmy_verif_ptr(void *tptr);
void	__libmy_remove_header(t_mem_header *ptr);

#endif	/* !INTERNAL_MALLOC_H_ */
