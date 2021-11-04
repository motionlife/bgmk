#include "movie_db_data_factory.h"
#include <rapidjson/document.h>
#include "settable_movie_data.h"

TheMovieDbDataFactory::TheMovieDbDataFactory()
{
}

TheMovieDbDataFactory::~TheMovieDbDataFactory()
{
}

std::shared_ptr<MovieData> TheMovieDbDataFactory::CreateFromJson(const std::string &jsonString) const
{
	try
	{
		rapidjson::Document jsonDocument;
		jsonDocument.Parse(jsonString.c_str());
		if (!jsonDocument.IsObject())
		{
			return std::make_shared<SettableMovieData>();
			;
		}

		auto imdbId = jsonDocument["imdb_id"].GetString();
		auto title = jsonDocument["title"].GetString();
		auto plot = jsonDocument["overview"].GetString();
		auto lengthMin = jsonDocument["runtime"].GetUint();

		auto result = std::make_shared<SettableMovieData>();
		result->SetImdbId(imdbId);
		result->SetTitle(title);
		result->SetPlot(plot);
		result->SetLengthMin(lengthMin);

		return result;
	}
	catch (...)
	{
	}

	return std::make_shared<SettableMovieData>();
}
