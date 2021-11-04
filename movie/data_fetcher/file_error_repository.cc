#include "file_error_repository.h"
#include <fstream>

using namespace std;

void FileErrorRepository::LogBadMovie(std::string movieName)
{
	ofstream errorLogFile;
	errorLogFile.open(m_fileName, ios::out);
	if (!errorLogFile.is_open())
	{
		// TODO: handle error
	}

	errorLogFile << movieName << endl;
	errorLogFile.close();
}
