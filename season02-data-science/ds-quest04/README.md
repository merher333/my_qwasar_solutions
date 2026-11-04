# Welcome to Ds Quest04
***

## Task
Seven exercises on model evaluation. Each function receives the true data and the predicted data and returns the matching metric from `sklearn.metrics`. The challenge: ex00 to ex02 receive CSV text (the robot name column must be dropped and both tables must have the same number of rows), while ex03 to ex06 receive lists of integers.

## Description
- ex00: R2 score (`r2_score`)
- ex01: Mean squared error (`mean_squared_error`)
- ex02: Mean absolute error (`mean_absolute_error`)
- ex03: Confusion matrix (`confusion_matrix`)
- ex04: Accuracy score (`accuracy_score`)
- ex05: Recall score (`recall_score`, `average=None`)
- ex06: F1 score (`f1_score`, `average=None`)

For ex00 to ex02, the CSV input is read with pandas (`read_csv`), the first column (the robot name) is dropped, and both tables are trimmed to the same length before calling sklearn. The input is accepted both as a string and as a `StringIO` object.

## Installation
pip install pandas scikit-learn

## Usage
Import the function from the exercise folder, for example:

cd ex04
python -c "from my_model_evaluation_journey_accuracy_score import *; print(my_model_evaluation_journey_accuracy_score([2,0,2,2,0,1,1,2,2,0,1,2],[0,0,2,1,0,2,1,0,2,0,2,2]))"

```
./my_project argument1 argument2
```

### The Core Team


<span><i>Made at <a href='https://qwasar.io'>Qwasar SV -- Software Engineering School</a></i></span>
<span><img alt='Qwasar SV -- Software Engineering School's Logo' src='https://storage.googleapis.com/qwasar-public/qwasar-logo_50x50.png' width='20px' /></span>
