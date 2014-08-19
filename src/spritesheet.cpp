#include <iostream>

#include "spritesheet.hpp"


Spritesheet::Spritesheet(SDL_Texture* texture)
{
    image = texture;
    clip_rect.x = 0;
    clip_rect.y = 0;

    if(image)
    {
        total_clips = 1;
        current_clip = 1;
    }
    else
    {
        total_clips = 0;
        current_clip = 0;
        std::cout << "Error setting up Spritesheet" << std::endl;
    }
    SDL_QueryTexture(image, NULL, NULL, &clip_rect.w, &clip_rect.h);


};

Spritesheet::~Spritesheet()
{
    image = NULL;
};

const SDL_Rect* Spritesheet::get_clip_rect()
{
    return &clip_rect;
};

SDL_Texture* Spritesheet::get_texture()
{
    return image;
};

unsigned int Spritesheet::get_sheet_width()
{
    int width = 0;
    SDL_QueryTexture(image, NULL, NULL, &width, NULL);
    return width;
};

unsigned int Spritesheet::get_sheet_height()
{
    int height = 0;
    SDL_QueryTexture(image, NULL, NULL, NULL, &height);
    return height;
};

unsigned int Spritesheet::get_clip_width()
{
    return clip_rect.w;
};

unsigned int Spritesheet::get_clip_height()
{
    return clip_rect.h;
};

unsigned int Spritesheet::get_current_clip()
{
    return current_clip;
};

unsigned int Spritesheet::get_total_clips()
{
    return total_clips;
};

void Spritesheet::set_clip_size(unsigned int width, unsigned int height)
{
    clip_rect.w = width;
    clip_rect.h = height;

    total_clips = ((this->get_sheet_height()/clip_rect.h) * (this->get_sheet_width()/clip_rect.w));
};

void Spritesheet::set_clip(unsigned int row, unsigned int column)
{
    if( ((column-1) * clip_rect.w) > (this->get_sheet_width())
       || ((row-1) * clip_rect.h) > (this->get_sheet_height())
      )
        return;

    clip_rect.x = (column-1) * clip_rect.w;
    clip_rect.y = (row-1) * clip_rect.h;
};

void Spritesheet::set_clip(unsigned int clip)
{
    /// total_clips-1 because it's a 0 based 'grid'
    if (clip > (total_clips - 1))
        return;

    /// find total rows and columns in sprite_sheet, on a 0 based 'grid'
    unsigned int row = (this->get_sheet_height() / clip_rect.h) - 1;
    unsigned int column = (this->get_sheet_width() / clip_rect.w) - 1;

    /// set clip_rect to the appropriate x/y
    row = (clip % column);
    column = (clip / column);

    clip_rect.x = column * clip_rect.w;
    clip_rect.y = row * clip_rect.h;
    return;
};


void Spritesheet::set_blend(SDL_BlendMode blendmode)
{
    SDL_SetTextureBlendMode(image, blendmode);
}

void Spritesheet::set_alpha(uint8_t alpha)
{
    SDL_SetTextureAlphaMod(image, alpha);
}
