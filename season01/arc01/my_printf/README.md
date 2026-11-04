# Welcome to My Printf
***

## Task
The goal of this project is to reimplement the standard `printf` function in C, handling specific format specifiers without using the original `printf` library functions.

## Description
This project implements a custom version of `printf` called `my_printf`. It supports format specifiers for integers, characters, strings, pointers, and different bases (decimal, octal, and hexadecimal). The function uses variadic arguments to process an unknown number of inputs dynamically.

### **Supported Specifiers**
- `%d` → Signed decimal integer
- `%u` → Unsigned decimal integer
- `%o` → Unsigned octal integer
- `%x` → Unsigned hexadecimal (lowercase)
- `%c` → Single character
- `%s` → String
- `%p` → Pointer address (in lowercase hex)

## Installation
To compile the project, run:
```bash
gcc -Wall -Wextra -Werror main.c my_printf.c -o my_program

## Usage
To test the function, run:
./my_program
Example output:
Hello World!
Testing decimal %d: 42
Testing unsigned decimal %u: 42
Testing octal %o: 52
Testing hex %x: ff
Testing char %c: A
Testing string %s: Hello Qwasar!
Testing pointer %p: 0xabcdef123456


```
./my_project argument1 argument2
```

### The Core Team


<span><i>Made at <a href='https://qwasar.io'>Qwasar SV -- Software Engineering School</a></i></span>
<span><img alt='Qwasar SV -- Software Engineering School's Logo' src='https://storage.googleapis.com/qwasar-public/qwasar-logo_50x50.png' width='20px' /></span>
