#include "graphic_cache.hpp"

Graphic_Cache::Graphic_Cache(SDL_Renderer* renderer)
{
    gameRenderer = renderer;
};

SDL_Texture* Graphic_Cache::getTexture(std::string filepath)
{
    std::map<std::string, SDL_Texture*>::iterator iter = textureLibrary.find(filepath);

    if (iter == textureLibrary.end())
    {
        SDL_Surface* loadedSurface = IMG_Load(filepath.c_str());
        SDL_Texture* newTexture = SDL_CreateTextureFromSurface(gameRenderer, loadedSurface);
        iter = textureLibrary.insert(iter, make_pair(filepath, newTexture));

        SDL_FreeSurface(loadedSurface);
    }
    return iter->second;
};

void Graphic_Cache::cleanup()
{
    if ( !textureLibrary.empty() )
        for ( std::map<std::string,SDL_Texture*>::iterator iter = textureLibrary.begin(); iter != textureLibrary.end(); iter++ )
            SDL_DestroyTexture(iter->second);

    textureLibrary.clear();
};

Graphic_Cache::~Graphic_Cache()
{
    cleanup();
};
