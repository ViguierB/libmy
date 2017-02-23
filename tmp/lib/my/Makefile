##
## Makefile<PSU_2016_my_printf_bootstrap> for Makefile_my_printf in /home/benji_epitech/C_Prog_Elem/PSU_2016_my_printf_bootstrap
## 
## Made by Benjamin Viguier
## Login   <benjamin.viguier@epitech.net>
## 
## Started on  Tue Nov  8 18:23:40 2016 Benjamin Viguier
## Last update Thu Feb 23 18:04:31 2017 Benjamin Viguier
##

include $(shell pwd)/include/depend.mk

AR	=	ar rc

SRC	=	my_strlen.c		\
		my_strcpy.c		\
		my_strncpy.c		\
		my_strcmp.c		\
		my_split.c		\
		my_atoi.c		\
		my_strconca.c		\
		my_trim.c		\
		clist.c			\
		my_showmem.c		\
		my_putnbr_base.c	\
		my_fd.c			\
		my_getline.c		\
		my_fread.c		\
		my_fd_write.c		\
		my_fd_std.c		\
		my_put.c		\
		my_memset.c		\
		my_memcpy.c		\
		my_memcmp.c		\
		my_memisempty.c		\
		my_isnum.c		\
		my_errno.c		\
		my_strbuilder.c		\
		my_strbuilder_ext.c

CFLAGS	+=	-I./include/

_OBJ    =	$(SRC:.c=.o)

OBJ	=	$(patsubst %,$(ODIR)/%,$(_OBJ))

NAME	=	libmy.a

all		:	$(NAME)

$(ODIR)/%.o	:	$(SDIR)/%.c
	$(CC) $(CFLAGS)	-c -o $@ $<

$(NAME)		:	$(OBJ)
	$(AR) $(NAME) $(OBJ)
	ranlib $(NAME)

clean		:
	rm -f $(OBJ)

fclean		:	clean
	rm -f $(NAME)

re		:	fclean all
