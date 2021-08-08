NAME = push_swap

C_FILES			=		srcs/main.c

O_FILES = $(C_FILES:.c=.o)

HEADER = header/header.h

.PHONY: all bonus clean fclean re

all: $(NAME)

$(NAME): $(O_FILES)
	make -C ./libft
	gcc -g -Wall -Wextra -Werror $(O_FILES) ./libft/libft.a -o $(NAME)

%.o: %.c $(HEADER)
	gcc -c $<

clean:
	rm -f $(O_FILES)
	make clean -C ./libft

fclean: clean
	rm -f $(NAME)
	make fclean -C ./libft

bonus: re

re: fclean all