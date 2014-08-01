#include <time.h>
#include <iostream>
#include <string>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "game.hpp"
#include "particle.hpp"

Game::Game()
{
    time(&game_time);
    time_info = localtime(&game_time);

    SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_EVENTS);
    IMG_Init(IMG_INIT_PNG);

    screen_width = 640;
    screen_height = 480;
    window_title = "Project Zen";
    frames_per_second = 60;

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

    game_renderer = SDL_CreateRenderer(game_window, -1,
                                       SDL_RENDERER_ACCELERATED);
    if (!game_renderer)
    {
        std::cout << "Problem creating renderer: " << SDL_GetError()
                  << std::endl;
    }

    texture_cache = new Graphic_Cache(game_renderer);
};

Game::~Game()
{
    for(int i = 0; i < entity_vector.size(); i++)
        delete entity_vector.at(i);

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
            if(event.key.keysym.sym == SDLK_SPACE)
            {
                entity_vector.pop_back();
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

    for (unsigned int x = 0; x < entity_vector.size(); x++)
    {
        entity_vector.at(x)->update();
    }
};

void Game::draw()
{

    SDL_RenderClear(game_renderer);

    hour = time_info->tm_hour;
    minute = time_info->tm_min;
    second = time_info->tm_sec;

    for (unsigned int x = 0; x < entity_vector.size(); x++)
    {
        entity_vector.at(x)->draw(game_renderer);
    }
    if(hour >= night || (hour < morning && hour >= 0))
        SDL_SetRenderDrawColor(game_renderer, 0, 0, 50, 0);
    else if(hour >= morning && hour < noon)
        SDL_SetRenderDrawColor(game_renderer, 255, 252, 127, 0);
    else if(hour >= noon && hour < evening)
        SDL_SetRenderDrawColor(game_renderer, 64, 156, 255, 0);
    else if(hour >= evening && hour < night)
        SDL_SetRenderDrawColor(game_renderer, 255, 183, 76, 0);
    SDL_RenderPresent(game_renderer);
};

void Game::run()
{
    Entity* newEntity = new Entity(texture_cache->get_texture(
                                   "../../resources/images/raindrop.png"));
    newEntity->stretch(48.0, 48.0);
    newEntity->move(320.0, 240.0);
    newEntity->rotate(20.0);
    newEntity->get_sprite()->set_clip_size(4, 4);
    newEntity->center_on_clip();
    entity_vector.push_back(newEntity);

    Entity* newEnt = new Entity(texture_cache->get_texture(
                                "../../resources/images/raindrop.png"));

    Particle* newPart = new Particle(texture_cache->get_texture(
                                "../../resources/images/raindrop.png"));
    newPart->move(120.0, 120.0);
    newPart->rotate(20.0);
    newPart->stretch(16,16);
    newPart->get_sprite()->set_clip_size(4, 4);
    newPart->center_on_clip();
    entity_vector.push_back(newPart);

    newEnt->stretch(16.0, 16.0);
    newEnt->move(480.0, 320.0);
    newEnt->rotate(65.0);
    newEnt->get_sprite()->set_clip_size(4, 4);
    newEnt->center_on_clip();
    entity_vector.push_back(newEnt);

    running = true;
    while(running)
    {
        const unsigned int start_time = SDL_GetTicks();
        handle_input(game_input);
        update();
        draw();
        const unsigned int elapsed_time = SDL_GetTicks() - start_time;

        if(elapsed_time < 16)
            SDL_Delay(1000 / frames_per_second - elapsed_time);
    }
};
