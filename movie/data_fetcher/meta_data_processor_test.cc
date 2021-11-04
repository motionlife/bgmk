#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include <vector>
#include "meta_data_processor.h"
#include "movie_data.h"
#include "movie_db_repository.h"
#include "movie/api_key.h"
#include "movie_db_data_factory.h"

using namespace std;

class MetaDataProcessorTests : public ::testing::Test
{
    TheMovieDbDataFactory dataFactory;
    TheMovieDbRepository *repository;

public:
    MetaDataProcessorTests()
    {
        repository = new TheMovieDbRepository(MY_API_KEY, dataFactory);
    }

    ~MetaDataProcessorTests()
    {
        delete repository;
    }

protected:
    MetaDataProcessor *processor;

    virtual void SetUp()
    {
        processor = new MetaDataProcessor(*repository);
    }

    virtual void TearDown()
    {
        delete processor;
    }
};

TEST_F(MetaDataProcessorTests, ProcessMovies_PassEmptyMovieList_ReturnEmptyResult)
{
    Movies result;
    processor->ProcessMovies({}, result);

    ASSERT_EQ(0, result.size());
}

TEST_F(MetaDataProcessorTests, DISABLED_ProcessMovies_PassValidMovie_ReturnMovieData)
{
    Movies result;
    processor->ProcessMovies({"Batman Begins"}, result);

    EXPECT_EQ(1, result.size());
    EXPECT_EQ(result[0]->GetTitle(), "Batman Begins");
}

TEST_F(MetaDataProcessorTests, DISABLED_ProcessMovies_PassValidMovies_ReturnAllMoviesData)
{
    Movies result;
    processor->ProcessMovies({"Batman Begins", "Apocalypse Now", "Dumb and Dumber"}, result);

    EXPECT_EQ(3, result.size());
    EXPECT_EQ(result[0]->GetTitle(), "Batman Begins");
    EXPECT_EQ(result[1]->GetTitle(), "Apocalypse Now");
    EXPECT_EQ(result[2]->GetTitle(), "Dumb and Dumber");
}