#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include "libmy.h"

void	trace(t_clist *q, t_clist *p, t_clist *b, clock_t qclk, clock_t pclk, int *passed, int *failed);

int	my_cmp_fct(long int a, long int b)
{
  if (a < b)
    return (-1);
  else if (a == b)
    return (0);
  else
    return (1);
}

int	my_bad_cmp_fct(long int a, long int b)
{
  if (a < b)
    return (-1);
  else if (a > b)
    return (0);
  else
    return (1);
}

void	print_list(FILE* mout, t_clist *list)
{
  t_clist_elm *elm;

  elm = list;
  while (elm)
    {
      fprintf(mout, "%ld", (long int) elm->ptr);
      elm = CLIST_NEXT(list, elm);
      if (elm)
	fprintf(mout, " ");
    }
  fprintf(mout, "\n");
}

int main(int ac, char **av)
{
  t_my_fd	*in_;
  char		*str;
  char		**tmp;
  char		**tmp2;
  t_clist	*blist = NULL;
  t_clist	*qlist = NULL;
  t_clist	*plist = NULL;
  int		fail = 0;
  int		passed = 0;
  int		count = 0;
  clock_t	qclk;
  clock_t	pclk;

  in_ = my_fd_from_fd(0);
  while (1)
    {
      str = my_getline(in_);
      if (!str || !(*str))
	break;
      tmp = my_split(str, ' ', NULL);
      tmp2 = tmp;
      while (*tmp)
	{
	  long int	val = atoi(*tmp);
	  qlist = clist_push(qlist, (void*) val);
	  plist = clist_push(plist, (void*) val);
	  blist = clist_push(blist, (void*) val);
	  tmp++;
	}
      count++;
      free(*tmp2);
      free(tmp2);
      free(str);
      pclk = clock();
      clist_sort(plist, (t_elm_cmp) &my_cmp_fct);
      pclk = clock() - pclk;
      qclk = clock();
      clist_qsort(qlist, (t_elm_cmp) &my_cmp_fct);
      qclk = clock() - qclk;
      trace(qlist, plist, blist, qclk, pclk, &passed, &fail);
      if (blist)
	clist_free(blist);
      blist = NULL;
      if (qlist)
	clist_free(qlist);
      qlist = NULL;
      if (plist)
	clist_free(plist);
      plist = NULL;
    }
  printf("Passed : \e[1;32m%d (%d %%)\e[0m, failed : \e[1;31m%d (%d %%)\e[0m\nBye Bye :3\n",
	 passed, passed * 100 / count, fail,  fail * 100 / count);
  my_fclose(in_);
  return (0);
}

int	verif(t_clist *q, t_clist *p)
{
  t_clist_elm *qelm;
  t_clist_elm *pelm;

  pelm = p;
  qelm = q;
  while (qelm && pelm)
    {
      if (qelm->ptr != pelm->ptr)
	return (0);
      qelm = CLIST_NEXT(q, qelm);
      pelm = CLIST_NEXT(p, pelm);
    }
  if (qelm || pelm)
	return (0);
  return (1);
}

void	trace(t_clist *q, t_clist *p, t_clist *b, clock_t qclk, clock_t pclk, int *passed, int *failed)
{
  static int	count;
  int		res;

  res = verif(q, p);
  printf("Round n°%d : ", ++count);
  if (!res)
    {
      fprintf(stderr, "\nTRACE FOR (Round n°%d):\n", count);
      fprintf(stderr, "blist : ");
      print_list(stderr, b);
      fprintf(stderr, "checking :\n");
      fprintf(stderr, "plist : ");
      print_list(stderr, p);
      fprintf(stderr, "qlist : ");
      print_list(stderr, q);
      fprintf(stderr, "%s\e[0m\n", ((res != 0) ? "\e[1;32mOK!" : "\e[1;31mKO!"));
      fprintf(stdout, "%s\e[0m  ", ((res != 0) ? "\e[1;32mOK!" : "\e[1;31mKO!"));
      *failed += 1;
    }
  else
    {
      *passed += 1;
      printf("%s\e[0m  ", ((res != 0) ? "\e[1;32mOK!" : "\e[1;31mKO!"));
    }
  printf("Insert sort = %d ms, Quick sort = %d ms\n", pclk, qclk);
}
