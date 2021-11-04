#include "meta_data_processor.h"
#include "movie_data.h"
#include <iostream>
#include <exception>

MetaDataProcessor::MetaDataProcessor(MovieMetaDataRepository &jsonClient) : m_repository(jsonClient)
{
}

MetaDataProcessor::~MetaDataProcessor()
{
}

void MetaDataProcessor::ProcessMovies(const std::vector<std::string> &movieNames, Movies &result)
{
	if (movieNames.size() == 0)
	{
		return;
	}

	for (auto movieName : movieNames)
	{
		try
		{
			std::shared_ptr<MovieData> movieData = m_repository.FindMovieData(movieName);

			result.push_back(movieData);
		}
		catch (const std::exception &ex)
		{
			std::cerr << "Exception: " << ex.what() << std::endl;
			// throw;
		}
	}
}
