#include "gameObject.h"

GameObject::GameObject()
    : position(0.f, 0.f), size(1.f, 1.f), velocity(0.f), colour(1.f), rotation(0.f), sprite(), isStatic(true) {}

GameObject::GameObject(glm::vec2 pos, glm::vec2 size, Texture2D sprite, glm::vec3 colour, glm::vec2 velocity, bool isStatic)
    : position(pos), size(size), velocity(velocity), colour(colour), rotation(0.f), sprite(sprite), isStatic(isStatic) {}

void GameObject::Draw(SpriteRenderer &renderer)
{
    renderer.DrawSprite(this->sprite, this->position, this->size, this->rotation, this->colour);
}