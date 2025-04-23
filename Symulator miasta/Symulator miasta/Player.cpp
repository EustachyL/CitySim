#include "Player.h"
#include "Log.h"

Player::Player(Grid* grid, UI* ui):grid(grid), ui(ui)
{
	//Clock::GetInstance().newOb(this);

}
Player::~Player() 
{
	delete ui;
}


void Player::mouse(SDL_Event event)
{
	std::pair<int, int> mPos;
	SDL_GetMouseState(&mPos.first , &mPos.second);
	Log::GetInstance().note("mysz");
	if (mPos.second > 700)
	{ 
		if(event.type == SDL_MOUSEBUTTONDOWN)
			ui->click(mPos, grid);
	}
	else
		ui->onBoard(event, mPos);
}
void Player::key(SDL_Event event)
{
	Log::GetInstance().note("klawisz");
	auto sym = event.key.keysym.sym;
	grid->moveOnMap({ (sym == SDLK_LEFT) * -1 + (sym == SDLK_RIGHT) ,(sym == SDLK_DOWN)  + (sym == SDLK_UP) * -1 });
		

}