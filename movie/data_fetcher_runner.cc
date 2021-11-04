#include <iostream>
#include <string>
#include "api_key.h"

#include "movie/data_fetcher/meta_data_processor.h"
#include "movie/data_fetcher/movie_db_repository.h"
#include "movie/data_fetcher/movie_db_data_factory.h"

int main(int argc, char **argv)
{
	TheMovieDbDataFactory dataFactory;
	TheMovieDbRepository repository(MY_API_KEY, dataFactory);
	MetaDataProcessor processor(repository);

	Movies result;
	processor.ProcessMovies({"Doctor Strange", "Dr. Strangelove", "The Internship"}, result);

	std::cout << "Resize.size() is: " << result.size() << std::endl;

	for (auto movie : result)
	{
		std::cout << "Title: " << movie->GetTitle() << std::endl;
		std::cout << "IMDB Id: " << movie->GetImdbId() << std::endl
				  << std::endl;
		std::cout << movie->GetPlot() << std::endl
				  << std::endl;
		std::cout << "Length (min.) " << movie->GetLengthMin() << std::endl
				  << std::endl;
		std::cout << "----------------------------------------" << std::endl;
	}

	return 0;
}