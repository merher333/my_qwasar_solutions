TARGET = my_ls
SRC = my_ls.c
OBJ = $(SRC:.c=.o)
CFLAGS = -Wall -Wextra -Werror -g3 -fsanitize=address

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(TARGET)

re: fclean all