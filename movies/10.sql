SELECT DISTINCT(name) FROM people, directors, ratings WHERE people.id = person_id AND directors.movie_id = ratings.movie_id AND rating >= 9.0;
