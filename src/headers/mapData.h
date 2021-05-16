#ifndef MAP_DATA_H
#define MAP_DATA_H

#include <vector>
#include <glad/glad.h>
#include <glm/glm.hpp>
#include "gameObject.h"
#include "spriteRenderer.h"
#include "resourceManager.h"

class MapData
{
public:
    std::vector<GameObject> tiles;
    MapData() {}
    void Load(const char* file, unsigned int width, unsigned int height);
    void Draw(SpriteRenderer &renderer);

private:
    void init(std::vector<std::vector<unsigned int>> tileData, unsigned int width, unsigned int height);
};

#endif