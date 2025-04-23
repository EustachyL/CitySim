#include "Grid.h"
#include "Log.h"
Grid::Grid(int width, int height, int vWidth, int vHeight):height(height),width(width), vHeight(vHeight/2), vWidth(vWidth/2)
{
	centered = { width / 2, height / 2 };
	Log::GetInstance().note("Grid "+ std::to_string(width) +" by "+ std::to_string(height)+" initialized");
	grid = new Tile**[height];
	//Wypelnianie mapy domyslnymi komorkami
	std::map<int,Tile*> empty;
	for (int i = 0; i < height; i++)
	{
		grid[i] = new Tile*[width];
		for (int j = 0; j < width; j++)
		{
			if (i == 0 || i == height - 1 || j == 0 || j == height - 1) // Ozanczenie krawedzi mapy
			{
				grid[i][j] = new Empty(0, empty);
				continue;
			}
			grid[i][j] = new Empty(1,empty);
		}
	}
	Log::GetInstance().note("Grid generated");
}

Grid::~Grid()
{
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
			delete grid[i][j];
		delete[] grid[i];
	}
	delete[] grid;

}

void Grid::getCurrentRange(std::pair<int, int>& horizontal, std::pair<int, int>& vertical)
{
	horizontal = { centered.first - vWidth, centered.first + vWidth };
	vertical = { centered.second - vHeight, centered.second + vHeight };
}

Tile* Grid::getTile(std::pair<int, int> cords)
{
	return grid[cords.second][cords.first];
}
Tile* Grid::getVisibleTile(std::pair<int, int> cords)
{
	return grid[cords.second+centered.second - vHeight][cords.first+centered.first - vWidth];
}

void Grid::moveOnMap(std::pair<int, int> movement)
{	
	movement.first+=centered.first;
	movement.second += centered.second;;
	if (!(movement.first > width - vWidth || movement.first < vWidth || movement.second> height - vHeight || movement.second < vHeight))
		centered = movement;
	
}
void Grid::replace(std::pair<int, int> cords, Tile* newTile)
{
	delete grid[cords.second][cords.first];
	grid[cords.second][cords.first] = newTile;
	Tile* tile = grid[cords.second][cords.first];
	Log::GetInstance().note("build on" + std::to_string(cords.second)+"x"+std::to_string(cords.first));
	

}
void Grid::build(std::pair<int, int> cords, Tile* newTile)
{
	std::pair<int, int> hor, ver;
	getCurrentRange(hor, ver);
	cords = { cords.first + hor.first, cords.second + ver.first };
	replace(cords, newTile);
}
void Grid::updateRange(std::pair<int, int> cords, std::pair<int, int> endcords)
{
	for (int i=cords.first;i<=endcords.first;++i)
	{
		for (int j = cords.second;j <= endcords.second;++j)
		{
			grid[j][i]->update();
		}
	}
}