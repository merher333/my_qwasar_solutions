# My Allocine

## Task
Write SQL queries to answer questions about a movie database (SQLite). The database has several linked tables: actors, genres, directors, movies, reviews, and the link tables between them (`movies_actors`, `directors_movies`, `movies_genres`, `movies_ratings_reviews`).

The challenge is to select exactly the columns the question asks for, to use JOINs to connect tables through their IDs, and to handle trickier cases such as duplicate rows (reviewers who rated several movies) and filtering by a date range.

## Description
Each question is answered with one SQL query stored in `my_allocine.rb`, in the format `requests["description"] = "SQL"`.

- Simple questions use `SELECT ... FROM ... WHERE`.
- Questions about actors, directors and roles use `JOIN` across the link tables.
- Name searches use `LIKE '%text%'`.
- The reviewers question uses a `JOIN` (not `IN`) so duplicate names are kept, and `ORDER BY` to sort them.
- The last question excludes actors who appeared in a film released between 1990 and 2000, using `NOT IN` with a subquery and the year taken from the release date with `strftime('%Y', ...)`.

## Installation
Nothing to install except SQLite. Download the database from inside `ex00`:

```bash
wget https://storage.googleapis.com/qwasar-public/track-claris/movies.db
```

## Usage
Open the database and try a query:

```bash
sqlite3 movies.db
sqlite> SELECT * FROM genres;
sqlite> .quit
```

The queries are in `my_allocine.rb`. The course's automatic tests (`gandalf`) run each one and compare the result with the expected output.
<span><i>Made at <a href='https://qwasar.io'>Qwasar SV -- Software Engineering School</a></i></span>
<span><img alt='Qwasar SV -- Software Engineering School's Logo' src='https://storage.googleapis.com/qwasar-public/qwasar-logo_50x50.png' width='20px' /></span>