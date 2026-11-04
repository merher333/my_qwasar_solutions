# Welcome to My Ls
***

## Task
Build a simple `ls`–style utility in C that lists directory contents one entry per line, supporting:
- `-a` (include “dot” files)
- `-t` (sort by modification time, newest first)
- multiple operands (files first, then directories, with headers)
Challenge: match the behavior of `ls -1`, `ls -a1`, `ls -1t`, and combined flags (e.g. `ls -ta`) without using forbidden functions like `qsort()`.
## Description
The `my_ls` program:
1. Parses combined flags (`-a`, `-t`, or both).
2. Splits operands into files and directories.
3. Lists files (always shown), sorted by name or time.
4. For directories:
   - With one operand, prints entries only.
   - With multiple operands, prints a `dirname:` header before each.
   - Reads entries via `opendir()`/`readdir()`, filters “dot” files when `-a` is not set, gathers metadata with `lstat()`.
   - Sorts with a simple bubble sort on an `Entry[]` array.
5. Prints one entry per line, matching `ls` exactly in all tested cases.
## Installation
Compile with GNU Make:
make
This produces the my_ls executable in the current directory.
## Usage
./my_ls [options] [file ...]
./my_ls                 # list current directory
./my_ls -a              # include dot-files
./my_ls -t /tmp         # sort /tmp by time
./my_ls dir1 dir2       # list two directories, with headers
./my_ls -ta marvel_dir  # include dot-files, sort by time

```
./my_project argument1 argument2
```

### The Core Team


<span><i>Made at <a href='https://qwasar.io'>Qwasar SV -- Software Engineering School</a></i></span>
<span><img alt='Qwasar SV -- Software Engineering School's Logo' src='https://storage.googleapis.com/qwasar-public/qwasar-logo_50x50.png' width='20px' /></span>
