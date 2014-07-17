#include "game.hpp"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <time.h>
#include <iostream>
#include <string>

Game::Game()
{
    time(&game_time);
    time_info = localtime(&game_time);


    screen_width = 640;
    screen_height = 480;
    window_title = "Project Zen";

    morning = 7;
    noon = 12;
    evening = 17;
    night = 20;

    game_window = SDL_CreateWindow(window_title.c_str(),
              SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
              screen_width, screen_height, SDL_WINDOW_SHOWN);
    if(!game_window)
    {
        std::cout << "Problem creating window: " << SDL_GetError()
                  << std::endl;
    }

    game_renderer = SDL_CreateRenderer(game_window, 0, SDL_RENDERER_ACCELERATED);
    if (!game_renderer)
    {
        std::cout << "Problem creating renderer: " << SDL_GetError()
                  << std::endl;
    }

    texture_cache = new Graphic_Cache(game_renderer);
};

Game::~Game()
{
    SDL_DestroyWindow(game_window);
    SDL_DestroyRenderer(game_renderer);
    texture_cache->cleanup();
    SDL_Quit();
};

void Game::handle_input(SDL_Event& event)
{
    while(SDL_PollEvent(&event))
    {
        switch (event.type)
        {
        case SDL_QUIT:
            running = false;
            break;
        case SDL_KEYDOWN:
            if(event.key.keysym.sym == SDLK_ESCAPE)
            {
                running = false;
            }
            break;
        default:
            break;
        }
    }
}

void Game::update()
{
    time(&game_time);
    time_info = localtime(&game_time);
};

void Game::draw()
{

    SDL_RenderClear(game_renderer);

    hour = time_info->tm_hour;
    minute = time_info->tm_min;
    second = time_info->tm_sec;
    if(hour >= night)
        SDL_SetRenderDrawColor(game_renderer, 0, 0, 50, 0);
    else if(hour >= morning && hour < noon)
        SDL_SetRenderDrawColor(game_renderer, 255, 252, 127, 0);
    else if(hour >= noon && hour < evening)
        SDL_SetRenderDrawColor(game_renderer, 64, 156, 255, 0);
    else if(hour >= evening && hour < night)
        SDL_SetRenderDrawColor(game_renderer, 255, 183, 76, 0);

    for (unsigned int x = 0; x < entity_vector.size(); x++)
    {
        entity_vector.at(x)->draw(game_renderer);
    }
    SDL_RenderPresent(game_renderer);
};

void Game::run()
{
    //texture_cache->get_texture("../../raindrop.png");

    Entity* newEntity = new Entity(texture_cache->get_texture("../../resources/images/raindrop.png"));
    newEntity->stretch(48.0, 48.0);
    newEntity->move(320.0, 240.0);
    newEntity->rotate(20.0);
    entity_vector.push_back(newEntity);

    Entity* newEnt = new Entity(texture_cache->get_texture("../../resources/images/raindrop.png"));
    newEnt->stretch(16.0, 16.0);
    newEnt->move(480.0, 320.0);
    newEnt->rotate(65.0);
    entity_vector.push_back(newEnt);

    running = true;
    while(running)
    {
        handle_input(game_input);
        update();
        draw();
        SDL_Delay(16);
    }
};
