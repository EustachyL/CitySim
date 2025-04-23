#include "Road.h"
Road::Road(std::map<int, Tile*> adjacent): Buildings(10,100, 10, adjacent)
{
	info["Object"] = "Road";
	update();
}
Road::~Road()
{
}
void Road::changeAdjecent(Tile* newAdj, int side)
{
	adjacent[side] = newAdj;
	update();
}
void Road::removeAdjecent(int side)
{
	if (adjacent.find(side) != adjacent.end())
		adjacent.erase(side);
	update();
}
void Road::update()
{
	std::map<int, Tile*> adjRoads;
	for (std::pair<int,Tile*> p: adjacent)
	{
		if (p.second->getTex() >= 10 && p.second->getTex() < 20)
			adjRoads[p.first] = p.second;
	}
	int v = 0;
	if (adjRoads.size() > 2 || adjRoads.size()==0)
		texture = 10;
	else
	{
		v = (adjRoads.find(0) != adjRoads.end()) + 2*(adjRoads.find(2) != adjRoads.end()) + 4*(adjRoads.find(1) != adjRoads.end()) + 7 * (adjRoads.find(3) != adjRoads.end());
		if (v < 4)
			texture = 11;
		else if (v == 7 || v == 11)
			texture = 14;
		else
			texture = 10 + v;
		
	}
}
void Road::propagate(int side, int range, std::set<Tile*>& q, std::list<Tile*>& s)
{
	q.insert(this);
	if (range <= 0)
		return;
	for (std::pair<int, Tile*> p : adjacent)
	{
		if (side == (p.first + 2) % 4)
			continue;
		bool chk = 1;
		for (Tile* t : q)
		{
			if (t == p.second)
			{
				chk = 0;
			}
		}
		if(chk)
		p.second->propagate(p.first, range - 1, q, s);

	}
}