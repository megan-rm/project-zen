#include "graphic_cache.hpp"

const std::string Graphic_Cache::image_path = "../../resources/images/";
const std::string Graphic_Cache::image_extension = ".png";

Graphic_Cache::Graphic_Cache(SDL_Renderer* renderer)
{
    game_renderer = renderer;
};


/// I think I can get away with Map[key] = new_value, instead of iterating.
SDL_Texture* Graphic_Cache::get_texture(std::string filename)
{
    std::map<std::string, SDL_Texture*>::iterator iter = texture_library.find(filename);

    if (iter == texture_library.end())
    {
        std::string filepath = image_path + filename + image_extension;

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

Graphic_Cache::~Graphic_Cache()
{
    if ( !texture_library.empty() )
        for ( std::map<std::string,SDL_Texture*>::iterator iter = texture_library.begin(); iter != texture_library.end(); iter++ )
            SDL_DestroyTexture(iter->second);

    texture_library.clear();
};
