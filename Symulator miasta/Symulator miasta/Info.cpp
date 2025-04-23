#include "Info.h"
Info::~Info()
{
}
std::map<std::string, std::string>& Info::getInfo()
{
	return info;
}