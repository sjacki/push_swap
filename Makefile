NAME = push_swap

FLAG			=		-Wextra -Werror -Wall

C_FILES			=		srcs/main.c

O_FILES			=		$(C_FILES:.c=.o)

HEADER			=		header/header.h

.PHONY: all bonus clean fclean re

all: $(NAME)

$(NAME): $(O_FILES)
	make -C ./libft
	gcc -g $(FLAG) $(O_FILES) ./libft/libft.a -o $(NAME)

%.o: %.c $(HEADER)
	gcc $(FLAG) -c $< -o $@

clean:
	rm -f $(O_FILES)
	make clean -C ./libft

fclean: clean
	rm -f $(NAME)
	make fclean -C ./libft

bonus: re

re: fclean all

run: all
	./push_swap 9 3 7 5 6 1 4 5 6 2