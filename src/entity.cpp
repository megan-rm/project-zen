#include <SDL2/SDL.h>

#include "entity.hpp"

Entity::Entity(SDL_Texture* entity_texture)
{
    image = entity_texture;

    sprite.x = 0;
    sprite.y = 0;
    position_rect.x = 0;
    position_rect.y = 0;

    position.set(0.0, 0.0);

    rotation = 0;

    flip_type = SDL_FLIP_NONE;

    SDL_QueryTexture(image, NULL, NULL, &sprite.w, &sprite.h);
    SDL_QueryTexture(image, NULL, NULL, &position_rect.w, &position_rect.h);

    center.x = position_rect.w/2;
    center.y = position_rect.h/2;

    alive = true;
    blending = SDL_BLENDMODE_BLEND;
    alpha = 255;
};

Entity::~Entity()
{
    /// prevent nullifying any existing textures
    /// aka 'unload' the gun / pointer.
    /// texture = NULL;
};

void Entity::draw(SDL_Renderer* game_renderer)
{
    /* //For my debugging purposes.
    SDL_SetRenderDrawColor(game_renderer, 255, 64, 64, 128);
    SDL_RenderDrawRect(game_renderer, &position_rect);
    /**/
    if(alive == false)
        return;
    SDL_BlendMode old_blend;
    uint8_t old_alpha;

    SDL_GetTextureBlendMode(image, &old_blend);
    SDL_GetTextureAlphaMod(image, &old_alpha);

    SDL_SetTextureAlphaMod(image, alpha);
    SDL_SetTextureBlendMode(image, blending);

    SDL_RenderCopyEx(game_renderer, image, &sprite,
                     &position_rect, rotation, &center, flip_type);


    SDL_SetTextureBlendMode(image, old_blend);
    SDL_SetTextureAlphaMod(image, old_alpha);
};

void Entity::update()
{
    move(position.get_x(), position.get_y());
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
    /************************************
    * Possibly re-center here, too?
    ************************************/
    position_rect.w = sprite.w * scale;
    position_rect.h = sprite.h * scale;
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

const SDL_Rect* Entity::get_sprite()
{
    return &sprite;
}

bool Entity::is_alive()
{
    return alive;
};

void Entity::center_on_rect()
{
    center.x = position_rect.w/2;
    center.y = position_rect.w/2;
};

void Entity::set_center(int new_x, int new_y)
{
    center.x = new_x;
    center.y = new_y;
};

void Entity::set_blending(SDL_BlendMode new_blend)
{
    blending = new_blend;
};

void Entity::set_alpha(uint8_t new_alpha)
{
    alpha = new_alpha;
};

void Entity::set_sprite(unsigned int width, unsigned height)
{
    sprite.w = width;
    sprite.h = height;
};

void Entity::flip_sprite(SDL_RendererFlip new_flip)
{
    flip_type = new_flip;
};

