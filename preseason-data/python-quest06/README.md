# Welcome to Python Quest06
***

## Task
The task is to process a dataset provided in a CSV format and transform it into a structured JSON object. This involves:
-Selecting specific columns from the dataset.
-Grouping data based on unique values in those columns.
-Counting occurrences of each value in the selected columns.
-Returning the result in a clean JSON format.
The challenge lies in handling string manipulations, maintaining proper data structure, and ensuring JSON formatting is accurate.

## Description
This project solves the problem of processing and summarizing raw sales data from an online coffee shop. The steps include:

1. Extracting relevant columns such as Gender, Email, Age, City, Device, and Order At.
2. Parsing the rows to count occurrences of unique values in each column.
3. Storing the counts in a dictionary, which is then converted to a JSON-compatible string.
4. Ensuring proper formatting by replacing unnecessary whitespace and escaping characters as required.
The script outputs a concise JSON representation of the dataset, making it easier to analyze and draw insights.

## Installation
1. Clone the repository:
git clone git@git.us.qwasar.io:python-quest06_177466_9m2rnr/python-quest06.git
2. Navigate to the ex02 directory:
cd project/ex02
3. Ensure Python is installed.

## Usage
1. Run the script:
python3 my_data_process.py
2. Example output:
{
    "Gender": {"Male": 3, "Female": 2},
    "Email": {"yahoo.com": 2, "hotmail.com": 3},
    "Age": {"21->40": 2, "66->99": 2, "41->65": 1},
    "City": {"Seattle": 2, "Detroit": 1, "Las Vegas": 1, "Chicago": 1},
    "Device": {"Safari iPhone": 1, "Chrome Android": 2, "Chrome": 2},
    "Order At": {"afternoon": 4, "morning": 1}
}
3. To check your progress, push and validate with Gandalf.

```
./my_project argument1 argument2
```

### The Core Team


<span><i>Made at <a href='https://qwasar.io'>Qwasar SV -- Software Engineering School</a></i></span>
<span><img alt='Qwasar SV -- Software Engineering School's Logo' src='https://storage.googleapis.com/qwasar-public/qwasar-logo_50x50.png' width='20px' /></span>
