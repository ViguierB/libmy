/*
** libmy_hash.h for libmy in /home/benji_epitech/workdir/perso/libmy/tmp/lib/my/src/malloc
** 
** Made by Benjamin Viguier
** Login   <benjamin.viguier@epitech.eu>
** 
** Started on  Wed Apr 26 15:27:18 2017 Benjamin Viguier
** Last update Wed Apr 26 15:48:12 2017 Benjamin Viguier
*/

#ifndef LIBMY_HASH_H_
# define LIBMY_HASH_H_

# include <unistd.h>
# include <stdint.h>

uint32_t	murmur3_32(const void *key, size_t len, uint32_t seed);

#endif /* !LIBMY_HASH_H_ */
