# Welcome to My Cat
***

## Task
The goal is to implement a program called `my_cat`, which replicates the behavior of the `cat` command in Unix/Linux systems.
The program reads the content of files provided as arguments and prints it to the standard output.
The challenge is to handle multiple files correctly and provide proper error handling if a file cannot be opened.

## Description
The program `my_cat` solves the problem by:
1. Accepting file names as arguments.
2. Opening each file one by one.
3. Reading the file's contents line by line.
4. Printing the contents to the terminal (standard output).
5. Handling errors gracefully if a file cannot be opened.
This program is written in **C** and uses basic file-handling functions such as:
- `fopen()` to open a file.
- `fgets()` to read the contents.
- `fclose()` to close the file safely.
Unlike the real `cat` command, this program does not support options or flags.


## Installation
To compile the program, you need a **C compiler** (like `gcc`).
1. Clone the repository:
   ```bash
   git clone <your-repository-url>
   cd <your-project-directory>
2. Compile the program:
gcc -Wall -Wextra -o my_cat my_cat.c

## Usage
To run the program, use the following syntax:
./my_cat file1.txt file2.txt
Example:
1. Create test files:
echo "Hello, this is file1." > file1.txt
echo "This is file2." > file2.txt
2. Run the program:
./my_cat file1.txt file2.txt
Output:
Hello, this is file1.
This is file2.

Error Handling:
If a file cannot be opened, the program will display:
my_cat: Cannot open file <filename>

```
./my_project argument1 argument2
```

### The Core Team


<span><i>Made at <a href='https://qwasar.io'>Qwasar SV -- Software Engineering School</a></i></span>
<span><img alt='Qwasar SV -- Software Engineering School's Logo' src='https://storage.googleapis.com/qwasar-public/qwasar-logo_50x50.png' width='20px' /></span>
