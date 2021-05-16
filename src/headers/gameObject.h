#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <glad/glad.h>
#include <glm/glm.hpp>
#include "texture.h"
#include "spriteRenderer.h"

class GameObject
{
public:
    glm::vec2 position, size, velocity;
    glm::vec3 colour;
    float rotation;
    bool isStatic;
    Texture2D sprite;
    GameObject();
    GameObject(glm::vec2 pos, glm::vec2 size, Texture2D sprite, glm::vec3 colour = glm::vec3(1.f), glm::vec2 velocity = glm::vec2(0.f, 0.f), bool isStatic = true);
    virtual void Draw(SpriteRenderer &renderer);
};

#endif