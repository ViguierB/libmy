/*
** main.c for openclassroom in /home/benji_epitech/workdir/perso/libmy/tests_Qsort/tmp
** 
** Made by Benjamin Viguier
** Login   <benjamin.viguier@epitech.eu>
** 
** Started on  Sat May 27 11:51:33 2017 Benjamin Viguier
** Last update Sat May 27 12:56:18 2017 Benjamin Viguier
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

int	main(int ac, char **av)
{
  char	c;
  int	fd;
  FILE	*file;
  
  if (ac > 2)
    {
      if (strcmp(av[1], "read") == 0)
	{
	  if ((fd = open(av[2], O_RDONLY)) < 0)
	    return (84);
	  while (read(fd, &c, 1) > 0);
	  close(fd);
	}
      else if (strcmp(av[1], "fread") == 0)
	{
	  if ((file = fopen(av[2], "r")) == NULL)
	    return (84);
	  while (fread(&c, 1, 1, file) > 0);
	  fclose(file);
	}
      else
	{
	  fprintf(stderr, "Bye.\n");
	  return (84);
	}
    }
  return (0);
}
