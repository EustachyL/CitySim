#include "School.h"
#include "Residential.h"
School::School(std::map<int, Tile*> adjacent) : Workspace(30, 0, 500, 2000, 40, adjacent), Communal(0.5f,12)
{
	Tile::info["Object"] = "School";
}
School::~School()
{
	for (Tile* t : relist())
	{
		dynamic_cast<Residential*>(t)->removeObserving(this);
	}
}
std::list<Tile*> School::relist()
{
	std::list<Tile*> l;
	std::set<Tile*> s;

	for (std::pair<int, Tile*> p : adjacent)
	{
		p.second->propagate(p.first, getRange(), s, l);
	}
	return l;
}

void School::mTickUpdate()
{
	for (Tile* t : relist())
	{
		dynamic_cast<Residential*>(t)->addObserving(this);
	}
}
