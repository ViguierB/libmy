/*
** libmy_hash.h for libmy in /home/benji_epitech/workdir/perso/libmy/tmp/lib/my/src/malloc
** 
** Made by Benjamin Viguier
** Login   <benjamin.viguier@epitech.eu>
** 
** Started on  Wed Apr 26 15:27:18 2017 Benjamin Viguier
** Last update Sun Oct 22 13:11:36 2017 Benjamin Viguier
*/

#ifndef LIBMY_HASH_H_
# define LIBMY_HASH_H_

# include <unistd.h>
# include <stdint.h>

# define HM_NOCLONE_KEY	0b001
# define HM_CLONE_VALUE	0b010
# define HM_NO_OVERWR	  0b100
# define HM_NO_OPTS	    0b000

# define HM_KEY_NEED_FREE	  0b01
# define HM_VALUE_NEED_FREE 0b10

# define MIN_MAP_SIZE     16
# define DEFAULT_MAP_SIZE 1024

typedef uint32_t	(*t_hash_fct)(const void*, size_t, uint32_t);

typedef enum  e_hashmap_result
{
  HM_SUCCESS  = 0b000
  HM_ERROR    = 0b001
  HM_FULL     = 0b010
  HM_EMPTY    = 0b100
}             t_hashmap_result

typedef struct  s_hashmap_value
{
  void          *key;
  size_t        key_len;
  void          *value;
  size_t        value_len;
}               t_hashmap_value;

typedef struct    s_hashmap
{
  size_t          size;
  size_t          avalaible;
  t_hash_fct      hash_fct;
  t_hashmap_value map[];
}                 t_hashmap;

t_hashmap         hashmap_create(size_t len, t_hash_fct fct);
t_hashmap_result  *get_hashmap_value(void *key, uint32_t key_len, 
                                      void *value, uint32_t value_len);


/*
** Hash Functions
*/
uint32_t	murmur3_32(const void *key, size_t len, uint32_t seed);

#endif /* !LIBMY_HASH_H_ */
