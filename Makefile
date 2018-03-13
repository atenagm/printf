C = clang

NAME = libftprintf.a

FLAGS = -Wall -Wextra -Werror -O2

LIBFT = libft

DIR_S = src

DIR_O = temporary

MAIN = main.c

SOURCES = 	ft_func_dd.c \
			ft_func_f.c \
			ft_func_x.c \
			ft_func_i_d.c \
			ft_function_float.c \
			f_func_o.c \
			ft_functions.c \
			ft_identifiers.c \
			ft_func_p.c \
			ft_print_itoabase_int.c \
			ft_data_clean.c \
			ft_func_s.c \
			ft_print_itoabase_long.c \
			ft_func_c.c \
			ft_printf.c \
			ft_func_u.c \
			ft_putchar_i.c \
			ft_print_mod.c \
			ft_specificator.c

SRCS = $(addprefix $(DIR_S)/,$(SOURCES))

OBJS = $(addprefix $(DIR_O)/,$(SOURCES:.c=.o))

all: $(NAME)

$(NAME): $(OBJS)
	@make -C $(LIBFT)
	@cp libft/libft.a ./$(NAME)
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)

$(DIR_O)/%.o: $(DIR_S)/%.c
	@mkdir -p temporary
	@$(CC) $(FLAGS) -o $@ -c $<

norme:
	norminette ./libft/
	@echo
	norminette ./$(DIR_S)/

test:
	make re
	$(CC) $(NAME) $(MAIN)
	./a.out

clean:
	@rm -f $(OBJS)
	@rm -rf $(DIR_O)
	@make clean -C $(LIBFT)

fclean: clean
	@rm -f $(NAME)
	@make fclean -C $(LIBFT)

re: fclean all