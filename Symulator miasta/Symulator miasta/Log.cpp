#include "Log.h"
Log::Log()
{
	logFile.open("Log.txt");
}


Log& Log::GetInstance()
{
	static Log instance;
	return instance;
}


void Log::note(std::string message)
{
	std::cout << message << "\n";
	logFile << message << "\n";
}