##
## depend.mk for all in /home/benji_epitech/System_Unix/PSU_2016_my_printf
## 
## Made by Benjamin Viguier
## Login   <benjamin.viguier@epitech.eu>
##
## Last update Wed May 24 11:51:10 2017 Benjamin Viguier
##

CC		=	gcc

AR		=	ar rc

DEBUG		=	true

WALL		=	true

RELEASE		=	false

OPTI_FLAG	=	-O3 -fno-builtin

ifeq	($(WALL),true)
 CFLAGS		+=	-W -Wall -Wextra -ansi
endif

ifeq	($(RELEASE),true)
 CFLAGS		+=	$(OPTI_FLAG)
 CFLAGS		+=	-Werror -Wno-unused-result
 DEBUG		=	false
else
 CFLAGS		+=	-O0
endif

ifeq	($(DEBUG),true)
 CFLAGS		+=	-g
endif

ODIR		=	obj

SDIR		=	src

## Project allowed function :
ALLOW_OPEN	=	true

ALLOW_LSEEK	=	true

ALLOW_ISATTY	=	true