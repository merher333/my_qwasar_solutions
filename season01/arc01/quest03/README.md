# Welcome to Quest03
***

## Task
This quest was all about **rebuilding C standard library functions** from scratch, because apparently, suffering builds character.  
The goal was to **practice pointers, loops, strings, structs, and logic**, while also questioning my life choices every time a `segmentation fault` popped up.

## Description
I implemented the following functions **(yes, manually, because why would life be easy?)**:
- **`reverse_string`** - Reverses a string **in place**, like flipping a pancake, but in C.
- **`my_strcmp`** - Compares two strings and returns their ASCII difference, because why not?
- **`my_strcpy`** - Copies a string, kinda like `CTRL+C`, but you have to write it yourself.
- **`my_strncpy`** - Copies a string with a limited number of characters—perfect for when you only like part of something.
- **`my_strchr`** - Finds the **first occurrence** of a character in a string, like "Where’s Waldo?" but in C.
- **`my_strrchr`** - Finds the **last occurrence** of a character in a string. Same game, but Waldo is hiding at the back.
- **`my_strstr`** - Finds a **substring inside a string**, because why not look for words inside other words?
- **`my_first_struct`** - Introduces **structs**, aka "How to store multiple things in one box."
- **`my_is_sort`** - Checks if an array is **sorted** in ascending or descending order, because apparently, we needed a function for that.

Every single function was **tested using Gandalf**, and **YES, I PASSED**

## Installation
If you want to relive my suffering, **compile the C files** like this:
gcc -Wall -Wextra -Werror <file>.c -o <output_file>
For example:
gcc -Wall -Wextra -Werror my_strcmp.c -o my_strcmp
If gcc yells at you, just fix your code and try again. Or cry. Both work.

## Usage
To run any function, type:
./<output_file>
Example:
./my_strcmp



```
./my_project argument1 argument2
```

### The Core Team


<span><i>Made at <a href='https://qwasar.io'>Qwasar SV -- Software Engineering School</a></i></span>
<span><img alt='Qwasar SV -- Software Engineering School's Logo' src='https://storage.googleapis.com/qwasar-public/qwasar-logo_50x50.png' width='20px' /></span>
