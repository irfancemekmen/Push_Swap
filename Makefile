NAME = push_swap
LIBFT = libft
LIBFTM = libft/libft.a
PRINTF = ft_printf
PRINTFLIB = ft_printf/libftprintf.a
CC = cc -g
CFLAGS = -Wall -Wextra -Werror
CFILES = 	push_swap.c			\
			utils.c				\
			sort_func.c 		\
			sort_small_func.c	\
			sort.c				\
			swap.c				\
			push.c				\
			rotate.c			\
			r_rotate.c			\
			quick_sort.c		\
			free_error.c

OBJS = $(CFILES:.c=.o)

$(NAME): $(OBJS)
	make -C $(LIBFT)
	make -C $(PRINTF)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFTM) $(PRINTFLIB) -o $(NAME)

all: $(NAME)

clean:
		rm -rf $(OBJS)
		make clean -C $(LIBFT)
		make clean -C $(PRINTF)

fclean: clean
		rm -rf $(NAME)
		make fclean -C $(LIBFT)
		make fclean -C $(PRINTF)

re: fclean all

.PHONY: all clean fclean re
