# Welcome to My IMDb API
***

## Task
Ohhhh nooo!! IMDB just went down. We need to provide a service while their DevOps team gets the website back online. This backend API allows users to search for movies by genre.

## Description
This project provides a backend service that parses a CSV file named `movies.csv`, filters movies based on the requested genre, and serves the results in JSON format via HTTP. The API is implemented using Flask, a lightweight Python framework, to handle HTTP communication.

## Installation
1. Clone this repository:
   git clone <repository_url>
   cd <repository_folder>
2. Install the required dependencies:
    pip install flask
3. Ensure that the movies.csv file is in the same directory as the app.py and my_csv_parser.py files.

## Usage
Run the Flask app:
python app.py
The server will start at `http://localhost:8080`.
 Available Routes:
1. GET `/`
    - Returns all movies or filters by the `genre` query parameter.
    - Example:
        curl "http://localhost:8080?genre=action"
2. GET `/action`
    - Returns movies in the Action genre.
    - Example:
        curl "http://localhost:8080/action"
3. GET `/adventure`**
    - Returns movies in the Adventure genre.
    - Example:
       curl "http://localhost:8080/adventure"
4. GET `/comedy`
    - Returns movies in the Comedy genre.
    - Example:     
       curl "http://localhost:8080/comedy"
5. GET `/drama`
    - Returns movies in the Drama genre.
    - Example:
        curl "http://localhost:8080/drama"     
6. GET `/romance`**
    - Returns movies in the Romance genre.
    - Example:
       curl "http://localhost:8080/romance"
  Example Response:
Request:
    curl "http://localhost:8080?genre=western"
Response:
[
  {
    "Rank": "39",
    "Title": "The Magnificent Seven",
    "Genre": "Action,Adventure,Western",
    "Description": "Seven gunmen in the old west gradually come together to help a poor village against savage thieves.",
    "Director": "Antoine Fuqua",
    "Actors": "Denzel Washington, Chris Pratt, Ethan Hawke,Vincent D'Onofrio",
    "Year": "2016",
    "Runtime (Minutes)": "132",
    "Rating": "6.9",
    "Votes": "122853",
    "Revenue (Millions)": "93.38",
    "Metascore": "54"
  }
]

```
./my_project argument1 argument2
```

### The Core Team


<span><i>Made at <a href='https://qwasar.io'>Qwasar SV -- Software Engineering School</a></i></span>
