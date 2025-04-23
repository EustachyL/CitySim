#include "Residential.h"
#include "Budget.h"
Residential::Residential(unsigned short int popcap, unsigned short int baseValue, unsigned short int maintenance, unsigned short int cost, int texture, std::map<int, Tile*> adjacent)
	: Buildings(maintenance, cost, texture, adjacent),popcap(popcap), baseValue(baseValue)
{
	//tymczasowe arbitralne wartosci
	pop = 4;
	qol = 0.5;
	revenue = 0;
	Clock::GetInstance().newMajorOb(this);
	popid = Budget::GetInstance().addPop(this);
	info["Type"] = "Residential";
	info["Pop capacity"] = std::to_string(popcap);
}
Residential::~Residential()
{
	Clock::GetInstance().deleteMajorOb(this);
	Budget::GetInstance().removePop(popid);
}

void Residential::mTickUpdate()
{
	float tqol = qol;
	for (Communal* c : observing)
		tqol += c->getInfluance();
	if (pop < popcap * tqol)
	{
		pop += 2;
	}
	else if (pop > popcap * tqol)
	{
		pop -= 1;
	}
	revenue = pop * (baseValue);
	info["Population"] = std::to_string(pop);
}

void Residential::tickUpdate()
{}
int Residential::getPop()
{
	return pop;
}
void Residential::propagate(int side, int range, std::set<Tile*>& q, std::list<Tile*>& s)
{
	s.push_back(this);
	Tile::propagate( side,  range, q, s);
}