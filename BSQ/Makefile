CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = bsq
SRCS = main.c map_parser.c solver.c utils.c process_map.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
