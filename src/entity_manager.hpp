#ifndef ENTITY_MANAGER_H_
#define ENTITY_MANAGER_H_

#include <string>
#include <map>

#include "SDL2/SDL.h"

#include "entity.hpp"

class Entity_Manager
{
private:
    std::map<std::string, Entity*>
                    entities;


public:
    /*ctr*/         Entity_Manager();
    /*dtr*/         ~Entity_Manager();

    void            add(std::string, Entity*);
    void            remove(std::string);

    unsigned int    get_entity_count();
    Entity*         get_entity(std::string) const;

    void            draw_entities(SDL_Renderer* game_renderer);
};

#endif
