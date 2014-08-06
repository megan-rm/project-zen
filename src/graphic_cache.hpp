#ifndef GRAPHIC_CACHE_H_
#define GRAPHIC_CACHE_H_

#include <iostream>
#include <map>
#include <string>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>


/******************************************
* TODO:
*  -Add a static string for the default
*   image location, ie: "../../resources/images/"
*  -Also add static string for the default
*   image extension: ".png"
*   (this will allow map keys to be shorter. IE:
*    "raindrop" instead of the whole path)
******************************************/

class Graphic_Cache
{
private:
    std::map<std::string, SDL_Texture*>
                        texture_library;
    SDL_Renderer*       game_renderer;
public:
    SDL_Texture*    get_texture(std::string);
    void            cleanup();
    /*ctr*/         Graphic_Cache(SDL_Renderer*);
    /*dtr*/         ~Graphic_Cache();
};
#endif
