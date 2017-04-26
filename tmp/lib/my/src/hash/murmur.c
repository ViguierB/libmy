/*
** murmur.c for libmy in /home/benji_epitech/workdir/perso/libmy/tmp/lib/my/src
** 
** Made by Benjamin Viguier
** Login   <benjamin.viguier@epitech.eu>
** 
** Started on  Mon Apr 10 13:42:28 2017 Benjamin Viguier
** Last update Wed Apr 26 15:49:15 2017 Benjamin Viguier
*/

#include <stdint.h>
#include <sys/types.h>

static uint32_t		murmur3_32_case2(const uint8_t **key, size_t len, uint32_t h)
{
  size_t		i;
  uint32_t		k;
  
  i = len & 3;
  k = 0;
  *key = key[i - 1];
  while (--i)
    {
      k <<= 8;
      k |= *(*key)--;
    }
  k *= 0xcc9e2d51;
  k = (k << 15) | (k >> 17);
  k *= 0x1b873593;
  h ^= k;

  return (h);
}

static uint32_t		murmur3_32_case1(const uint8_t **key, size_t len, uint32_t h)
{
  const uint32_t*	key_x4;
  size_t		i;
  uint32_t		k;

  key_x4= (const uint32_t*) *key;
  i = len >> 2;
  while (--i)
    {
      k = *key_x4++;
      k *= 0xcc9e2d51;
      k = (k << 15) | (k >> 17);
      k *= 0x1b873593;
      h ^= k;
      h = (h << 13) | (h >> 19);
      h += (h << 2) + 0xe6546b64;
    }
  *key = (const uint8_t*) key_x4;
  return (h);
}

uint32_t	murmur3_32(const void *mkey, size_t len, uint32_t seed)
{
  const uint8_t *key = mkey;
  uint32_t	h;

  h = seed;
  if (len > 3)
    h = murmur3_32_case1(&key, len, h);
  if (len & 3)
    h = murmur3_32_case2(&key, len, h);
  h ^= len;
  h ^= h >> 16;
  h *= 0x85ebca6b;
  h ^= h >> 13;
  h *= 0xc2b2ae35;
  h ^= h >> 16;
  return (h);
}
