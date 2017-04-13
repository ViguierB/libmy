##
## Makefile<PSU_2016_my_printf_bootstrap> for Makefile_my_printf in /home/benji_epitech/C_Prog_Elem/PSU_2016_my_printf_bootstrap
## 
## Made by Benjamin Viguier
## Login   <benjamin.viguier@epitech.net>
## 
## Started on  Tue Nov  8 18:23:40 2016 Benjamin Viguier
## Last update Thu Apr 13 18:15:41 2017 Benjamin Viguier
##

include ./include/depend.mk

CFLAGS	+=	-I./include/

ifeq	($(ALLOW_OPEN), true)
 CFLAGS	+=	-D ALLOW_OPEN
endif
ifeq	($(ALLOW_LSEEK), true)
 CFLAGS	+=	-D ALLOW_LSEEK
endif

SRC	=	my_strlen.c		\
		my_strcpy.c		\
		my_strncpy.c		\
		my_strcmp.c		\
		my_split.c		\
		my_atoi.c		\
		my_strconca.c		\
		my_trim.c		\
		my_clist.c		\
		my_clist_rem.c		\
		my_clist_sort.c		\
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

PFSRC	=	my_printf.c	\
		pf_flags.c	\
		pf_modifier.c	\
		pf_write.c	\
		pf_format.c	\
		pf_modif_va.c

HSRC	=	my_hash_table.c		\
		my_hash_table_utils.c	\
		murmur.c

SPFDIR	=	$(SDIR)/my_printf
OPFDIR	=	$(ODIR)

SHDIR	=	$(SDIR)/hash
OHDIR	=	$(ODIR)

OBJ	=	$(patsubst %,$(ODIR)/%,$(SRC:.c=.o))
PFOBJ	=	$(patsubst %,$(OPFDIR)/%,$(PFSRC:.c=.o))
HOBJ	=	$(patsubst %,$(OHDIR)/%,$(HSRC:.c=.o))

NAME	=	libmy.a

all		:	$(NAME)

echologo	:
	@echo -en "\033[1;34m"
	@cat ./tools/logo.logo
	@echo -e "\033[0m"

show_cflags	:
	@echo -e "Flags Actif :" "\033[1;33m"$(CFLAGS)"\033[0m";

$(ODIR)/%.o	:	$(SDIR)/%.c
	@echo -e "[libmy] Compilation de" "\033[1;34m"$(notdir $<)"\033[0m"
	@$(CC) $(CFLAGS)	-c -o $@ $<

$(OPFDIR)/%.o	:	$(SPFDIR)/%.c
	@echo -e "[my_printf] Compilation de" "\033[1;34m"$(notdir $<)"\033[0m"
	@$(CC) $(CFLAGS)	-c -o $(patsubst %,$(ODIR)/%,$(notdir $@)) $<

$(OHDIR)/%.o	:	$(SHDIR)/%.c
	@echo -e "[hash] Compilation de" "\033[1;34m"$(notdir $<)"\033[0m"
	@$(CC) $(CFLAGS)	-c -o $(patsubst %,$(ODIR)/%,$(notdir $@)) $<

mkobj		:
	@echo "Verification du dossier 'obj'";
	@./tools/verif_objdir;

$(NAME)		:	echologo mkobj show_cflags $(OBJ) $(PFOBJ) $(HOBJ)
	@echo -e "Creation de" "\033[1;32m"$(NAME)"\033[0m"
	@$(AR) $(NAME) $(OBJ) $(PFOBJ)
	@ranlib $(NAME)

clean		:
	@rm -rf	$(ODIR)

fclean		:	clean
	@rm -f	$(NAME)

re		:	fclean all
