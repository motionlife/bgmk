#pragma once
#include <vector>
#include <string>
#include "movie_meta_data_repository.h"
#include <memory>

class MovieData;

typedef std::vector<std::shared_ptr<MovieData>> Movies;

class MetaDataProcessor
{
	MovieMetaDataRepository &m_repository;

public:
	MetaDataProcessor(MovieMetaDataRepository &respository);
	~MetaDataProcessor();

	void ProcessMovies(const std::vector<std::string> &movieNames, Movies &result);
};