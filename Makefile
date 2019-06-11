C = gcc

NAME = libftprintf.a

FLAGS = -Wall -Wextra -Werror

LIBFT = libft

SRC = src

DIR_O = obj

HEADER = include

SOURCES = ft_printf.c \
		  print_int.c \
		  print_string.c \
			print_pointer.c \
			print_float.c \
			print_binary.c \
			arg.c \
			flag.c \
			get_arg.c \
		  strjoin.c \
		  itoa_base.c \
		  ft_pow.c \
		  integer.c \
		  convert.c \
		  caster.c \
		  free.c \
		  functions.c \
			putter.c \
			exception.c \
			except.c \
			itoa.c

SRC_LIB = ft_memset.c \
			ft_bzero.c \
			ft_memcpy.c \
			ft_memccpy.c \
			ft_memmove.c \
			ft_memcmp.c \
			ft_memchr.c \
			ft_strlen.c \
			ft_strdup.c \
			ft_strcpy.c \
			ft_strncpy.c \
			ft_strcat.c \
			ft_strncat.c \
			ft_strchr.c \
		  ft_strlcat.c \
		 	ft_strstr.c \
			ft_strnstr.c \
			ft_strrchr.c \
			ft_strcmp.c \
			ft_strncmp.c \
			ft_atoi.c \
			ft_isalpha.c \
			ft_isdigit.c \
			ft_isalnum.c \
			ft_isascii.c \
			ft_isprint.c \
			ft_toupper.c \
			ft_tolower.c \
			ft_memalloc.c \
			ft_memdel.c \
			ft_strnew.c \
			ft_strdel.c \
			ft_strclr.c \
			ft_striter.c \
			ft_striteri.c \
			ft_strmap.c \
			ft_strmapi.c \
			ft_strequ.c \
			ft_strnequ.c \
			ft_strsub.c \
			ft_strjoin.c \
			ft_strtrim.c \
			ft_strndup.c \
			ft_abs.c \
			ft_putchar.c \
			ft_putnbr.c \
			ft_putnstr.c \
			ft_itoa.c \
			ft_putchar_fd.c \
			ft_putstr_fd.c \
			ft_putendl_fd.c \
			ft_putnbr_fd.c \
			ft_putstr.c \
			ft_putendl.c \
			ft_strtrim.c \
			ft_strsplit.c \
			ft_print_list.c \
			ft_lstnew.c \
			ft_lstdelone.c \
			ft_lstdel.c \
			ft_lstadd.c \
			ft_lstiter.c \
			ft_lstmap.c \
			ft_sort_integer_table.c \
			ft_strrev.c \
			ft_swap.c \
			ft_recursive_factorial.c \
			ft_recursive_power.c \
			ft_sqrt.c \
			ft_is_prime.c

SRCS = $(addprefix $(SRC)/,$(SOURCES))

OBJS = $(addprefix $(DIR_O)/,$(SOURCES:.c=.o))

OBJECTS	= $(SRC_LIB:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@echo "$(_GREEN)[OK] $(_BLUE)Tous les objets sont generes\r"
	@ar rc $(NAME) $(OBJECTS) || printf "\n$(_RED)[ERREUR]$(_GRAY) Une est erreur est survenue $(_WHITE)$(NAME)\n"
	@ranlib $(NAME)
	@cp libft/libft.a ./$(NAME)
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)

$(DIR_O)/%.o: $(SRC)/%.c
	@mkdir -p obj
	@$(CC) $(FLAGS) -I $(HEADER) -o $@ -c $<

exe: all
	gcc $(NAME) src/main.c -o ft_printf


clean:
	@rm -f $(OBJS)
	@rm -rf $(DIR_O)
	@make clean -C $(LIBFT)

fclean: clean
	@rm -f $(NAME)
	@make fclean -C $(LIBFT)

re: fclean all
