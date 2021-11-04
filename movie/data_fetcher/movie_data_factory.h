#pragma once
#include <memory>
#include "movie_data.h"

class MovieDataFactory
{
public:
	virtual ~MovieDataFactory() = default;
	virtual std::shared_ptr<MovieData> CreateFromJson(const std::string &jsonString) const = 0;
};
