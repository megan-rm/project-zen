#include <iostream>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "game.hpp"

int main(int argc, char* args[])
{
    Game myGame;
    myGame.run();
    return 0;
}
