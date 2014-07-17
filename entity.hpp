#ifndef ENTITY_H_
#define ENTITY_H_

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

class Entity
{
private:
    SDL_Rect            frame_rect;
    SDL_Texture*        texture;
    double              rotation;
    float               center_x;
    float               center_y;
    SDL_Point           center;
    SDL_RendererFlip    flip_type;

public:
  /*ctr*/               Entity(SDL_Texture*);
  /*dtr*/               ~Entity();

  void                  draw(SDL_Renderer*);
  void                  update();
  void                  stretch(float, float);
  void                  move(float, float);
  void                  rotate(double angle);
};

#endif
