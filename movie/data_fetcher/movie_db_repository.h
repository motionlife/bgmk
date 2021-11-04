#pragma once
#include "movie_meta_data_repository.h"
#include "rest_api_client.h"
#include "movie_data_factory.h"

class TheMovieDbRepository : public MovieMetaDataRepository
{
	RestApiClient m_client;
	const std::string &m_apiKey;
	const MovieDataFactory &m_movieDataFactory;

public:
	TheMovieDbRepository(const std::string &apiKey, const MovieDataFactory &movieDataFactory);
	~TheMovieDbRepository();

	std::shared_ptr<MovieData> FindMovieData(const std::string &movieName) override;
};
