#include "mapData.h"
#include <fstream>
#include <sstream>

void MapData::Load(const char* file, unsigned int width, unsigned int height)
{
    this->tiles.clear();
    unsigned int tileCode;
    MapData data;
    std::string line;
    std::ifstream fstream(file);
    std::vector<std::vector<unsigned int>> tileData;
    if(fstream)
    {
        while(std::getline(fstream, line))
        {
            std::istringstream sstream(line);
            std::vector<unsigned int> row;
            while (sstream >> tileCode)
                row.push_back(tileCode);
            tileData.push_back(row);
        }
        if(tileData.size() > 0)
            this->init(tileData, width, height);
    }
}

void MapData::Draw(SpriteRenderer &renderer)
{
    for(int i = 0; i < tiles.size(); i++)
    {
        tiles[i].Draw(renderer);
    }
}

void MapData::init(std::vector<std::vector<unsigned int>> tileData, unsigned int width, unsigned int height)
{
    unsigned int h = tileData.size();
    unsigned int w = tileData[0].size();
    float unitWidth = width / (float)w, unitHeight = height / (float)h;
    for(int y = 0; y < h; y++)
    {
        for(int x = 0; x < w; x++)
        {
            if(tileData[x][y] != 0)
            {
                glm::vec2 pos(unitWidth * x, unitHeight * y);
                glm::vec2 size(unitWidth, unitHeight);
                GameObject obj(pos, size, ResourceManager::GetTexture("icon"));
                this->tiles.push_back(obj);
            }
        }
    }
}