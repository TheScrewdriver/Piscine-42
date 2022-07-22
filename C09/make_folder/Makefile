# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/16 09:33:17 by rbroque           #+#    #+#              #
#    Updated: 2022/07/18 01:16:22 by rbroque          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

### SRCS

PATH_SRCS = srcs

_SRCS += ft_putchar
_SRCS += ft_swap
_SRCS += ft_putstr
_SRCS += ft_strlen
_SRCS += ft_strcmp

vpath %.c $(PATH_SRCS)

SRCS = $(patsubst %, $(PATH_SRCS)/%, $(_SRCS))

### OBJS

OBJS = $(patsubst %, %.o, $(SRCS))

### INCLUDES

INCLUDES = -I./includes

### COMPILATION

CC = gcc
CFLAGS = -Wall
CFLAGS = -Wextra
CFLAGS = -Werror

### LIB

LIB_NAME = libft.a

### COMMAND

RM = rm -f

### RULES

all: ${LIB_NAME}

${OBJS}:
	for i in $(SRCS) ; do \
		$(CC) $(CFLAGS) -c $$i.c -o $$i.o ${INCLUDES}; \
	done

${LIB_NAME}: ${OBJS}
	ar rc $(LIB_NAME) $(OBJS)

clean:
	${RM} ${OBJS}

fclean: clean
	${RM} $(LIB_NAME)

re: fclean all
