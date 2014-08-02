#ifndef GAME_H_
#define GAME_H_

#include <map>
#include <string>
#include <time.h>
#include <vector>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "entity.hpp"
#include "graphic_cache.hpp"
#include "timer.hpp"
#include "realtime.hpp"

using std::string;
using std::map;

class Game
{
private:
    SDL_Window*         game_window;
    SDL_Renderer*       game_renderer;
    SDL_Event           game_input;

    std::vector<Entity*>
                        entity_vector;
    Graphic_Cache*      texture_cache;

    std::string         window_title;

    Realtime            game_time;

    unsigned int        screen_width;
    unsigned int        screen_height;
    unsigned int        frames_per_second;

    bool                running;

    unsigned short      morning;
    unsigned short      noon;
    unsigned short      evening;
    unsigned short      night;

    void                event_loop();
    void                update();
    void                draw();
    void                handle_input(SDL_Event&);

public:
    /*ctr*/             Game();
    /*dtr*/             ~Game();

    void                run();
};


#endif //GAME_H_
