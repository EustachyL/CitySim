#include "TexManager.h"
#include "Log.h"
#include "Budget.h"


TexManager::TexManager(SDL_Renderer* renderer, int tileSize, std::vector<Button_GI*> buttons) : renderer(renderer), tileSize(tileSize), buttons(buttons)
{
	importTextures(renderer);
	importUI(renderer);
	fColor.r = fColor.g = fColor.b = 255;
	bColor.r = bColor.g = bColor.b = 0;
	TTF_Init();
	font = TTF_OpenFont("add/arial.ttf", 20);
}
TexManager::~TexManager()
{
	delete[] textures;
	delete[] UI;
}

void TexManager::renderTile(int textureInt, int x, int y)
{
	SDL_Rect destR;
	destR.x = x*tileSize;
	destR.y = y * tileSize;
	destR.w = 50;
	destR.h = 50;

	SDL_RenderCopy(renderer, textures[textureInt], NULL, &destR);

}
void TexManager::renderImage(int textureInt, int x, int y, int w, int h)
{
	SDL_Rect destR;
	destR.x = x;
	destR.y = y;
	destR.w = w;
	destR.h = h;

	SDL_RenderCopy(renderer, UI[textureInt], NULL, &destR);
}
void TexManager::renderText(int x, int y, int w, int h, const char* text, SDL_Color color)
{
	
	SDL_Rect destR;
	destR.x = x;
	destR.y = y;
	destR.w = w;
	destR.h = h;
	SDL_Surface* imgTxt;

	imgTxt = TTF_RenderText_Blended(font, text, color);
	SDL_Texture* tempTex = SDL_CreateTextureFromSurface(renderer, imgTxt);
	SDL_FreeSurface(imgTxt);
	SDL_RenderCopy(renderer, tempTex, NULL, &destR);
	SDL_DestroyTexture(tempTex);
}

void TexManager::renderUI()
{
	
	std::string temp = std::to_string(Budget::GetInstance().getTreasury());
	std::string temp2 = std::to_string(Budget::GetInstance().getBalance());
	std::string temp3 = std::to_string(Budget::GetInstance().getPop());

	renderImage(0, 0, 700, 1600, 200);
	for (Button_GI* b : buttons)
	{
		renderImage(b->getTex(), b->getPosition().first, b->getPosition().second, 80, 80);
	}
	unsigned int min = 128;
	renderText(1440, 730, std::min(min, 21 * temp.length()), 28, temp.c_str(), fColor);
	renderText(1440, 785, std::min(min, 21 * temp2.length()), 28, temp2.c_str(), fColor);
	renderText(1440, 840, std::min(min, 21 * temp3.length()), 28, temp3.c_str(), fColor);
}

void TexManager::renderInfo(std::map<std::string, std::string>& info)
{
	unsigned int min = 200;
	if (info.find("Object") != info.end())
	{
		std::string temp= "Object: " + info["Object"];
		renderText(1150, 715, std::min(min, 21 * temp.length()), 28, temp.c_str(), bColor);
	}
	std::string s = info["Object"];
	info.erase("Object");
	std::string temp = "";
	int line = 0;
	for (const std::pair<std::string, std::string>& p  : info)
	{
		temp = p.first+": " +p.second;
		renderText(1150, 745 + line*27, std::min(min, 19 * temp.length()), 25, temp.c_str(), bColor);
		line++;
	}
	info["Object"]=s;
}


SDL_Texture* TexManager::assignTexture(const char* path, SDL_Renderer* renderer)
{
	SDL_Surface* surface = IMG_Load(path);
	SDL_Texture* tempTex = SDL_CreateTextureFromSurface(renderer, surface);
	SDL_FreeSurface(surface);
	return tempTex;
}


void TexManager::importTextures(SDL_Renderer* renderer)
{
	textures[0] = assignTexture("textures/Border.png", renderer);
	textures[1] = assignTexture("textures/Ground.png", renderer);
	textures[10] = assignTexture("textures/2-way_road_c.png", renderer);
	textures[11] = assignTexture("textures/2-way_road_l-p.png", renderer);
	textures[14] = assignTexture("textures/2-way_road_t-b.png", renderer);
	textures[15] = assignTexture("textures/2-way_road_l-b.png", renderer);
	textures[16] = assignTexture("textures/2-way_road_b-p.png", renderer);
	textures[18] = assignTexture("textures/2-way_road_l-t.png", renderer);
	textures[19] = assignTexture("textures/2-way_road_t-p.png", renderer);
	textures[20] = assignTexture("textures/HDense.png", renderer);
	textures[30] = assignTexture("textures/Industrial.png", renderer);
	textures[40] = assignTexture("textures/School.png", renderer);
	Log::GetInstance().note("textures imported");
}

void TexManager::importUI(SDL_Renderer* renderer)
{
	UI[0] = assignTexture("textures/UiB.png", renderer);
	UI[1] = assignTexture("textures/info_ui_bar.png", renderer);
	UI[8] = assignTexture("textures/Erase_button.png", renderer);
	UI[9] = assignTexture("textures/Erase_button_S.png", renderer);
	UI[10] = assignTexture("textures/Road_button.png", renderer);
	UI[11] = assignTexture("textures/Road_button_S.png", renderer);
	UI[12] = assignTexture("textures/HDense_button.png", renderer);
	UI[13] = assignTexture("textures/HDense_button_S.png", renderer);
	UI[14] = assignTexture("textures/Industrial_button.png", renderer);
	UI[15] = assignTexture("textures/Industrial_button_S.png", renderer);
	UI[16] = assignTexture("textures/School_button.png", renderer);
	UI[17] = assignTexture("textures/School_button_S.png", renderer);
	
	Log::GetInstance().note("UI imported");
}