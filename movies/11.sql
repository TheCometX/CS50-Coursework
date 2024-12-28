SELECT title FROM movies, people, stars, ratings WHERE people.id = person_id AND stars.movie_id = movies.id
AND movies.id = ratings.movie_id AND people.name = 'Chadwick Boseman' ORDER BY rating DESC LIMIT 5;
