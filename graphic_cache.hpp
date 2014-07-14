#ifndef GRAPHIC_CACHE_H_
#define GRAPHIC_CACHE_H_

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <map>
#include <string>

class Graphic_Cache
{
private:
    std::map<std::string, SDL_Texture*>
                        textureLibrary;
    SDL_Renderer*       gameRenderer;
public:
    SDL_Texture*    getTexture(std::string);
    void            cleanup();
    /*ctr*/         Graphic_Cache(SDL_Renderer*);
    /*dtr*/         ~Graphic_Cache();
};
#endif
