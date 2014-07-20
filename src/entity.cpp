#include <SDL2/SDL.h>

#include "entity.hpp"

Entity::Entity(SDL_Texture* entity_texture) : sprite(entity_texture)
{
    position_rect.x = 0;
    position_rect.y = 0;

    position_x = 0.0;
    position_y = 0.0;

    rotation = 0;

    flip_type = SDL_FLIP_NONE;

    SDL_QueryTexture(entity_texture, NULL, NULL, &position_rect.w, &position_rect.h);

    center_x = (float)position_rect.w/2;
    center_y = (float)position_rect.w/2;

    center.x = position_rect.w/2;
    center.y = position_rect.h/2;
};

Entity::~Entity()
{
    /// prevent nullifying any existing textures
    /// aka 'unload' the gun / pointer.
    //texture = NULL;
};

void Entity::draw(SDL_Renderer* game_renderer)
{
    SDL_RenderCopyEx(game_renderer, this->sprite.get_texture(), this->sprite.get_clip_rect(), &position_rect, rotation, &center, flip_type);
};

void Entity::update()
{
    rotation += 0.1;
    position_x += 0.5;
    position_y += 0.3;

    position_rect.x = (int)position_x;
    position_rect.y = (int)position_y;
    if(position_x >= 650)
        move(-10.0, position_y);
    if(position_rect.y >= 490)
        move(position_x, -10.0);
};

void Entity::stretch(float new_width, float new_height)
{
    position_rect.w = (int)new_width;
    position_rect.h = (int)new_height;
};

void Entity::move(float new_x, float new_y)
{
    position_x = new_x - center.x;
    position_y = new_y - center.y;
};

void Entity::rotate(double angle)
{
    rotation = angle;
};

Sprite* const Entity::get_sprite()
{
    return &sprite;
}

void Entity::center_on_clip()
{
    center_x = float(position_rect.w/2);
    center_y = float(position_rect.h/2);

    center.x = position_rect.w/2;
    center.y = position_rect.w/2;
};

void Entity::set_center(float new_x, float new_y)
{
    center_x = new_x;
    center_y = new_y;
    center.x = (int)new_x;
    center.y = (int)new_y;
};

void Entity::flip_sprite(SDL_RendererFlip new_flip)
{
    flip_type = new_flip;
};
