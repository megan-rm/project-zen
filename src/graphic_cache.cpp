#include "graphic_cache.hpp"

Graphic_Cache::Graphic_Cache(SDL_Renderer* renderer)
{
    game_renderer = renderer;
};


/// I think I can get away with Map[key] = new_value, instead of iterating.
SDL_Texture* Graphic_Cache::get_texture(std::string filepath)
{
    std::map<std::string, SDL_Texture*>::iterator iter = texture_library.find(filepath);

    if (iter == texture_library.end())
    {
        SDL_Surface* loaded_surface = IMG_Load(filepath.c_str());
        if (!loaded_surface)
        {
            std::cout << "Error loading surface " << filepath
                      << " : " << SDL_GetError() << std::endl;
        }

        /*************************************
        * Ugly magenta color = transparent
        *************************************/
        SDL_SetColorKey(loaded_surface, SDL_TRUE, SDL_MapRGB(loaded_surface->format, 0xFF, 0, 0xFF));

        SDL_Texture* new_texture = SDL_CreateTextureFromSurface(game_renderer, loaded_surface);
        if(!new_texture)
        {
            std::cout << "Error creating texture " << filepath
                      << " : " << SDL_GetError() << std::endl;
        }

        iter = texture_library.insert(iter, make_pair(filepath, new_texture));
        SDL_FreeSurface(loaded_surface);
    }
    return iter->second;
};

/// throw this in the destructor. No need for this function.
void Graphic_Cache::cleanup()
{
    if ( !texture_library.empty() )
        for ( std::map<std::string,SDL_Texture*>::iterator iter = texture_library.begin(); iter != texture_library.end(); iter++ )
            SDL_DestroyTexture(iter->second);

    texture_library.clear();
};

Graphic_Cache::~Graphic_Cache()
{
    cleanup();
};
