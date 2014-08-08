#include <iostream>

#include "sprite.hpp"


Sprite::Sprite(SDL_Texture* texture)
{
    sprite_sheet = texture;
    clip_rect.x = 0;
    clip_rect.y = 0;

    if(sprite_sheet)
    {
        total_clips = 1;
        current_clip = 1;
    }
    else
    {
        total_clips = 0;
        current_clip = 0;
        std::cout << "Error setting up Sprite" << std::endl;
    }
    SDL_QueryTexture(sprite_sheet, NULL, NULL, &clip_rect.w, &clip_rect.h);


};

Sprite::~Sprite()
{
    sprite_sheet = NULL;
};

const SDL_Rect* Sprite::get_clip_rect()
{
    return &clip_rect;
};

SDL_Texture* Sprite::get_texture()
{
    return sprite_sheet;
};

unsigned int Sprite::get_sheet_width()
{
    int width = 0;
    SDL_QueryTexture(sprite_sheet, NULL, NULL, &width, NULL);
    return width;
};

unsigned int Sprite::get_sheet_height()
{
    int height = 0;
    SDL_QueryTexture(sprite_sheet, NULL, NULL, NULL, &height);
    return height;
};

unsigned int Sprite::get_clip_width()
{
    return clip_rect.w;
};

unsigned int Sprite::get_clip_height()
{
    return clip_rect.h;
};

unsigned int Sprite::get_current_clip()
{
    return current_clip;
};

unsigned int Sprite::get_total_clips()
{
    return total_clips;
};

void Sprite::set_clip_size(unsigned int width, unsigned int height)
{
    clip_rect.w = width;
    clip_rect.h = height;

    total_clips = ((this->get_sheet_height()/clip_rect.h) * (this->get_sheet_width()/clip_rect.w));
};

void Sprite::set_clip(unsigned int row, unsigned int column)
{
    if(((column-1) * clip_rect.w) > (this->get_sheet_width()
       || ((row-1) * clip_rect.h) > (this->get_sheet_height()))
      )
        return;

    clip_rect.x = (column-1) * clip_rect.w;
    clip_rect.y = (row-1) * clip_rect.h;
};

void Sprite::set_blend(SDL_BlendMode blendmode)
{
    SDL_SetTextureBlendMode(sprite_sheet, blendmode);
}

void Sprite::set_alpha(unsigned short alpha)
{
    SDL_SetTextureAlphaMod(sprite_sheet, alpha);
}
