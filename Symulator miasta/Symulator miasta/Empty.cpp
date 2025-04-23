#include "Empty.h"
Empty::Empty(int texture, std::map<int, Tile*> adjacent) :Tile(texture,adjacent)
{

	for (std::pair<int, Tile*> p : adjacent)
	{
		p.second->changeAdjecent(this, (p.first + 2) % 4);
		p.second->update();
		adjacent.erase(p.first);
	}
	info["Object"] = "Empty Tile";
}
Empty::Empty(std::map<int, Tile*> adjacent) :Tile(texture, adjacent)
{
	texture = 1;
	for (std::pair<int, Tile*> p : adjacent)
	{
		p.second->changeAdjecent(this, (p.first + 2) % 4);
		p.second->update();
	}
	info["Object"] = "Empty Tile";
}
Empty::~Empty()
{
	for (std::pair<int, Tile*> p : adjacent)
	{
		p.second->removeAdjecent((p.first + 2) % 4);
		p.second->update();
	}
}
void Empty::changeTex(int tex)
{
	texture = tex;
}
int Empty::getTex()
{
	return texture;
}
void Empty::update() {}