#include "Workspace.h"
#include "Budget.h"
Workspace::Workspace(unsigned short int jobs, unsigned short int baseValue, unsigned short int maintenance, unsigned short int cost, int tex, std::map<int, Tile*> adjacent)
	: Buildings(maintenance, cost, tex, adjacent), jobs(jobs), baseValue(baseValue)
{
	//tymczasowe arbitralne wartosci
	taken = 0;
	value = 1;
	revenue = 0;
	Clock::GetInstance().newMajorOb(this);
	jobid = Budget::GetInstance().addWork(this);
	info["Type"] = "Workspace";
	info["Max jobs"] = std::to_string(jobs);
	info["Income per job"] = std::to_string(value + baseValue);
}
Workspace::~Workspace()
{
	Clock::GetInstance().deleteMajorOb(this);
	Budget::GetInstance().removeWork(jobid);
}

void Workspace::mTickUpdate()
{
	revenue = taken * (value + baseValue);
}

void Workspace::tickUpdate()
{}
void Workspace::setWorkforce(int& pop)
{
	taken = 0;
	if (pop - jobs >= 0)
		taken = jobs;
	else
		taken = pop;
	pop -= taken;
	info["Jobs taken"] = std::to_string(taken);
}