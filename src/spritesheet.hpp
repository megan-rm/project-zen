#ifndef SPRITESHEET_H_
#define SPRITESHEET_H_

#include <SDL2/SDL.h>

/********************************
* TODO:
*  -set_blend() maybe belongs to
*   entities...
********************************/

class Spritesheet
{
private:
    SDL_Texture*    image;
    SDL_Rect        clip_rect; /// just a w/h needed

    unsigned int    current_clip; /// unneeded
    unsigned int    total_clips;

public:
    /*ctr*/         Spritesheet(SDL_Texture*);
    /*dtr*/         ~Spritesheet();

    /// SDL_Rect    get_clip(index); instead?
    const SDL_Rect* get_clip_rect();

    SDL_Texture*    get_texture();

    unsigned int    get_sheet_width();
    unsigned int    get_sheet_height();

    unsigned int    get_clip_width();
    unsigned int    get_clip_height();

    unsigned int    get_current_clip(); /// unneeded, used for animations
    unsigned int    get_total_clips();

    void            set_clip_size(unsigned int width, unsigned int height);

    ///             these are unneeded
    void            set_clip(unsigned int column, unsigned int row);
    void            set_clip(unsigned int index);
    void            set_blend(SDL_BlendMode);
    void            set_alpha(uint8_t alpha);
};
#endif
