#include "Informer.h"
Informer::Informer(Grid* grid, UI* ui):grid(grid), ui(ui)
{
}

void Informer::showInfo(TexManager* texManager)
{
	std::pair<int, int> mPos;
	Info* info;
	SDL_GetMouseState(&mPos.first, &mPos.second);
	if (mPos.second >= 700)
	{
		info=ui->point(mPos);
	}
	else
	{
		mPos.first = mPos.first / 50;
		mPos.second = mPos.second / 50;
		info=grid->getVisibleTile(mPos);
	}
	if (info == nullptr)
		return;
	texManager->renderInfo(info->getInfo());
}