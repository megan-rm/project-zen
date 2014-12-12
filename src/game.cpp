#include <time.h>
#include <iostream>
#include <string>
#include <algorithm>
#include <random>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "game.hpp"
#include "particle_emitter.hpp"
#include "sun.hpp"
#include "spritesheet.hpp"

Game::Game()
{
    srand(time(NULL));

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
    for(unsigned int i = 0; i < entity_vector.size(); i++)
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
    SDL_SetRenderDrawBlendMode(game_renderer, SDL_BLENDMODE_BLEND);
    /// Night
    if(game_time.get_hour() >= game_time.get_night_time()
       || (game_time.get_hour() < game_time.get_morning_time()
        && game_time.get_hour() >= 0))
        SDL_SetRenderDrawColor(game_renderer, 0, 0, 50, 255);
    /// Morning
    else if(game_time.get_hour() >= game_time.get_morning_time()
            && game_time.get_hour() < game_time.get_noon_time())
        SDL_SetRenderDrawColor(game_renderer, 255, 250, 130, 255);
    /// Afternoon
    else if(game_time.get_hour() >= game_time.get_noon_time()
            && game_time.get_hour() < game_time.get_evening_time())
            SDL_SetRenderDrawColor(game_renderer, 64, 156, 255, 0);
    /// Evening
    else if(game_time.get_hour() >= game_time.get_evening_time()
            && game_time.get_hour() < game_time.get_night_time())
        SDL_SetRenderDrawColor(game_renderer, 255, 183, 76, 255);

    SDL_RenderPresent(game_renderer);
};

void Game::run()
{
    Entity* fakemoon = new Entity(texture_cache->get_texture("celestial_bodies"));
    fakemoon->set_sprite(32,32);

    fakemoon->stretch(64.0, 64.0);
    fakemoon->scale(3);
    fakemoon->move(20, 50.0);
    fakemoon->rotate(0.0);
    fakemoon->center_on_rect();
    entity_vector.push_back(fakemoon);

    Entity* fakemoon_glow = new Entity(texture_cache->get_texture("celestial_bodies"));
    fakemoon_glow->set_sprite(32,32);
    fakemoon_glow->scale(5);
    fakemoon_glow->center_on_rect();
    fakemoon_glow->move(-12.0, 20.0);
    fakemoon_glow->set_alpha(20);
    fakemoon_glow->set_blending(SDL_BLENDMODE_ADD);
    entity_vector.push_back(fakemoon_glow);


    Sun* newSun = new Sun(texture_cache->get_texture("celestial_bodies"), game_time);
    newSun->set_sprite(32, 32);
    newSun->scale(3);
    newSun->center_on_rect();
    entity_vector.push_back(newSun);


    Particle_Emitter* emitter = new Particle_Emitter(
                                texture_cache->get_texture("snow"),
                                800, 320, 240);
    emitter->set_shape(Particle_Emitter::RECTANGLE);
    emitter->set_blending(SDL_BLENDMODE_ADD);
    emitter->get_info()->set_start_color(255,255,255, 200);
    emitter->get_info()->set_end_color(255,255,255, 255);
    emitter->set_rect(640, 20);
    emitter->move(0,0);
    emitter->get_info()->set_life_span(10000);
    emitter->get_info()->set_velocity(0,0.5);
    emitter->get_info()->set_acceleration(0.0, 0.01);
    emitter->set_interval(0);
    emitter->get_info()->set_velocity_cap(0, 0.80);
    emitter->get_info()->set_start_size(.4);
    emitter->get_info()->set_end_size(.8);
    entity_vector.push_back(emitter);


    Particle_Emitter* newEmit = new Particle_Emitter(
                                    texture_cache->get_texture("star"),
                                    100);
    newEmit->set_shape(Particle_Emitter::POINT);
    newEmit->set_blending(SDL_BLENDMODE_ADD);
    newEmit->get_info()->set_start_color(255, 255, 255, 175);
    newEmit->get_info()->set_end_color(255, 255, 255, 255);
    newEmit->get_info()->set_acceleration(0.001, 1.0);
    newEmit->get_info()->set_velocity(0, 0.5);
    newEmit->get_info()->set_velocity_cap(0, 0.95);
    newEmit->get_info()->set_life_span(3000);
    newEmit->set_interval(333);
    SDL_Point emit_center;
    emit_center.x = 48;
    emit_center.y = 48;
    newEmit->attach_to_entity(*fakemoon, emit_center.x, emit_center.y);
    entity_vector.push_back(newEmit);



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
    return;
};
