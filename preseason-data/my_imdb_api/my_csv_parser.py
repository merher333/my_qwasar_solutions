import csv

def movie_filter(genre):
    filename = 'movies.csv'
    result = []
    try:
        with open(filename) as csvfile:
            csv_content = csv.DictReader(csvfile)
            for movie in csv_content:
                # Normalize genres by stripping spaces and making them lowercase
                genres = [g.strip().lower() for g in movie['Genre'].split(',')]
                if genre.lower() in genres:  # Compare genre in lowercase
                    result.append(movie)
    except FileNotFoundError:
        return {"error": f"{filename} not found"}
    except Exception as e:
        return {"error": str(e)}
    return result
