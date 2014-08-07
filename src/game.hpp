#ifndef GAME_H_
#define GAME_H_

#include <map>
#include <string>
#include <time.h>
#include <vector>

/// Randomness. Maybe C++11 instead?
#include <cstdlib>
#include <ctime>


#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "entity.hpp"
#include "graphic_cache.hpp"
#include "timer.hpp"
#include "realtime.hpp"

using std::string;
using std::map;
using std::vector;

/***************************************
* TODO:
*  -Separate and move stuff into classes
*  -Need to throw away the FPS control
*   for something better.
***************************************/

class Game
{
private:
    SDL_Window*         game_window;
    SDL_Renderer*       game_renderer;
    SDL_Event           game_input;

    vector<Entity*>     entity_vector;
    Graphic_Cache*      texture_cache;

    string              window_title;

    Realtime            game_time;

    unsigned int        screen_width;
    unsigned int        screen_height;
    unsigned int        frames_per_second;

    bool                running;

    /// This should be part of the Sun/Moon

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
