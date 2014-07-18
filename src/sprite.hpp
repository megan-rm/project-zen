#ifndef SPRITE_H_
#define SPRITE_H_

#include <SDL2/SDL.h>

class Sprite
{
private:
    SDL_Texture*    sprite_sheet;
    SDL_Rect        clip_rect;

    unsigned int    current_clip;
    unsigned int    total_clips;

public:
    /*ctr*/         Sprite(SDL_Texture* texture);
    /*dtr*/         ~Sprite();

    SDL_Rect        get_clip_rect();
    SDL_Texture*    get_texture();

    unsigned int    get_sheet_width();
    unsigned int    get_sheet_height();

    unsigned int    get_clip_width();
    unsigned int    get_clip_height();

    unsigned int    get_current_clip();
    unsigned int    get_total_clips();

    void            set_clip_size(unsigned int, unsigned int);
    void            set_clip(unsigned int, unsigned int);
};
#endif
