##
## depend.mk for all in /home/benji_epitech/System_Unix/PSU_2016_my_printf
## 
## Made by Benjamin Viguier
## Login   <benjamin.viguier@epitech.eu>
## 
## Started on  Wed Nov  9 17:16:44 2016 Benjamin Viguier
## Last update Wed May 10 16:56:12 2017 Benjamin Viguier
##

CC		=	gcc

AR		=	ar rc

DEBUG		=	true

WALL		=	true

RELEASE		=	false

ALLOW_OPEN	=	true

ALLOW_LSEEK	=	true

OPTI_FLAG	=	-O3 -fno-builtin

ifeq	($(WALL),true)
 CFLAGS		+=	-W -Wall -Wextra
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
