NAME	= libftprintf.a
CC		= cc
CFLAGS	= -Wall -Werror -Wextra
OBJDIR	= ../obj/ft_printf_obj
SRC		=	ft_printf.c \
			ft_func.c

OBJ = $(SRC:%.c=$(OBJDIR)/%.o)

all : $(NAME)

$(NAME): $(OBJ)
	@ar rcs $(NAME) $?

$(OBJDIR)/%.o: %.c
	@mkdir -p $(OBJDIR)
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -rf $(OBJDIR)

fclean: clean
	@rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
