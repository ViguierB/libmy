##
## Makefile<PSU_2016_my_printf_bootstrap> for Makefile_my_printf in /home/benji_epitech/C_Prog_Elem/PSU_2016_my_printf_bootstrap
## 
## Made by Benjamin Viguier
## Login   <benjamin.viguier@epitech.net>
## 
## Started on  Tue Nov  8 18:23:40 2016 Benjamin Viguier
## Last update Mon Jan 30 18:11:36 2017 Benjamin Viguier
##

include $(shell pwd)/include/depend.mk

AR	=	ar rc

SRC	=	my_strlen.c		\
		my_strcpy.c		\
		my_strncpy.c		\
		my_strcmp.c		\
		my_split.c		\
		my_printf.c		\
		my_printf_extend.c	\
		need_space.c		\
		need_space_bis.c	\
		get_params.c		\
		verif_wap.c		\
		flag_format.c		\
		flag.c			\
		my_basic_funct.c	\
		stack.c			\
		param_t_val.c		\
		modif_spe_funt.c	\
		modif_spe_funt_bis.c	\
		print_int.c		\
		print_uint.c		\
		print_xhex.c		\
		print_char.c		\
		print_oct.c		\
		print_ptr.c		\
		print_bin.c		\
		my_strconca.c		\
		my_trim.c		\
		clist.c			\
		my_showmem.c		\
		my_putnbr_base.c	\
		my_fd.c			\
		my_getline.c		\
		my_put.c		\
		my_memset.c		\
		my_memcpy.c		\
		my_memcmp.c		\
		my_memisempty.c

CFLAGS	+=	-I./include/

OBJ	=	$(SRC:.c=.o)

NAME	=	libmy.a

all	:	$(NAME)

$(NAME)	:	$(OBJ)
	$(AR) $(NAME) $(OBJ)
	ranlib $(NAME)

clean	:
	rm -f $(OBJ)

fclean	:	clean
	rm -f $(NAME)

re	:	fclean all
