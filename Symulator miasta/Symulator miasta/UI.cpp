#include "UI.h"
#include "Clock.h"
#include "Button.h"
UI::UI()
{
	mode = 0;
	buttons.push_back(new Button<Road>(10, { 25,715 }));
	buttons.push_back(new Button<HDense>(12, { 115,715 }));
	buttons.push_back(new Button<Industrial>(14, { 205,715 }));
	buttons.push_back(new Button<School>(16, { 295,715 }));


	buttons.push_back(new Button<Empty>(8, { 385,715 }));
}
std::vector<Button_GI*> UI::getButtons()
{
	return buttons;
}
Button_GI* UI::point(std::pair<int, int> mpos)
{
	for (Button_GI* b : buttons)
	{
		if (mpos.first >= b->getPosition().first && mpos.first <= b->getPosition().first + 80)
		{
			return b;
		}
	}
	return nullptr;
}
void UI::click(std::pair<int,int> mpos, Grid* grid)
{
	if (mode)
	{
		mode = 0;
		used->deactivate();
	}
	for (Button_GI* b : buttons)
	{
		if (mpos.first >= b->getPosition().first && mpos.first <= b->getPosition().first+80)
		{
			used = b;
			used->activate(grid);

			mode = 1;
		}
	}
	
}
void UI::onBoard(SDL_Event event, std::pair<int, int> mpos)
{
	if (!mode)
		return;
	switch (event.type)
	{
	case SDL_MOUSEBUTTONDOWN:
		if(used->mouseDown(mpos))
		{
			used->deactivate();
			mode = 0;
		}
		break;
	case SDL_MOUSEBUTTONUP:
		if (used->mouseUp(mpos))
		{
			used->deactivate();
			mode = 0;
		}
		break;

	default:
		break;
	}
	

}