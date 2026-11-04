# Welcome to My Select Query
***

## Task
Implement a class `MySelectQuery` that parses CSV content and provides a `where(column_name, criteria)` method to return all rows matching the criteria. The challenge lies in correctly splitting CSV lines, mapping column names to indices, and filtering data efficiently.
## Description
My solution uses a JavaScript `MySelectQuery` class that:
- Parses the CSV string into lines and extracts headers.
- Builds a mapping of column names to their corresponding index.
- Stores raw data lines alongside their parsed fields.
- Implements the `where` method to filter rows by comparing field values to the specified criteria.
## Installation
No external dependencies. Ensure you have [Node.js](https://nodejs.org/) installed.
## Usage
Import and run the MySelectQuery class:
node ex00/test.js
Or in your code:
const MySelectQuery = require('./ex00/my_select_query');
const csv =
  "name,year_start,year_end,position\n" +
  "Andre Brown,2007,2009,F\n" +
  "Bob Smith,2010,2012,G\n" +
  "Andre Brown,2013,2015,C\n";

const q = new MySelectQuery(csv);
const result = q.where('name', 'Andre Brown');
console.log(result);

```
./my_project argument1 argument2
```

### The Core Team


<span><i>Made at <a href='https://qwasar.io'>Qwasar SV -- Software Engineering School</a></i></span>
<span><img alt='Qwasar SV -- Software Engineering School's Logo' src='https://storage.googleapis.com/qwasar-public/qwasar-logo_50x50.png' width='20px' /></span>
