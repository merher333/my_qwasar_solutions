from flask import Flask, request
import json
from my_csv_parser import movie_filter

app = Flask(__name__)

@app.route('/')
def root():
    genre = request.args.get('genre')
    if genre:
        movies = movie_filter(genre)
        return json.dumps(movies)
    return json.dumps({"error": "No genre provided"}), 400


@app.route('/action')
def action_movies():
    movies = movie_filter("Action")
    return json.dumps(movies)

@app.route('/adventure')
def adventure_movies():
    movies = movie_filter("Adventure")
    return json.dumps(movies)

@app.route('/comedy')
def comedy_movies():
    movies = movie_filter("Comedy")
    return json.dumps(movies)

@app.route('/drama')
def drama_movies():
    movies = movie_filter("Drama")
    return json.dumps(movies)

@app.route('/romance')
def romance_movies():
    movies = movie_filter("Romance")
    return json.dumps(movies)

if __name__ == '__main__':
    app.run('0.0.0.0', port=8080, debug=True)
