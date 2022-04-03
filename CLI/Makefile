BLUE = \033[34m
RESET = \033[0m
GREEN = \033[32m

NAME	=	cli

SRCS	=	main.c \
			get_next_line.c

OBJS	=	$(SRCS:.c=.o)

all:	$(NAME)

$(NAME):	$(OBJS)
	@gcc	$(OBJS) -o $(NAME)
	@echo "$(GREEN)We are ready!$(RESET)"
	@echo "$(BLUE)To start type './cli' and then 'logs'.$(RESET)"

%.o: %.c
	@gcc -c $< -o $@

clean:
	@rm -rf $(OBJS)

fclean: clean
	@rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
