#ifndef ENTITY_MANAGER_H_
#define ENTITY_MANAGER_H_

#include <string>
#include <map>

#include "SDL2/SDL.h"

#include "entity.hpp"

/*************************************
* TODO:
*  -Figure out what this will do...
*   (maybe hold world info, and share?)
*************************************/

class Entity_Manager
{
private:
    std::map<std::string, Entity*>
                    entities;


public:
    /*ctr*/         Entity_Manager();
    /*dtr*/         ~Entity_Manager();

    void            add(std::string entity_id, Entity* entity);
    void            remove(std::string entity_id);

    unsigned int    get_entity_count();
    Entity*         get_entity(std::string entity_id) const;

    void            draw_entities(SDL_Renderer* game_renderer);
};

#endif
