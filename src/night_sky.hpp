#ifndef NIGHT_SKY_H_
#define NIGHT_SKY_H_

#include <vector>

#include <SDL2/SDL.h>

#include "stars.hpp"

/******************************
* Probably best to have most
* static stars drawn to this,
* and 'twinkling' / constellation
* stars seperate.
******************************/

class Night_Sky
{
private:
    SDL_Texture*            sky_image;
    std::vector<Stars*>     twinkle_stars;

public:
    /*ctr*/             Night_Sky();
    /*dtr*/             ~Night_Sky();

    void                draw(SDL_Renderer* game_renderer);
    void                move(); /// moves circular ish.
};
#endif // NIGHT_SKY_H_
