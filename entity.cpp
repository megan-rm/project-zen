#include "entity.hpp"
#include <SDL2/SDL.h>

Entity::Entity(SDL_Texture* itsTexture)
{
    texture = itsTexture;

    texRect.x = 0;
    texRect.y = 0;

    rotation = 0;

    flip_type = SDL_FLIP_NONE;

    SDL_QueryTexture(itsTexture, NULL, NULL, &texRect.w, &texRect.h);

    center_x = (float)texRect.w/2;
    center_y = (float)texRect.w/2;

    center.x = texRect.w/2;
    center.y = texRect.h/2;
};

Entity::~Entity()
{
    /// prevent nullifying any existing textures
    texture = NULL;
};

void Entity::draw(SDL_Renderer* gameRenderer)
{
    SDL_RenderCopyEx(gameRenderer, texture, NULL, &texRect, rotation, &center, flip_type);
};

void Entity::update()
{

};

void Entity::stretch(float new_width, float new_height)
{
    texRect.w = (int)new_width;
    texRect.h = (int)new_height;

    center_x = (float)texRect.w/2;
    center_y = (float)texRect.w/2;

    center.x = texRect.w/2;
    center.y = texRect.h/2;
};

void Entity::move(float new_x, float new_y)
{
    texRect.x = (int)new_x - center.x;
    texRect.y = (int)new_y - center.y;
};

void Entity::rotate(double angle)
{
    rotation = angle;
};
