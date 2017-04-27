/*
** libmy_hash.h for libmy in /home/benji_epitech/workdir/perso/libmy/tmp/lib/my/src/malloc
** 
** Made by Benjamin Viguier
** Login   <benjamin.viguier@epitech.eu>
** 
** Started on  Wed Apr 26 15:27:18 2017 Benjamin Viguier
** Last update Thu Apr 27 18:58:20 2017 Benjamin Viguier
*/

#ifndef LIBMY_HASH_H_
# define LIBMY_HASH_H_

# include <unistd.h>
# include <stdint.h>

# define HM_NOCLONE_KEY	0b001
# define HM_CLONE_VALUE	0b010
# define HM_NO_OVERWR	0b100
# define HM_NO_OPTS	0b000

# define HM_KEY_NEED_FREE	0b01
# define HM_VALUE_NEED_FREE	0b10

# define MIN_TAB_SIZE	16

typedef uint32_t	(*t_hash_fct)(const void*, size_t, uint32_t);

typedef enum	e_hashm_type
  {
    HM_EMPTY		= 0,
    HM_VALUE		= 1,
    HM_SUB_HASHMAP	= 2,
  }		t_hashm_type;

typedef struct	s_hashmap_val
{
  void		*value;
  void		*key;
  size_t	key_len;
  char		free_opts;
}		t_hashmap_val;

typedef union	u_hashmap_uni
{
  void		*sub;
  t_hashmap_val	value;
}		t_hashmap_uni;

typedef struct	s_hashmap_tab
{
  t_hashm_type	type;
  t_hashmap_uni	uni;
}		t_hashmap_tab;

typedef struct	s_hashmap
{
  unsigned	dim;
  size_t	size;
  t_hash_fct	hfct;
  int		itm_nbr;
  t_hashmap_tab	tab[];
}		t_hashmap;

typedef struct	s_hashmap_opts
{
  void		*key;
  size_t	key_len;
  void		*value;
  int		opts;
  size_t	value_len;
}		t_hashmap_opts;

/*
** hash Map functions
*/
t_hashmap	*hashmap_create(size_t len, t_hash_fct fct);
int		hashmap_push(t_hashmap *hm, t_hashmap_opts opts);

/*
** Hash Functions
*/
uint32_t	murmur3_32(const void *key, size_t len, uint32_t seed);

#endif /* !LIBMY_HASH_H_ */
