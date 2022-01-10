CC=gcc
NAME=push_swap
CFLAGS=-Wall -Wextra -Werror
SRC=algo.c check_input.c list.c \
	main.c move.c spec_list.c \
	utils_algo.c utils.c algo_10.c \
	utils2_algo.c ft_itoa.c
SRCS=$(addprefix srcs/, $(SRC))
OBJS=$(SRC:.c=.o)
LIB=libtf/libft.a
INCLUDE=include/include.h

.PHONY: all re clean fclean

all: $(NAME)

$(NAME): $(OBJS)
	make -C libft
	$(CC) $(OBJS) $(CFLAGS) -L./libft -lft -o $(NAME)

$(OBJS): $(SRCS) $(INCLUDE)
	$(CC) $(CFLAGS) -c -Iinclude $(SRCS)

clean:
	rm -rf $(OBJS)
	make -C libft clean

fclean: clean
	rm -rf $(NAME)
	make -C libft fclean

re: fclean all