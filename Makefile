NAME=push_swap
CFLAGS=-Wall -Wextra -Werror -O0 -g3 -fsanitize=address
SRC=algo.c check_input.c list.c \
	main.c move.c spec_list.c \
	utils_algo.c utils.c
SRCS=$(addprefix srcs/, $(SRC))
OBJS=$(SRC:.c=.o)
LIB=libtf/libft.a
INCLUDE=include/include.h

.PHONY: all re clean fclean

all: $(NAME)

$(NAME): $(OBJS) $(LIB)
	gcc $(CFLAGS) -o $(NAME) $(OBJS) -L./libft -lft

$(OBJS): $(SRCS) $(INCLUDE)
	gcc $(CFLAGS) -c -Iinclude $(SRCS)

$(LIB):
	make -C libft

clean:
	rm -rf $(OBJS)
	make -C libft clean

fclean: clean
	rm -rf $(NAME)
	make -C ../libft fclean

re: all