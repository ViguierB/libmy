/*
** my_clist_qsort.c for libmy in /home/benji_epitech/workdir/perso/libmy/tmp/lib/my/src
** 
** Made by Benjamin Viguier
** Login   <benjamin.viguier@epitech.eu>
** 
** Started on  Fri Apr 14 16:12:39 2017 Benjamin Viguier
** Last update Fri Apr 14 19:34:28 2017 Benjamin Viguier
*/

#include "libmy.h"

static void	__libmy_qsort_loop(t_clist_elm **pcur, t_clist_elm **pwall,
				   t_clist_elm *pivot, t_elm_cmp cmp_fct)
{
  t_clist_elm	*cur;
  t_clist_elm	*wall;

  cur = *pcur;
  wall = *pwall;
  while (1)
    {
      while (wall != cur && cmp_fct(wall->ptr, pivot->ptr) < 0)
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
  *pcur = cur;
}

static void	__libmy_qsort(t_clist_elm *start, t_clist_elm *end,
			      t_elm_cmp cmp_fct)
{
  t_clist_elm	*pivot;
  t_clist_elm	*cur;
  t_clist_elm	*wall;

  if (start->next == end)
    return;
  cur = end->prev;
  wall = start->next;
  if (wall == cur)
    {
      if (cmp_fct(start->ptr, cur->ptr) > 0)
	clist_swap_val(start, cur);
      return;
    }
  pivot = start;
  __libmy_qsort_loop(&cur, &wall, pivot, cmp_fct);
  if (cmp_fct(wall->ptr, pivot->ptr) < 0)
    clist_swap_val(wall, pivot);
  __libmy_qsort(start, wall, cmp_fct);
  if (wall->next != end)
    __libmy_qsort(wall->next, end, cmp_fct);
}

void	clist_qsort(t_clist *list, t_elm_cmp cmp_fct)
{
  if (list)
    __libmy_qsort(list, list, cmp_fct);
}
