#include "Communal.h"
Communal::Communal(float influance, unsigned short int range):influance(influance), range(range)
{
}
Communal::~Communal()
{
}
float Communal::getInfluance()
{
	return influance;
}
unsigned short int  Communal::getRange()
{
	return range;
}