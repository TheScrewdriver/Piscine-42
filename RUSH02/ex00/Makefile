# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/16 12:57:35 by rbroque           #+#    #+#              #
#    Updated: 2022/07/23 09:53:43 by rbroque          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = rush-02

### SRCS

PATH_SRCS = srcs

SRCS += string.c
SRCS += parser.c
SRCS += read_file.c
SRCS += rush02.c

vpath %.c $(PATH_SRCS)

### OBJS

PATH_OBJS = objs

OBJS = $(patsubst %.c, $(PATH_OBJS)/%.o, $(SRCS))

### INCLUDES

INCLUDES = includes/

HEADER += rush02.h

vpath %.h $(INCLUDES)

### COMPILATION

CC = gcc
CFLAGS += -Wall
CFLAGS += -Wextra
CFLAGS += -Werror

### COMMAND

RM = rm -fr

### RULES

all: $(NAME)

$(NAME): $(OBJS)
#	$(CC) $(CFLAGS) $^ -o $@ -I $(INCLUDES)

$(PATH_OBJS):
	mkdir $@

$(OBJS): $(PATH_OBJS)/%.o: %.c $(HEADER) $(PATH_OBJS)
	$(CC) $(CFLAGS) -c $< -o $@ -I $(INCLUDES)

clean:
	${RM} ${PATH_OBJS}/${OBJS}

fclean: clean
	${RM} $(NAME)

re: fclean
	$(MAKE)

.PHONY: all clean fclean re
