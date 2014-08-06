#include <SDL2/SDL.h>

#include "entity.hpp"

Entity::Entity(SDL_Texture* entity_texture) : sprite(entity_texture)
{
    position_rect.x = 0;
    position_rect.y = 0;

    position.set(0.0, 0.0);

    rotation = 0;

    flip_type = SDL_FLIP_NONE;

    SDL_QueryTexture(entity_texture, NULL, NULL, &position_rect.w, &position_rect.h);

    center.x = position_rect.w/2;
    center.y = position_rect.h/2;
};

Entity::~Entity()
{
    /// prevent nullifying any existing textures
    /// aka 'unload' the gun / pointer.
    /// texture = NULL;
};

void Entity::draw(SDL_Renderer* game_renderer)
{
    SDL_SetRenderDrawColor(game_renderer, 255, 64, 64, 128);
    SDL_RenderDrawRect(game_renderer, &position_rect); /// For my debugging purposes.
    SDL_RenderCopyEx(game_renderer, this->sprite.get_texture(), this->sprite.get_clip_rect(), &position_rect, rotation, &center, flip_type);
};

void Entity::update()
{
    rotation += 0.1;
    Vector2D movement(0.5, 0.3);

    position = position + movement;
    move(position.get_x(), position.get_y());

    if(position_rect.x >= 650)
        move(-10.0, position.get_y());
    if(position_rect.y >= 490)
        move(position.get_x(), -10.0);
};

void Entity::stretch(int new_width, int new_height)
{
    /************************************
    * Possibly re-center here?
    ************************************/
    position_rect.w = new_width;
    position_rect.h = new_height;
};

void Entity::scale(float scale)
{
    position_rect.w = sprite.get_clip_rect()->w * scale;
    position_rect.h = sprite.get_clip_rect()->h * scale;
};

void Entity::move(float new_x, float new_y)
{
    position.set(new_x, new_y);
    position_rect.x = (int)position.get_x();
    position_rect.y = (int)position.get_y();
};

void Entity::rotate(float angle)
{
    rotation = angle;
};

Sprite* const Entity::get_sprite()
{
    return &sprite;
}

void Entity::center_on_clip()
{
    center.x = position_rect.w/2;
    center.y = position_rect.w/2;
};

void Entity::set_center(float new_x, float new_y)
{
    center.x = (int)new_x;
    center.y = (int)new_y;
};

void Entity::flip_sprite(SDL_RendererFlip new_flip)
{
    flip_type = new_flip;
};
