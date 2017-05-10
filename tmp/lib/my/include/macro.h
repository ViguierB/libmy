/*
** macro.h for libmy in /home/ben/epitech/libmy/tmp/lib/my
** 
** Made by Benjamin Viguier
** Login   <benjamin.viguier@epitech.eu>
** 
** Started on  Wed May 10 17:21:19 2017 Benjamin Viguier
** Last update Wed May 10 22:12:38 2017 Benjamin Viguier
*/

#ifndef MACRO_H_
# define MACRO_H_

# define LMY_TRUE	(1)
# define LMY_FALSE	(0)
# define PSQ(x)		((x) * (x))
# define MIN(a, b)	(((a) < (b)) ? (a) : (b))
# define MAX(a, b)	(((a) > (b)) ? (a) : (b))
# define ABS(a)		(((a) < 0) ? (-(a)) : (a))
# define ISUPPER(c)	(((c) >= 'A' && (c) <= 'Z') ? 1 : 0)
# define ISLOWER(c)	(((c) >= 'a' && (c) <= 'z') ? 1 : 0)
# define ISPRINTABLE(c)	(((c) >= 32 && (c) <= 126) ? 1 : 0)
# define ISQUOTE(c)	(((c) != '\'' || (c) != '\"' || (c) != '`') ? 0 : (c))
# define ISSPACE(c)	(((c) == ' ' || (c) == '\t') ? 1 : 0)
# define ISBLANK(c)	(((c) == ' ' || (c) == '\t' || (c) == '\n') ? 1 : 0)

# define LMY_CONSTRUCTOR	__attribute__((constructor))
# define LMY_DESTRUCTOR		__attribute__((destructor))
# define LMY_AUTOFREE		__attribute__((__cleanup__(free)))
# define LMY_CLEANUP(fct)	__attribute__((__cleanup__(fct)))
# define LMY_PACKED		__attribute__((packed))

#endif /* !MACRO_H_ */
