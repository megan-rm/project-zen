#ifndef GRAPHIC_CACHE_H_
#define GRAPHIC_CACHE_H_

#include <iostream>
#include <map>
#include <string>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "spritesheet.hpp"
/******************************************
* TODO:
*   -default textures as sprites (1 clip
*    per image.
******************************************/

class Graphic_Cache
{
private:
    std::map<std::string, SDL_Texture*>
                                texture_library;

    std::map<std::string, Spritesheet*>
                                spritesheet_library;

    SDL_Renderer*               game_renderer;

    static const std::string    image_path;
    static const std::string    image_extension;
public:
    SDL_Texture*                get_texture(std::string);
    /*ctr*/                     Graphic_Cache(SDL_Renderer*);
    /*dtr*/                     ~Graphic_Cache();

    void                        create_sprite(std::string); /// not sure if this is useful...
                                /// name of image, width, height
    void                        create_spritesheet(std::string, int, int);
    Spritesheet*                get_spritesheet(std::string);
};
#endif
