#include "Button_GI.h"
#include "Log.h"
Button_GI::Button_GI(int texId, std::pair<int, int> position) : texId(texId), position(position)
{
	active = 0;
	info["Object"] = "Button";
}
std::pair<int, int> Button_GI::getPosition()
{
	return position;
}

int Button_GI::getTex()
{
	return texId + active;
}
