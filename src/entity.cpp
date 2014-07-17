#include "entity.hpp"
#include <SDL2/SDL.h>

Entity::Entity(SDL_Texture* entity_texture)
{
    texture = entity_texture;

    frame_rect.x = 0;
    frame_rect.y = 0;

    rotation = 0;

    flip_type = SDL_FLIP_NONE;

    SDL_QueryTexture(entity_texture, NULL, NULL, &frame_rect.w, &frame_rect.h);

    center_x = (float)frame_rect.w/2;
    center_y = (float)frame_rect.w/2;

    center.x = frame_rect.w/2;
    center.y = frame_rect.h/2;
};

Entity::~Entity()
{
    /// prevent nullifying any existing textures
    /// aka 'unload' the gun / pointer.
    texture = NULL;
};

void Entity::draw(SDL_Renderer* game_renderer)
{
    SDL_RenderCopyEx(game_renderer, texture, NULL, &frame_rect, rotation, &center, flip_type);
};

void Entity::update()
{

};

void Entity::stretch(float new_width, float new_height)
{
    frame_rect.w = (int)new_width;
    frame_rect.h = (int)new_height;

    center_x = (float)frame_rect.w/2;
    center_y = (float)frame_rect.w/2;

    center.x = frame_rect.w/2;
    center.y = frame_rect.h/2;
};

void Entity::move(float new_x, float new_y)
{
    frame_rect.x = (int)new_x - center.x;
    frame_rect.y = (int)new_y - center.y;
};

void Entity::rotate(double angle)
{
    rotation = angle;
};
