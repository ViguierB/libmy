/*
** my_hashmap_utils.c for libmy in /home/benji_epitech/workdir/libmy/lib/my/src/hash
**
** Made by Benjamin Viguier
** Login   <benjamin.viguier@epitech.eu>
**
** Started on  Wed Nov 01 17:47:46 2017 Benjamin Viguier
** Last update Wed Nov 01 20:08:57 2017 Benjamin Viguier
*/

#include "libmy_hash.h"

t_hashmap_element *get_hashmap_element(void *key, const size_t key_len, 
                                        void *value, const size_t value_len)
{
    static t_hashmap_element  res_value;

    res_value = (t_hashmap_element) {
        .key = key,
        .key_len = key_len,
        .value = value,
        .value_len = value_len
    };
    return (&res_value);
}