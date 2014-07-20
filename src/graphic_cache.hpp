#ifndef GRAPHIC_CACHE_H_
#define GRAPHIC_CACHE_H_

#include <iostream>
#include <map>
#include <string>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

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
