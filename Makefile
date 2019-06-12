C = gcc
NAME = libftprintf.a
FLAGS = -Wall -Wextra -Werror
LIBFT = libft
SRC = src
DIR_O = obj
HEADER = includes

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
			itoa.c \
			\
			ft_isdigit.c \
			ft_itoa.c \
			ft_memalloc.c \
			ft_memdel.c \
			ft_putchar.c \
			ft_putstr.c \
			ft_putnbr.c \
			ft_strdup.c \
			ft_strchr.c \
			ft_strnew.c \
			ft_strsub.c \
			ft_abs.c \
			ft_bzero.c \
			ft_strlen.c \
			ft_strncpy.c \
			ft_memset.c

SRCS = $(addprefix $(SRC)/,$(SOURCES))

OBJS = $(addprefix $(DIR_O)/,$(SOURCES:.c=.o))

all: $(NAME)

$(NAME): $(OBJS)
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)

$(DIR_O)/%.o: $(SRC)/%.c
	@mkdir -p obj
	@$(CC) $(FLAGS) -I $(HEADER) -o $@ -c $<

exe: all
	gcc $(NAME) src/main.c -o ft_printf

norme:
	norminette ./includes/
	@echo
	norminette ./src/

clean:
	@rm -f $(OBJS)
	@rm -rf $(DIR_O)

fclean: clean
	@rm -f $(NAME)

re: fclean all
