NAME = fillit
SRCS = $(wildcard *.c)
HEADER = fillit.h
OBJ = $(SRCS:.c=.o)
CC = gcc
CFLAGS = -Wall -Wextra -Werror

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -I . -o $(NAME)

%.o: %.c $(HEADER)
	$(CC) -c $(CFLAGS) -I . $< -o $@

clean:
	/bin/rm -rf $(OBJ)

fclean: clean
	/bin/rm -rf $(NAME)

re: fclean all