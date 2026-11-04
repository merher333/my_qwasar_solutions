# Welcome to My Levenshtein
***

## Task
The task is to implement a function, `my_levenshtein`, that calculates the Qwasar version of the Levenshtein difference between two strings. The challenge lies in ensuring the function handles edge cases, such as strings of unequal lengths, while efficiently comparing characters to count mismatches.

## Description
To solve this problem:
1. The function first checks if the lengths of the input strings are equal. If not, it immediately returns `-1`.
2. If the lengths are equal, the function iterates through both strings simultaneously, comparing each character.
3. For every character mismatch, a counter is incremented. The final value of the counter is returned as the Levenshtein difference.

## Installation
1. Clone the repository:
   ```bash
   git clone <repository-url>
   cd project
2. Ensure Python 3 is installed:
python3 --version


## Usage
Run the script using Python 3. Example:
python3 ex00/my_levenshtein.py
Example Outputs
Input: "GGACTGA" and "GGACTGA"
Return Value: 0

Input: "ACCAGGG" and "ACTATGG"
Return Value: 2

Input: "GGACGGATTCTG" and "AGG"
Return Value: -1

Input: "" and ""
Return Value: 0

```
./my_project argument1 argument2
```

### The Core Team


<span><i>Made at <a href='https://qwasar.io'>Qwasar SV -- Software Engineering School</a></i></span>
<span><img alt='Qwasar SV -- Software Engineering School's Logo' src='https://storage.googleapis.com/qwasar-public/qwasar-logo_50x50.png' width='20px' /></span>
