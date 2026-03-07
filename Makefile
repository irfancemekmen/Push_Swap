NAME = push_swap
LIBFT = libft
LIBFTM = libft/libft.a
PRINTF = ft_printf
PRINTFLIB = ft_printf/libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
CFILES =	main.c			\
			linked_list.c	\
			check.c			\
			error_handle.c	\
			steps/push.c	\
			steps/swap.c	\
			steps/rotate.c

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
