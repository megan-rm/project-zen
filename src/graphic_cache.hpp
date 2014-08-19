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
    SDL_Texture*                get_texture(std::string texture_id);
    /*ctr*/                     Graphic_Cache(SDL_Renderer* game_renderer);
    /*dtr*/                     ~Graphic_Cache();

    void                        create_sprite(std::string sprite_id); /// not sure if this is useful...
                                /// name of image, width, height
    void                        create_spritesheet(std::string image_id, int sprite_width, int sprite_height);
    Spritesheet*                get_spritesheet(std::string spritesheet_id);
};
#endif
