# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thallot <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/03 14:51:59 by thallot           #+#    #+#              #
#    Updated: 2019/05/09 12:06:34 by thallot          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

############## COLORS ##################
_WHITE=$ \x1b[37m
_BLUE=$ \x1b[36m
_GREEN=$ \033[1;32m
_GREY=$ \x1b[33m
_RED=$ \x1b[31m

############## FLAGS ##################

NAME= ft_printf
CC = gcc
CFLAGS = -Werror -Wall -Wextra

############## FILES ##################

SRC= main.c \
	 arg.c \
	 flag.c \
	 get_arg.c \
	 string.c \
	 integer.c
	

############## PATH ##################

OBJECTS	= $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJECTS)
	@$(CC) $(OBJECTS) libft/libft.a -o $(NAME)
	@echo "$(_GREEN)[OK] $(_BLUE)Compilation de $(_WHITE)$(NAME)"

%.o: %.c
	@$(CC) $(CFLAGS) -c $(SRC)

exe: all clean

clean:
	@rm -rf $(OBJECTS)
	@echo "$(_GREEN)[OK]$(_RED) Supression de tous les objets"

fclean: clean
	@rm -rf $(NAME) $(EXE)
	@echo "$(_GREEN)[OK]$(_RED) Supression de $(_WHITE)$(NAME)"
	@echo "$(_GREEN)[OK]$(_RED) Supression de tous les fichiers$(_WHITE)"

re: fclean all
	@echo "$(_GREEN)[OK]$(_BLUE) Succes $(_WHITE)"

.PHONY: clean fclean re all exe
