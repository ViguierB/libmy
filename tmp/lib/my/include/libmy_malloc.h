/*
** libmy_malloc.h for libmy in /home/benji_epitech/workdir/perso/libmy/tmp/lib/my/src/malloc
** 
** Made by Benjamin Viguier
** Login   <benjamin.viguier@epitech.eu>
** 
** Started on  Wed Apr 26 15:28:45 2017 Benjamin Viguier
** Last update Wed Apr 26 15:58:56 2017 Benjamin Viguier
*/

#ifndef LIBMY_MALLOC_H_
# define LIBMY_MALLOC_H_

# include <unistd.h>

void	*my_malloc(size_t len);
void	*my_realloc(void *old, size_t len);
int	my_free(void *ptr);
void	*my_pcalloc(size_t len, int ch);
void	*my_calloc(size_t len);

#endif /* !LIBMY_MALLOC_H_ */
