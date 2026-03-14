NAME = push_swap
LIBFT = libft
LIBFTM = libft/libft.a
PRINTF = ft_printf
PRINTFLIB = ft_printf/libftprintf.a
CC = cc -g
CFILES =	main.c					\
			check.c					\
			error_handle.c			\
			linked_list.c			\
			qsort.c					\
			qsort_utils.c			\
			sorting.c				\
			steps/push.c			\
			steps/swap.c			\
			steps/rotate.c			\
			steps/reverse_rotate.c	\

OBJS = $(CFILES:.c=.o)

$(NAME): $(OBJS)
	make -C $(LIBFT)
	make -C $(PRINTF)
	$(CC) $(OBJS) $(LIBFTM) $(PRINTFLIB) -o $(NAME)

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
