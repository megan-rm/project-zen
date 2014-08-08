#include <time.h>
#include <iostream>
#include <string>
#include <algorithm>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "game.hpp"
#include "particle_emitter.hpp"
#include "sun.hpp"

Game::Game()
{
    game_time.update();

    SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_EVENTS);
    IMG_Init(IMG_INIT_PNG);

    screen_width = 640;
    screen_height = 480;
    window_title = "Project Zen";
    frames_per_second = 60;

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
    delete texture_cache;
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
        case SDL_KEYDOWN: /// Use scancodes? and a input config?
            if(event.key.keysym.sym == SDLK_ESCAPE)
            {
                running = false;
            }
            if(event.key.keysym.sym == SDLK_SPACE)
            {
                if(!entity_vector.empty())
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
    game_time.update();

    for (unsigned int x = 0; x < entity_vector.size(); x++)
    {
        entity_vector.at(x)->update();
        if(!entity_vector.at(x)->is_alive())
        {
            delete entity_vector.at(x);
            std::swap(entity_vector.at(x), entity_vector.back());
            entity_vector.pop_back();
            x--;
        }
    }
};

void Game::draw()
{
    SDL_RenderClear(game_renderer);

    for (unsigned int x = 0; x < entity_vector.size(); x++)
    {
        entity_vector.at(x)->draw(game_renderer);
    }
    if(game_time.get_hour() >= game_time.get_night_time()
       || (game_time.get_hour() < game_time.get_morning_time()
        && game_time.get_hour() >= 0))
        SDL_SetRenderDrawColor(game_renderer, 0, 0, 50, 0);

    else if(game_time.get_hour() >= game_time.get_morning_time()
            && game_time.get_hour() < game_time.get_noon_time())
        SDL_SetRenderDrawColor(game_renderer, 255, 252, 127, 0);

    else if(game_time.get_hour() >= game_time.get_noon_time()
            && game_time.get_hour() < game_time.get_evening_time())
        SDL_SetRenderDrawColor(game_renderer, 64, 156, 255, 0);

    else if(game_time.get_hour() >= game_time.get_evening_time()
            && game_time.get_hour() < game_time.get_night_time())
        SDL_SetRenderDrawColor(game_renderer, 255, 183, 76, 0);

    SDL_RenderPresent(game_renderer);
};

void Game::run()
{
    Entity* newEntity = new Entity(texture_cache->get_texture("raindrop"));
    newEntity->stretch(48.0, 48.0);
    newEntity->move(320.0, 240.0);
    newEntity->rotate(20.0);
    newEntity->get_sprite()->set_clip_size(4, 4);
    newEntity->center_on_rect();
    entity_vector.push_back(newEntity);

    Entity* newEnt = new Entity(texture_cache->get_texture("raindrop"));

    newEnt->stretch(16.0, 16.0);
    newEnt->move(480.0, 320.0);
    newEnt->rotate(65.0);
    newEnt->get_sprite()->set_clip_size(4, 4);
    newEnt->center_on_rect();
    entity_vector.push_back(newEnt);

    Sun* newSun = new Sun(texture_cache->get_texture("celestial_bodies"), game_time);
    newSun->get_sprite()->set_clip_size(32, 32);
    newSun->get_sprite()->set_clip(1,2);
    newSun->move(320, 240);
    newSun->center_on_rect();
    newSun->scale(3);
    entity_vector.push_back(newSun);

    Particle_Emitter* emitter = new Particle_Emitter(
                                texture_cache->get_texture("raindrop"),
                                1500, 320, 240);
    emitter->get_info()->set_life_span(10000);
    emitter->get_info()->set_acceleration(0.04, 0.08);
    emitter->set_interval(10);
    emitter->get_info()->set_velocity_cap(0.99);
    entity_vector.push_back(emitter);

    running = true;
    unsigned int start_time;
    unsigned int elapsed_time;

    while(running)
    {
        start_time = SDL_GetTicks();

        handle_input(game_input);
        update();
        draw();

        elapsed_time = SDL_GetTicks() - start_time;

        if(elapsed_time < 16)
            SDL_Delay(1000 / frames_per_second - elapsed_time);
        std::cout << elapsed_time << std::endl;
    }
};
