#include "movie_db_repository.h"
#include "json_helper.h"
#include "movie_not_found_exception.h"
#include "string_html_encoder.h"
#include "movie_data_factory.h"

using namespace std;

TheMovieDbRepository::TheMovieDbRepository(const string &apiKey, const MovieDataFactory &movieDataFactory) : m_apiKey(apiKey), m_movieDataFactory(movieDataFactory)
{
}

TheMovieDbRepository::~TheMovieDbRepository()
{
}

std::shared_ptr<MovieData> TheMovieDbRepository::FindMovieData(const std::string &movieName)
{
	auto encoded_url = StringHtmlEncoder::Encode("https://api.themoviedb.org/3/search/movie?api_key=" + m_apiKey + "&page=1&query=" + movieName);
	string movieList = m_client.HttpGet(encoded_url);

	if (movieList.length() == 0)
	{
		throw MovieNotFoundException(movieName);
	}

	auto movieId = JsonHelper::GetMatchingTitleIdFromMovieList(movieName, movieList);

	if (movieId.length() == 0)
	{
		throw MovieNotFoundException(movieName);
	}

	string encoded_url1 = StringHtmlEncoder::Encode("https://api.themoviedb.org/3/movie/" + movieId + "?api_key=" + m_apiKey);
	auto movieDataJson = m_client.HttpGet(encoded_url1);

	return m_movieDataFactory.CreateFromJson(movieDataJson);
}
