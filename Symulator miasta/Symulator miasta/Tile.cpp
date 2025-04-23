#include "Tile.h"
Tile::Tile(int texture, std::map<int, Tile*> adjacent):texture(texture), adjacent(adjacent)
{
	for (std::pair<int, Tile*> p : adjacent)
	{
		p.second->changeAdjecent(this,(p.first + 2) % 4);
		p.second->update();
	}
}
Tile::~Tile()
{
	for (std::pair<int, Tile*> p : adjacent)
	{
		p.second->removeAdjecent((p.first + 2) % 4);
		p.second->update();
	}
}
void Tile::changeTex(int tex)
{
	texture = tex;
}
int Tile::getTex()
{
	return texture;
}
void Tile::changeAdjecent(Tile* newAdj, int side)
{
	adjacent[side] = newAdj;
}
void Tile::removeAdjecent(int side)
{
	if(adjacent.find(side)!=adjacent.end())
		adjacent.erase(side);
}
void Tile::update() {}
void Tile::propagate(int side, int range, std::set<Tile*>& q, std::list<Tile*>& s)
{
	q.insert(this);
	if (range <= 0)
		return;
	for (std::pair<int, Tile*> p : adjacent)
	{
		if (side = (p.first + 2) % 4)
			continue;
		for (Tile* t : q)
		{
			if (t == p.second)
				continue;
		}
		p.second->propagate(p.first, range - 3, q, s);

	}
}