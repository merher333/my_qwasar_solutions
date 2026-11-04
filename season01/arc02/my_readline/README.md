# Welcome to My Readline
***

## Task
Implement a function `char *my_readline(int fd);` (and `void init_my_readline(void);`) that reads the next line from a file descriptor without including the newline. It must use a global buffer of size `READLINE_READ_SIZE`, handle EOF and errors, and free/reinit state correctly.
## Description
`my_readline` reads chunks of size `READLINE_READ_SIZE` into a heap‐allocated “storage” buffer, searches for `'\n'`, and returns each line (excluding the newline). On each call it preserves leftover data between reads. `init_my_readline()` frees any remaining buffer so you can start fresh.
## Installation
Compile with:
gcc -Wall -Wextra -Werror -g3 -fsanitize=address
my_readline.c test.c -o test
## Usage
Run your tests or read from a file:
./test < input.txt
Or:
./test

```
./my_project argument1 argument2
```

### The Core Team


<span><i>Made at <a href='https://qwasar.io'>Qwasar SV -- Software Engineering School</a></i></span>
<span><img alt='Qwasar SV -- Software Engineering School's Logo' src='https://storage.googleapis.com/qwasar-public/qwasar-logo_50x50.png' width='20px' /></span>
