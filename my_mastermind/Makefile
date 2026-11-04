CC = gcc
CFLAGS = -Wall -Wextra -Werror
TARGET = my_mastermind

all: $(TARGET)

$(TARGET): main.c
	$(CC) $(CFLAGS) -o $(TARGET) main.c

clean:
	rm -f $(TARGET)

fclean: clean

re: fclean all
