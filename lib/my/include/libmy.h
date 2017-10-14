/*
** libmy.h for libmy in /home/benji_epitech/System_Unix/PSU_2016_my_sokoban
** 
** Made by Benjamin Viguier
** Login   <benjamin.viguier@epitech.eu>
** 
** Started on  Mon Dec 12 13:19:11 2016 Benjamin Viguier
** Last update Sat Oct 14 16:52:42 2017 Benjamin Viguier
*/

#ifndef LIBMY_H_
# define LIBMY_H_

# include <sys/types.h>
# include <stdlib.h>
# include <stdarg.h>
# include "macro.h"

# define S_IN		0
# define S_OUT		1
# define S_ERR		2
# define IO_BUFF_LEN	1024

# define CLIST_NEXT(l, e) ((((e)->next) == (l)) ? ((void*) 0) : ((e)->next))

typedef struct	s_io
{
  int		fd;
  char		buf[IO_BUFF_LEN + 1];
  int		rest;
  int		len;
  char		wbuf[IO_BUFF_LEN + 1];
  int		wlen;
  int		auto_flush;
}		t_io;

enum
  {
    SBW_BEGIN,
    SBW_POS,
    SBW_END
  };

typedef enum	e_lmy_st
  {
    LIBMY_INIT	= 0x1,
    LIBMY_GET	= 0x2,
    LIBMY_SET	= 0x4
  }		t_lmy_st;

typedef struct	s_strbuilder
{
  char		buf[IO_BUFF_LEN + 1];
  size_t	len;
  char		*res;
  off_t		pos;
  size_t	res_len;
}		t_strbuilder;

typedef struct		s_clist
{
  void			*ptr;
  struct s_clist	*next;
  struct s_clist	*prev;
}			t_clist;
typedef t_clist		t_clist_elm;
typedef int		(*t_elm_cmp)(void *, void *);

typedef unsigned long	t_ulong;
typedef unsigned int	t_uint;
typedef unsigned short	t_usht;
typedef unsigned char	t_uchar;

extern t_io	*g_in;
extern t_io	*g_out;
extern t_io	*g_err;

/*
** Circular Linked List
*/
t_clist		*clist_push(t_clist *l, void *ptr);
void		clist_swap_val(t_clist_elm *elm1, t_clist_elm *elm2);
void		clist_free(t_clist *l);
void		clist_free_data(t_clist *l, void (*myfree)(void*));
t_clist		*clist_remove(t_clist *list, t_clist_elm *elm);
t_clist		*clist_rem_fdata(t_clist *list, t_clist_elm *elm,
				 void (*my_free)(void*));
void		clist_sort(t_clist *list, t_elm_cmp cmp_fct);
void		clist_qsort(t_clist *list, t_elm_cmp cmp_fct);
t_clist_elm	*clist_at(t_clist *list, int at);

/*
** Basics Functs
** Notes :
**	- nb_lines for my_split is optionnal,
**		use NULL if u don't want to use it.
*/
int	my_vfprintf(t_io *io, char *fmt, va_list va);
int	my_fprintf(t_io *io, char *fmt, ...);
int	my_dprintf(int io, char *fmt, ...);
int	my_printf(char *fmt, ...);
int	my_sbprintf(t_strbuilder *sb, char *fmt, ...);
char	*my_sprintf(char *fmt, ...);
int	my_putchar(char c);
int	my_putstr(char *str);
int	my_puterror(char *error_str);
int	my_putnbr_base(int nb, char *base);
size_t	my_strlen(const char *str);
size_t	my_strnlen(const char *str, size_t n);
char	*my_strconca(char *str1, char *str2);
char	*my_strcpy(char *dest, char *from);
char	*my_strncpy(char *dest, char *from, int n);
int	my_strcmp(char *s1, char *s2);
char	*my_strdup(char *str);
char	**my_split(char *inp, char sep, int *nb_lines);
int	my_showmem(char *str, int size);
void	*my_memcpy(void *dptr, void *fptr, size_t size);
void	my_memset(void *ptr, int c, size_t size);
int	my_memcmp(void *ptr1, void *ptr2, size_t len);
int	my_memisempty(void *ptr, size_t size);
char	*my_ftrim(char *str);
char	*my_trim(char *str);
int	my_isnum(char *str);
int	my_atoi(char *str);
int	my_strtod(char *str, int *res);

/*
** my_io functions
*/
t_io	*my_io_from_fd(const int fd);
t_io	*my_fopen(char *path, int flags, ...);
void	my_fclose(t_io *to_free);
char	*my_getdelim(t_io *pack, char delim);
char	*my_getline(t_io *pack);
ssize_t	my_fread(t_io *pack, char *buffer, size_t size);
int	my_fread_to_end(t_io *io, char **res);
off_t	my_io_seek(t_io *sb, off_t offset, int whence);
ssize_t	my_fwrite(t_io *io, void *ptr, size_t size);
int	my_fflush(t_io *io);

/*
** my_strbuilder functions
*/
t_strbuilder	*my_sb_init(void);
char		*my_sb_get_str(t_strbuilder *sb);
int		my_sb_write(t_strbuilder *sb, void *ptr, size_t size);
off_t		my_sb_seek(t_strbuilder *sb, off_t offset, int whence);
char		*my_sb_flush(t_strbuilder *sb);
int		my_sbprintf(t_strbuilder *sb, char *fmt, ...);

#endif /* !LIBMY_H_ */
