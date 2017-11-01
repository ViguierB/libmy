/*
** libmy_hash.h for libmy in /home/benji_epitech/workdir/perso/libmy/tmp/lib/my/src/malloc
** 
** Made by Benjamin Viguier
** Login   <benjamin.viguier@epitech.eu>
** 
** Started on  Wed Apr 26 15:27:18 2017 Benjamin Viguier
** Last update Wed Nov 01 20:10:19 2017 Benjamin Viguier
*/

#ifndef LIBMY_HASH_H_
# define LIBMY_HASH_H_

# include "libmy.h"
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
# define DEFAULT_FACTOR   0.75

typedef uint32_t	(*t_hash_fct)(const void*, size_t, uint32_t);

typedef enum  e_hashmap_result
{
  HM_SUCCESS  = 0b0000,
  HM_ERROR    = 0b0001,
  HM_FULL     = 0b0010,
  HM_VOID     = 0b0100,
  HM_OUTOFMEM = 0b1000
}             t_hashmap_result;

typedef enum  e_hashmap_type
{
  HM_EMPTY    = 0b00,
  HM_ELEMENT  = 0b01,
  HM_CLIST    = 0b10
}             t_hashmap_type;

typedef struct  s_hashmap_element
{
  void          *key;
  size_t        key_len;
  void          *value;
  size_t        value_len;
}               t_hashmap_element;

typedef union       u_hashmap_value
{
  t_clist           *clist;
  t_hashmap_element elem;
}                   t_hashmap_value;

typedef struct    s_bucket_elem
{
  t_hashmap_type  type;
  t_hashmap_value value;
}                 t_bucket_elem;

typedef struct    s_hashmap
{
  size_t          size;
  size_t          initial_size;
  size_t          used;
  float           load_factor;
  t_hash_fct      hash_fct;
  t_bucket_elem   *bucket;
}                 t_hashmap;

t_hashmap         *hashmap_create(const char *options, ...);
t_hashmap_result  hashmap_push(t_hashmap *hm, t_hashmap_element *value);
t_hashmap_result  hashmap_remove(t_hashmap *hm, t_hashmap_element *key,
                                    void (*free_fct)(t_hashmap_element *));
t_hashmap_result  hashmap_rehash(t_hashmap *hm, size_t new_size);
t_hashmap_element *get_hashmap_element(void *key, const size_t key_len, 
                                        void *value, const size_t value_len);
t_hashmap_element *hm_f_ss(char *key, char *value);
t_hashmap_element *hm_f_sh(char *key, void *value, const size_t value_len);

/*
** Hash Functions
*/
uint32_t	murmur3_32(const void *key, size_t len, uint32_t seed);

#endif /* !LIBMY_HASH_H_ */
