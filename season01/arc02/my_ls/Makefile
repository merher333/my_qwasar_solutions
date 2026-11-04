CC      = gcc
CFLAGS  = -Wall -Wextra -Werror
SRC     = my_ls.c
OBJ     = $(SRC:.c=.o)
NAME    = my_ls

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

%.o: %.c my_ls.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
