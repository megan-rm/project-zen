#include "entity.hpp"
#include <SDL2/SDL.h>

Entity::Entity(SDL_Texture** itsTexture)
{
    texture = itsTexture;
    SDL_QueryTexture(*itsTexture, NULL, NULL, &texRect->w, &texRect->h);
};
Entity::~Entity()
{

};

void Entity::draw(SDL_Renderer* gameRenderer)
{
    SDL_RenderCopy(gameRenderer, *texture, NULL, texRect);
};

void Entity::update()
{

};

void Entity::stretch()
{

};
