#include "entity.hpp"
#include <SDL2/SDL.h>

Entity::Entity(SDL_Texture* entity_texture) : sprite(entity_texture)
{
    position_rect.x = 0;
    position_rect.y = 0;

    rotation = 0;

    flip_type = SDL_FLIP_NONE;

    SDL_QueryTexture(entity_texture, NULL, NULL, &position_rect.w, &position_rect.h);

    center_x = (float)position_rect.w/2;
    center_y = (float)position_rect.w/2;

    center.x = position_rect.w/2;
    center.y = position_rect.h/2;

    sprite.set_clip_size(4, 4);
};

Entity::~Entity()
{
    /// prevent nullifying any existing textures
    /// aka 'unload' the gun / pointer.
    //texture = NULL;
};

void Entity::draw(SDL_Renderer* game_renderer)
{
    //SDL_RenderCopyEx(game_renderer, texture, NULL, &frame_rect, rotation, &center, flip_type);
    SDL_RenderCopyEx(game_renderer, sprite.get_texture(), sprite.get_clip_rect(), &position_rect, rotation, &center, flip_type);
};

void Entity::update()
{

};

void Entity::stretch(float new_width, float new_height)
{
    position_rect.w = (int)new_width;
    position_rect.h = (int)new_height;

    center_x = (float)position_rect.w/2;
    center_y = (float)position_rect.w/2;

    center.x = position_rect.w/2;
    center.y = position_rect.h/2;
};

void Entity::move(float new_x, float new_y)
{
    position_rect.x = (int)new_x - center.x;
    position_rect.y = (int)new_y - center.y;
};

void Entity::rotate(double angle)
{
    rotation = angle;
};
