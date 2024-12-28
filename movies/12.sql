SELECT title FROM movies, stars, people WHERE movies.id = movie_id
AND name = 'Jennifer Lawrence' AND title IN ()
