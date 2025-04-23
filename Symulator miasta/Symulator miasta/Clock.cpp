#include "Clock.h"
#include "Log.h"

Clock::Clock()
{
}
Clock::~Clock()
{}
Clock& Clock::GetInstance()
{
	static Clock instance;
	return instance;
}

void Clock::tick()
{
	int counter = 0;
		std::chrono::milliseconds delay(16);
	while (running)
	{
		counter = (counter + 1) % 40 ;
		std::this_thread::sleep_for(delay);
		if (counter==0)
			this->majorTickInform();
		this->tickInform();
	}
}

void Clock::newOb(Observer* ob)
{
	observers.insert(ob);
}

void Clock::newMajorOb(Observer* ob)
{
	majorObservers.insert(ob);
}

void Clock::deleteOb(Observer* ob)
{
	observers.erase(observers.find(ob));
}

void Clock::deleteMajorOb(Observer* ob)
{
	majorObservers.erase(majorObservers.find(ob));
}
void Clock::tickInform()
{
	for (auto& o : observers)
	{
		o->tickUpdate();
	}
}

void Clock::majorTickInform()
{
	for (auto& o : majorObservers)
	{
		o->mTickUpdate();
	}
	Log::GetInstance().note("Major Tick");
}
void Clock::start()
{
	Log::GetInstance().note("clock started");
	running = 1;
	tick();
}
void Clock::stop()
{
	Log::GetInstance().note("clock stopped");
	running = 0;
}