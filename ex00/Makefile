# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/16 12:57:35 by rbroque           #+#    #+#              #
#    Updated: 2022/07/22 22:02:18 by rbroque          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

### SRCS

PATH_SRCS = srcs

_SRCS += string
_SRCS += parser
_SRCS += read_file
MAIN = rush02.c

vpath %.c $(PATH_SRCS)

SRCS = $(patsubst %, $(PATH_SRCS)/%.c, $(_SRCS))

### OBJS

PATH_OBJS = objs

_OBJS = $(patsubst %, %.o, $(_SRCS))
OBJS = $(patsubst %, $(PATH_OBJS)/%, $(_OBJS))

### INCLUDES

INCLUDES = -I./includes

### COMPILATION

CC = gcc
CFLAGS += -Wall
CFLAGS += -Wextra
CFLAGS += -Werror

NAME = rush-02

### COMMAND

RM = rm -fr

### RULES

all: $(NAME)

${OBJS}:
	mkdir -p $(PATH_OBJS)
	for i in $(_SRCS) ; do \
		$(CC) $(CFLAGS) -c $(PATH_SRCS)/$$i.c -o $(PATH_OBJS)/$$i.o ${INCLUDES}; \
	done

$(NAME): ${OBJS}
	$(CC) $(CFLAGS) -o $(NAME) $(PATH_SRCS)/$(MAIN) $(OBJS) ${INCLUDES}

clean:
	${RM} ${PATH_OBJS}/${OBJS}

fclean: clean
	${RM} $(NAME)

re: fclean all
