#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int ac, char **av)
{
  srand(time(NULL));
  if (ac < 4)
    {
      printf("usage = ./gen nbtest len max\n");
      return (84);
    }
  int	nbtest = atoi(av[1]);
  int	len = atoi(av[2]);
  int	max = atoi(av[3]);
  int	i;
  while (nbtest-- > 0)
    {
      i = 0;
      while (i++ < len)
	{
	  printf("%d", (rand() % max));
	  if (len)
	    printf(" ");
	}
      printf("\n");
    }
  return (0);
}
