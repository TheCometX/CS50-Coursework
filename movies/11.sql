SELECT title FROM movies, ratings, people, stars WHERE people.id = person_id
AND stars.movie_id = movies.id AND movies.id = ratings.movie_id ORDER BY rating DESC LIMIT 5;
