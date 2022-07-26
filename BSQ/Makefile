# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/16 12:57:35 by rbroque           #+#    #+#              #
#    Updated: 2022/07/26 14:02:50 by rbroque          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = bsq

### SRCS

PATH_SRCS = srcs

SRCS += display.c
SRCS += error.c
SRCS += free.c
SRCS += ft_split.c
SRCS += ft_stradd.c
SRCS += main.c
SRCS += map.c
SRCS += math.c
SRCS += parsing.c
SRCS += read_file.c
SRCS += solve.c
SRCS += strings.c

vpath %.c $(PATH_SRCS)

### OBJS

PATH_OBJS = objs

OBJS = $(patsubst %.c, $(PATH_OBJS)/%.o, $(SRCS))

### INCLUDES

INCLUDES = includes/

HEADER += bsq.h

vpath %.h $(INCLUDES)

### COMPILATION

CC = gcc
CFLAGS += -Wall
CFLAGS += -Wextra
CFLAGS += -Werror

ifeq ($(debug), true)
	CFLAGS += -g3
	CFLAGS += -fsanitize=address,undefined
endif

### RULES

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@ -I $(INCLUDES)

$(OBJS): $(PATH_OBJS)/%.o: %.c $(HEADER)
	mkdir -p $(PATH_OBJS)
	$(CC) $(CFLAGS) -c $< -o $@ -I $(INCLUDES)

clean:
	$(RM) -R $(PATH_OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean
	$(MAKE)

.PHONY: all clean fclean re
