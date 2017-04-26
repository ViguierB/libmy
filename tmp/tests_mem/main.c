#include "libmy_malloc.h"
#include "libmy.h"
#include <time.h>

int main(int ac, char **av)
{
  clock_t	now;
  char	*buffer;
  int	size = ((ac > 1) ? atoi(av[1]) : 10000);
  
  buffer = my_malloc(size);
  now = clock();
  my_memset(buffer, 0, size);
  now = clock() - now;
  printf("new clock = %d\n", now);
  now = clock();
  /*
  my_oldmemset(buffer, 0, size);
  now = clock() - now;
  printf("old clock = %d\n", now);
  */
  my_showmem((void*) buffer, size);
  my_free(buffer);
  return (0);
}
