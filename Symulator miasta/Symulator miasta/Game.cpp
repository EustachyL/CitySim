#include "Game.h"
#include "Log.h"

Game::Game()
{
	//Settings import
	std::vector<int> settingsArray = importSettings();
	Log::GetInstance().note("intialisation started");
	int flags = 0;
	int tileSize = 50;
	//fullscreen
	if (settingsArray[2]==1)
	{
		flags = SDL_WINDOW_FULLSCREEN;
	}
	//submodules initialization
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
	{
		Log::GetInstance().note("Initialazation failed");
		isActive = false;
		return;
	}
	//window
	mainWin = SDL_CreateWindow("main", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, settingsArray[0], settingsArray[1], flags);
	if (!mainWin)
	{
		Log::GetInstance().note("Window creation failed");
		isActive = false;
		return;
	}
	//renderer
	renderer = SDL_CreateRenderer(mainWin, -1, 0);
	if (!renderer)
	{
		Log::GetInstance().note("Renderer creation failed");
		isActive = false;
		return;
	}
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
	//Grid
	grid = new Grid(settingsArray[4], settingsArray[3], settingsArray[0]/ tileSize, settingsArray[1]/ tileSize -4);
	//UI
	UI* ui = new UI();
	//TexManager
	texManager = new TexManager(renderer, tileSize, ui->getButtons());
	//Clock
	Clock::GetInstance().newOb(this);
	//Player
	player = new Player(grid, ui);
	//Informer
	informer = new Informer(grid, ui);
	//Budget
	Budget::GetInstance();
	



	isActive = true;

	Log::GetInstance().note("intialisation sucessful");
	Clock::GetInstance().start();

}


Game::~Game()
{
	delete grid;
	delete texManager;
	delete player;
	delete informer;
}


std::vector<int> Game::importSettings()
{
	std::vector<int> settingsArray;
	std::ifstream sFile("Settings.ini");
	int tmp;
	while (sFile)
	{
		sFile >> tmp;
		settingsArray.push_back(tmp);
	}

	return settingsArray;
}

void Game::events()
{
	SDL_Event event;
	SDL_PollEvent(&event);
	switch (event.type)
	{
		case SDL_QUIT:
			clean();
			break;

		case SDL_KEYDOWN:
			player->key(event);
			break;
		case SDL_MOUSEBUTTONDOWN:
			player->mouse(event);
			break;
		case SDL_MOUSEBUTTONUP:
			player->mouse(event);
			break;

		default:
			break;
	}

}
void Game::mTickUpdate()
{

}



void Game::render()
{
	SDL_RenderClear(renderer);
	renderVisibleArea();
	texManager->renderUI();
	informer->showInfo(texManager);
	SDL_RenderPresent(renderer);
}


void Game::clean()
{
	SDL_DestroyWindow(mainWin);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
	isActive = false;
	Log::GetInstance().note("Game closed");
	Clock::GetInstance().stop();

}


SDL_Renderer* Game::getRenderer()
{
	return renderer;
}

void Game::renderVisibleArea()
{
	std::pair<int, int> horizontal, vertical;
	grid->getCurrentRange(horizontal, vertical);
	//Log::GetInstance().note("render area: "+ std::to_string(horizontal.first)+"x" + std::to_string(vertical.first)+" to " + std::to_string(horizontal.second) + "x" + std::to_string(vertical.second));
	int baseX = 0, baseY = 0;
	for (int i = horizontal.first; i < horizontal.second; ++i)
	{
		baseY = 0;
		for (int j = vertical.first; j < vertical.second; ++j)
		{
			texManager->renderTile(grid->getTile({ i,j })->getTex(), baseX, baseY);
			baseY++;
		}

		baseX++;
	}
	

}

void Game::tickUpdate()
{
	events();
	render();
}

bool Game::active()
{
	return isActive;
} 