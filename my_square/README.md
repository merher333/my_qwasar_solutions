# Welcome to My Square
***

## Task
The goal of this project is to create a C program that prints a rectangle or square using specific characters based on given width and height inputs. The program takes two command-line arguments and prints a properly formatted shape.

## Description
This program uses loops to generate a structured square or rectangle with:

o at the corners
- for horizontal edges
| for vertical edges
Spaces inside (if applicable)
It ensures correct handling of edge cases like width/height of 1. The program reads input values, processes them into an integer format, and prints the appropriate shape based on conditions.

## Installation
To compile and run the program, use:
gcc my_square.c -o my_square
./my_square width height
Replace width and height with desired values.

## Usage
To print a 5x3 rectangle, run:
./my_square 5 3
Output:
o---o
|   |
o---o

Edge Cases
./my_square 1 1 → Outputs o
./my_square 5 1 → Outputs o---o

```
./my_project argument1 argument2
```

### The Core Team


<span><i>Made at <a href='https://qwasar.io'>Qwasar SV -- Software Engineering School</a></i></span>
<span><img alt='Qwasar SV -- Software Engineering School's Logo' src='https://storage.googleapis.com/qwasar-public/qwasar-logo_50x50.png' width='20px' /></span>
