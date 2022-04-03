BLUE = \033[34m
RESET = \033[0m
GREEN = \033[32m

NAME	=	activity

SRCS	=	main.c \
			curl.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@gcc $(OBJS) -o $(NAME) -lcurl -lulfius
	@echo "$(GREEN)We are ready!$(RESET)"
	@echo "$(BLUE)To start the executable, type './activity'.$(RESET)"


%.o: %.c
	@gcc -c $< -o $@

clean:
	@rm -rf $(OBJS)

fclean: clean
	@rm -rf $(NAME)
	@rm -rf log.txt

re: fclean all

.PHONY: all clean fclean re
