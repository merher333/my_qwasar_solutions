CC = gcc
CFLAGS = -Wall -Wextra -Werror -g
NAME = my_blockchain
SRC = my_blockchain.c
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
	rm -f blockchain.bak

re: fclean all

.PHONY: all clean fclean re