#ifndef ENTITY_H_
#define ENTITY_H_

#include <SDL.h>
#include <SDL_image.h>

class Entity
{
private:
  SDL_Rect*       texRect;
  SDL_Texture**   texture;
public:
  /*ctr*/         Entity(SDL_Texture**);
  /*dtr*/         ~Entity();

  void            draw(SDL_Renderer*);
  void            update();
  void            stretch();
};

#endif
