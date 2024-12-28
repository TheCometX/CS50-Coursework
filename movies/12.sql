SELECT title FROM movies, stars, people WHERE movies.id = movie_id
AND person_id = people.id AND name = 'Bradley Cooper' AND name = 'Jennifer Lawrence';
