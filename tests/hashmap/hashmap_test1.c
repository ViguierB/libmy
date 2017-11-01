/*
** hashmap_test1.c for test-hashmap in /home/benji_epitech/workdir/libmy/tests/hashmap
**
** Made by Benjamin Viguier
** Login   <benjamin.viguier@epitech.eu>
**
** Started on  Tue Oct 31 18:42:50 2017 Benjamin Viguier
** Last update Tue Oct 31 19:31:51 2017 Benjamin Viguier
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <time.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include "libmy.h"
#include "libmy_hash.h"

LMY_CONSTRUCTOR int	init_random(void)
{
  int	fd;
  int	seed;

  if ((fd = open("/dev/urandom", O_RDONLY)) >= 0)
    {
      read(fd, &seed, sizeof(seed));
      close(fd);
    }
  else
    seed = time(NULL);
  srand(seed);
  return (0);
}

t_hashmap_value *get_random_value(int rangeA, int rangeB)
{
    char *getRandomStr(void) {
        int len = (rand() % (rangeB - rangeA)) + rangeA;
        char *tmp = malloc(len);
        if (!tmp)
        {
            my_fprintf(g_err, "ERROR !!   Out of memory.\n");
            exit(84);
        }
        char *cur = tmp;
        while (--len)
            *(cur++) = (rand() % (126 - 33)) + 33;
        *cur = 0;
        return tmp;
    }
    char *key = getRandomStr();
    char *value = getRandomStr();
    return hm_f_ss(key, value);
}

int main()
{
    t_hashmap   *hm;

    hm = hashmap_create(128, NULL);

    for (int i = 0; i < 128; i++)
        hashmap_push(hm, get_random_value(15, 150));
}