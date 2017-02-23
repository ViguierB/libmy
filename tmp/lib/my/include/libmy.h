/*
** libmy.h for libmy in /home/benji_epitech/System_Unix/PSU_2016_my_sokoban
** 
** Made by Benjamin Viguier
** Login   <benjamin.viguier@epitech.eu>
** 
** Started on  Mon Dec 12 13:19:11 2016 Benjamin Viguier
** Last update Thu Feb 23 18:14:14 2017 Benjamin Viguier
*/

#ifndef LIBMY_H_
# define LIBMY_H_

# include <stdlib.h>

# define S_IN 0
# define S_OUT 1
# define S_ERR 2
# define MY_FD_BUFF_LEN 1024
# define PSQ(x) ((x) * (x))
# define MIN(a, b) (((a) < (b)) ? (a) : (b))
# define MAX(a, b) (((a) > (b)) ? (a) : (b))
# define ABS(a) (((a) < 0) ? (-(a)) : (a))
# define CLIST_NEXT(l, e) ((((e)->next) == (l)) ? ((void*) 0) : ((e)->next)) 

typedef struct	s_my_fd
{
  int		fd;
  char		buf[MY_FD_BUFF_LEN];
  int		rest;
  int		len;
  char		wbuf[MY_FD_BUFF_LEN];
  int		wlen;
}		t_my_fd;

enum
  {
    SBW_BEGIN,
    SBW_POS,
    SBW_END
  };

typedef struct	s_strbuilder
{
  char		buf[MY_FD_BUFF_LEN];
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

typedef unsigned long	t_ulong;
typedef unsigned int	t_uint;
typedef unsigned short	t_usht;
typedef unsigned char	t_uchar;

/*
** Circular Linked List
*/
t_clist	*clist_push(t_clist *l, void *ptr);
void	clist_swap_val(t_clist_elm *elm1, t_clist_elm *elm2);
void	clist_free(t_clist *l);
void	clist_free_data(t_clist *l, void (*myfree)(void*));

/*
** Basics Functs
** Notes :
**	- nb_lines for my_split is optionnal,
**		use NULL if u don't want to use it.
*/
int	my_printf(char *fmt, ...);
int	my_sbprintf(t_strbuilder *sb, char *fmt, ...);
char	my_sprintf(char *fmt, ...);
int	my_putchar(char c);
int	my_putstr(char *str);
int	my_puterror(char *error_str);
int	my_putnbr_base(int nb, char *base);
int	my_strlen(char *str);
int	my_malloc(void *ptr, size_t len);
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
** my_fd functions
*/
t_my_fd	*my_fdin(void);
t_my_fd	*my_fdout(void);
t_my_fd	*my_fderr(void);
t_my_fd	*my_fd_from_fd(const int fd);
t_my_fd	*my_fopen(char *path, int flags, ...);
void	my_fclose(t_my_fd *to_free);
char	*my_getline(t_my_fd *pack);
ssize_t	my_fread(t_my_fd *pack, char *buffer, size_t size);
int	my_fread_to_end(t_my_fd *fd, char **res);
off_t	my_fd_seek(t_my_fd *sb, off_t offset, int whence);
ssize_t	my_fwrite(t_my_fd *fd, void *ptr, size_t size);
int	my_fflush(t_my_fd *fd);

/*
** my_strbuilder functions
*/
t_strbuilder	*my_sb_init(void);
char		*my_sb_get_str(t_strbuilder *sb);
int		my_sb_write(t_strbuilder *sb, void *ptr, size_t size);
off_t		my_sb_seek(t_strbuilder *sb, off_t offset, int whence);
char		*my_sb_flush(t_strbuilder *sb);

#endif /* !LIBMY_H_ */
