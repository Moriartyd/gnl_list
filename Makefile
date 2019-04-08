all:
	clang -Wall -Wextra -Werror -I libft/includes -o get_next_line.o -c get_next_line.c
	clang -Wall -Wextra -Werror -I libft/includes -o main.o -c main.c
	clang -o test_gnl main.o get_next_line.o -I libft/includes -L libft/ -lft

clean:
	rm -f get_next_line.o main.o

fclean: clean
	rm -Rf test_gnl

re: fclean all
