/*
** clist.c for libmy in /home/benji_epitech/System_Unix/PSU_2016_my_ls
** 
** Made by Benjamin Viguier
** Login   <benjamin.viguier@epitech.eu>
** 
** Started on  Wed Nov 23 17:41:40 2016 Benjamin Viguier
** Last update Tue Dec 13 16:20:23 2016 Benjamin Viguier
*/

#include "my.h"
#include "libmy.h"

t_clist		*clist_push(t_clist *first, void *ptr)
{
  t_clist_elm	*n_elm;
  t_clist_elm	*last;

  n_elm = malloc(sizeof(t_clist_elm));
  if (n_elm == NULL)
    return (NULL);
  n_elm->ptr = ptr;
  if (first)
    {
      last = first->prev;
      last->next = n_elm;
      first->prev = n_elm;
      n_elm->next = first;
      n_elm->prev = last;
    }
  else
    {
      n_elm->prev = n_elm;
      n_elm->next = n_elm;
      return (n_elm);
    }
  return (first);
}

void	clist_swap_val(t_clist_elm *elm1, t_clist_elm *elm2)
{
  void	*tmp;

  tmp = elm1->ptr;
  elm1->ptr = elm2->ptr;
  elm2->ptr = tmp;
}

void		clist_free_data(t_clist *l, void (*myfree)(void*))
{
  t_clist_elm	*elm;
  int		cont;

  elm = l;
  cont = 1;
  l->prev->next = l->prev;
  while (elm && l && cont)
    {
      l = l->next;
      if (elm == l)
	cont  = 0;
      if (elm)
	{
	  myfree(elm->ptr);
	  free(elm);
	}
      elm = l;
    }
}

void		clist_free(t_clist *l)
{
  t_clist_elm	*elm;
  int		cont;

  elm = l;
  cont = 1;
  l->prev->next = l->prev;
  while (elm && l && cont)
    {
      l = l->next;
      if (elm == l)
	cont  = 0;
      free(elm);
      elm = l;
    }
}
