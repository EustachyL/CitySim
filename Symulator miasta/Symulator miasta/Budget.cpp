#include "Budget.h"
#include "Log.h"
Budget::Budget()
{
	treasury = 100000;
	balance = 0;
	pop = 0;
	free = 0;
	bid = rid = wid = 0;
	Clock::GetInstance().newMajorOb(this);
}

void Budget::recount()
{
	balance = 0;
	for(std::pair<int, Buildings*> b : buildings)
	{
		balance+=b.second->getBalance();
	}
	Log::GetInstance().note("balance recount");
}
void Budget::recountPop()
{
	pop = 0;
	for (std::pair<int, Residential*> b : res)
	{
		pop += b.second->getPop();
	}
	free = pop;
	for (std::pair<int, Workspace*> b : workspace)
	{
		if (free == 0)
			break;
		b.second->setWorkforce(free);
	}
	Log::GetInstance().note("Out of "+std::to_string(pop)+ " pop "+ std::to_string(free) +" dont have jobs");
}

Budget& Budget::GetInstance()
{
	static Budget instance;
	return instance;
}
int Budget::getTreasury()
{
	return treasury;
}
int Budget::getBalance()
{
	return balance;
}
int Budget::getPop()
{
	return pop;
}
void Budget::tickUpdate()
{

}
void Budget::mTickUpdate()
{
		treasury+=balance;
		recount();
		recountPop();

}
int Budget::addBuilding(Buildings* b)
{
	++bid;
	buildings[bid]=b;
	treasury -= b->getCost();
	return bid;
}
void Budget::removeBuilding(int id)
{
	buildings.erase(id);
	recount();

}
int Budget::addPop(Residential* b)
{
	++rid;
	res[rid] = b;
	return rid;
}
void Budget::removePop(int id)
{
	res.erase(id);

}
int Budget::addWork(Workspace* b)
{
	++wid;
	workspace[wid] = b;
	return wid;
}
void Budget::removeWork(int id)
{
	workspace.erase(id);

}