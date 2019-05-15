C = gcc

NAME = libftprintf.a

FLAGS = -Wall -Wextra -Werror 

LIBFT = libft

SRC = src

DIR_O = obj

HEADER = include

SOURCES = ft_printf.c \
		  print_int.c \
		  arg.c \
		  flag.c \
		  get_arg.c \
		  string.c \
		  integer.c \
		  functions.c \
		  percent.c \
		  convert.c \
		  caster.c \
		  free.c

SRCS = $(addprefix $(SRC)/,$(SOURCES))

OBJS = $(addprefix $(DIR_O)/,$(SOURCES:.c=.o))

all: $(NAME)

$(NAME): $(OBJS)
	@make -C $(LIBFT)
	@cp libft/libft.a ./$(NAME)
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)

$(DIR_O)/%.o: $(SRC)/%.c
	@mkdir -p obj
	@$(CC) $(FLAGS) -I $(HEADER) -o $@ -c $<

exe: all
	gcc $(NAME) src/main.c -o ft_printf

norme:
	norminette ./libft/
	@echo
	norminette ./$(HEADER)/
	@echo
	norminette ./$(SRC)/

clean:
	@rm -f $(OBJS)
	@rm -rf $(DIR_O)
	@make clean -C $(LIBFT)

fclean: clean
	@rm -f $(NAME)
	@make fclean -C $(LIBFT)

re: fclean all

