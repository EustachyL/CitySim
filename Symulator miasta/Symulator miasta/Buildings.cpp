#include "Log.h"
#include "Buildings.h"
#include "Budget.h"

Buildings::Buildings(int maintenance, int cost, int tex, std::map<int, Tile*> adjacent): Tile(tex, adjacent), maintenance(maintenance), cost(cost)
{
	id=Budget::GetInstance().addBuilding(this);
	revenue = 0;
}

Buildings::~Buildings()
{
	Budget::GetInstance().removeBuilding(id);
}
int Buildings::getBalance()
{
	info["Revenue"] = std::to_string(revenue);
	info["Maintenance"] = std::to_string(maintenance);
	return revenue - maintenance;
}
int Buildings::getCost()
{
	return cost;
}
void Buildings::addObserving(Communal* b)
{
	observing.insert(b);
}
void Buildings::removeObserving(Communal* b)
{
	observing.erase(b);
}