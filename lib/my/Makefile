##
## Makefile<PSU_2016_my_printf_bootstrap> for Makefile_my_printf in /home/benji_epitech/C_Prog_Elem/PSU_2016_my_printf_bootstrap
## 
## Made by Benjamin Viguier
## Login   <benjamin.viguier@epitech.net>
## 
## Started on  Tue Nov  8 18:23:40 2016 Benjamin Viguier
## Last update Wed May 24 19:10:59 2017 Benjamin Viguier
##

include ./include/depend.mk

CFLAGS	+=	-I./include/

ifeq	($(ALLOW_OPEN), true)
 CFLAGS	+=	-D ALLOW_OPEN
endif
ifeq	($(ALLOW_LSEEK), true)
 CFLAGS	+=	-D ALLOW_LSEEK
endif
ifeq	($(ALLOW_ISATTY), true)
 CFLAGS	+=	-D ALLOW_ISATTY
endif

SRC	=	my_strlen.c		\
		my_strcpy.c		\
		my_strncpy.c		\
		my_strcmp.c		\
		my_split.c		\
		my_atoi.c		\
		my_basic_funct.c	\
		my_strconca.c		\
		my_trim.c		\
		my_clist.c		\
		my_clist_rem.c		\
		my_clist_sort.c		\
		my_clist_qsort.c	\
		my_showmem.c		\
		my_putnbr_base.c	\
		my_put.c		\
		my_memset.c		\
		my_memcpy.c		\
		my_memcmp.c		\
		my_memisempty.c		\
		my_isnum.c		\
		my_errno.c		\
		my_strbuilder.c		\
		my_strbuilder_ext.c

IOSRC	=	my_fd.c		\
		my_getline.c	\
		my_fread.c	\
		my_fd_write.c	\
		my_fd_std.c

PFSRC	=	my_printf.c	\
		pf_flags.c	\
		pf_modifier.c	\
		pf_write.c	\
		pf_format.c	\
		pf_modif_va.c	\
		pf_wandp_ud.c	\
		pf_str.c	\
		pf_char.c	\
		pf_dec.c	\
		pf_hexa.c	\
		pf_bin.c	\
		pf_oct.c	\
		pf_nflag.c

HSRC	=	murmur.c		\
		my_hashmap_create.c	\
		my_hashmap_push.c

MLCSRC	=	my_malloc.c		\
		my_malloc_internal.c	\
		my_calloc.c

SIODIR	=	$(SDIR)/io
OIODIR	=	$(ODIR)

SPFDIR	=	$(SDIR)/io/my_printf
OPFDIR	=	$(ODIR)

SHDIR	=	$(SDIR)/hash
OHDIR	=	$(ODIR)

SMLCDIR	=	$(SDIR)/malloc
OMLCDIR	=	$(ODIR)

OBJ	=	$(patsubst %,$(ODIR)/%,$(SRC:.c=.o))
IOOBJ	=	$(patsubst %,$(OIODIR)/%,$(IOSRC:.c=.o))
PFOBJ	=	$(patsubst %,$(OPFDIR)/%,$(PFSRC:.c=.o))
HOBJ	=	$(patsubst %,$(OHDIR)/%,$(HSRC:.c=.o))
MLCOBJ	=	$(patsubst %,$(OMLCDIR)/%,$(MLCSRC:.c=.o))

NAME	=	libmy.a

all		:	echologo mkobj show_cflags $(NAME) warn_allow

echologo	:
	@printf	"\033[1;34m"
	@cat	./tools/logo.logo
	@printf	"\033[0m"
	@printf "\n"

show_cflags	:
	@printf	"Flags Actif : "
	@printf "\033[1;33m"
	@echo	$(CFLAGS)
	@printf	"\033[0m"

warn_allow	:
ifeq	($(ALLOW_OPEN), true)
	@printf	"\033[1;31m"
	@printf "/!\ OPEN & CLOSE	enabled\n"
	@printf	"\033[0m"
endif
ifeq	($(ALLOW_LSEEK), true)
	@printf	"\033[1;31m"
	@printf "/!\ LSEEK		enabled\n"
	@printf	"\033[0m"
endif
ifeq	($(ALLOW_ISATTY), true)
	@printf	"\033[1;31m"
	@printf "/!\ ISATTY		enabled\n"
	@printf	"\033[0m"
endif

$(ODIR)/%.o	:	$(SDIR)/%.c
	@printf	"[libmy] Compilation de "
	@printf	"\033[1;34m"
	@echo	$(notdir $<)
	@printf	"\033[0m"
	@$(CC) $(CFLAGS)	-c -o $@ $<

$(OPFDIR)/%.o	:	$(SIODIR)/%.c
	@printf	"[my_io] Compilation de "
	@printf	"\033[1;34m"
	@echo	$(notdir $<)
	@printf	"\033[0m"
	@$(CC) $(CFLAGS)	-c -o $(patsubst %,$(ODIR)/%,$(notdir $@)) $<

$(OPFDIR)/%.o	:	$(SPFDIR)/%.c
	@printf	"[my_printf] Compilation de "
	@printf	"\033[1;34m"
	@echo	$(notdir $<)
	@printf	"\033[0m"
	@$(CC) $(CFLAGS)	-c -o $(patsubst %,$(ODIR)/%,$(notdir $@)) $<

$(OHDIR)/%.o	:	$(SHDIR)/%.c
	@printf	"[hash] Compilation de "
	@printf	"\033[1;34m"
	@echo	$(notdir $<)
	@printf	"\033[0m"
	@$(CC) $(CFLAGS)	-c -o $(patsubst %,$(ODIR)/%,$(notdir $@)) $<

$(OMLCDIR)/%.o	:	$(SMLCDIR)/%.c
	@printf	"[my_malloc] Compilation de "
	@printf	"\033[1;34m"
	@echo	$(notdir $<)
	@printf	"\033[0m"
	@$(CC) $(CFLAGS)	-c -o $(patsubst %,$(ODIR)/%,$(notdir $@)) $<

mkobj		:
	@echo "Verification du dossier 'obj'";
	@./tools/verif_objdir;

$(NAME)		:	$(OBJ) $(IOOBJ) $(PFOBJ) $(HOBJ) $(MLCOBJ)
	@printf	"Creation de  "
	@printf	"\033[1;32m"
	@echo	$(NAME)
	@printf	"\033[0m"
	@$(AR) $(NAME) $(OBJ) $(IOOBJ) $(PFOBJ) $(HOBJ) $(MLCOBJ)
	@ranlib $(NAME)

clean		:
	@rm -rf	$(ODIR)

fclean		:	clean
	@rm -f	$(NAME)

re		:	fclean all
