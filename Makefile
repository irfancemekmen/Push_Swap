NAME		= push_swap
LIBFT		= libft
LIBFTM		= libft/libft.a
PRINTF		= ft_printf
PRINTFLIB	= ft_printf/libftprintf.a
CC			= cc
CFLAGS		= -Wall -Wextra -Werror
OBJ			= obj
OBJDIR		= obj/push_swap_obj
CFILES 		=	main.c					\
				check.c					\
				error_handle.c			\
				linked_list.c			\
				qsort.c					\
				qsort_utils.c			\
				sorting.c				\
				push.c					\
				swap.c					\
				rotate.c				\
				reverse_rotate.c

OBJS = $(CFILES:%.c=$(OBJDIR)/%.o)

all: $(NAME)

$(NAME): $(OBJS)
	@make -C $(LIBFT)
	@make -C $(PRINTF)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFTM) $(PRINTFLIB) -o $(NAME)

$(OBJDIR)/%.o: %.c
	@mkdir -p $(OBJDIR)
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
		rm -rf $(OBJ)
		make clean -C $(LIBFT)
		make clean -C $(PRINTF)

fclean: clean
		rm -rf $(NAME)
		make fclean -C $(LIBFT)
		make fclean -C $(PRINTF)

re: fclean all

.PHONY: all clean fclean re
