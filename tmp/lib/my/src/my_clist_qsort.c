/*
** my_clist_qsort.c for libmy in /home/benji_epitech/workdir/perso/libmy/tmp/lib/my/src
** 
** Made by Benjamin Viguier
** Login   <benjamin.viguier@epitech.eu>
** 
** Started on  Fri Apr 14 16:12:39 2017 Benjamin Viguier
** Last update Mon Apr 17 20:47:12 2017 Benjamin Viguier
*/

#include "libmy.h"

static void	__libmy_qsort_loop(t_clist_elm *cur, t_clist_elm **pwall,
				   t_clist_elm *pivot, t_elm_cmp cmp_fct)
{
  t_clist_elm	*wall;

  wall = *pwall;
  while (1)
    {
      while (wall != cur && cmp_fct(wall->ptr, pivot->ptr) <= 0)
	wall = wall->next;
      if (wall == cur)
	break;
      while (wall != cur && cmp_fct(cur->ptr, pivot->ptr) > 0)
	cur = cur->prev;
      if (wall == cur)
	break;
      clist_swap_val(wall, cur);
    }
  *pwall = wall;
}

#include <stdio.h>
int             print_list(t_clist *list, t_clist *end);

static void	__libmy_qsort(t_clist_elm *start, t_clist_elm *end,
			      t_elm_cmp cmp_fct)
{
  t_clist_elm	*pivot;
  t_clist_elm	*cur;
  t_clist_elm	*wall;
  int		res;

  wall = start->next;
  if (wall == end)
    return;
  cur = end->prev;
  if (wall == cur)
    {
      if (cmp_fct(start->ptr, cur->ptr) > 0)
	clist_swap_val(start, cur);
      return;
    }
  pivot = start;
  //print_list(start, cur);
  //printf("\n");
  
  __libmy_qsort_loop(cur, &wall, pivot, cmp_fct);
  if ((res = cmp_fct(wall->ptr, pivot->ptr)) < 0)
    clist_swap_val(wall, pivot);
  cur = wall;
  
  // printf("Pivot : %ld\n"
	 //	 "Wall  : %ld\n", (long int) pivot->ptr, (long int) wall->ptr); 
  //fflush(stdout);

  while (cur != start && cur->prev != start && !cmp_fct(cur->prev->ptr, pivot->ptr))
    cur = cur->prev;
  
  //print_list(start, cur);
  //printf("\n\n");
  //fflush(stdout);

  __libmy_qsort(start, cur, cmp_fct);
  if (res < 0)
    wall = wall->next;
  while (wall != end && !cmp_fct(wall->ptr, pivot->ptr))
    wall = wall->next;
  if (wall != end)
    __libmy_qsort(wall, end, cmp_fct);
}

void	clist_qsort(t_clist *list, t_elm_cmp cmp_fct)
{
  if (list)
    __libmy_qsort(list, list, cmp_fct);
}
