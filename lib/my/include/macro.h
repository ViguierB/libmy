/*
** macro.h for libmy in /home/ben/epitech/libmy/tmp/lib/my
** 
** Made by Benjamin Viguier
** Login   <benjamin.viguier@epitech.eu>
** 
** Started on  Wed May 10 17:21:19 2017 Benjamin Viguier
** Last update Thu Jun  1 17:35:41 2017 Benjamin Viguier
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
# define LMY_AUTOFREE		__attribute__((__cleanup__(&free)))
# define LMY_CLEANUP(fct)	__attribute__((__cleanup__(fct)))
# define LMY_PACKED		__attribute__((packed))

# if defined __x86_64__
#  define LMY_WORDSIZE_64
typedef long unsigned	LMY_WORD;
# else
#  define LMY_WORDSIZE_32
typedef unsigned	LMY_WORD;
# endif

# define MEM_CLONE_32(c) (c << 24 | c << 16 | c << 8 | c)

# ifdef LMY_WORDSIZE_32
#  define MEM_CLONE(c)	MEM_CLONE_32(c)
#  define MASK01	0x01010101
#  define MASK80	0x80808080
# else
#  define MEM_CLONE(c) ((MEM_CLONE_32(c) << 32) | MEM_CLONE_32(c))
#  define MASK01	0x0101010101010101
#  define MASK80	0x8080808080808080
# endif

#endif /* !MACRO_H_ */
