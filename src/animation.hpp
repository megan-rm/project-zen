#ifndef ANIMATION_H_
#define ANIMATION_H_

#include <vector>

#include <SDL2/SDL.h>

class Animation
{
private:
    /// not sure if i should bother with it being pointers
    std::vector<SDL_Rect*>  frames;
    unsigned int            total_frames;

    /// how long it takes to advance a frame
    unsigned int            frame_time;
    unsigned int            current_frame;

    unsigned int            frame_width;
    unsigned int            frame_height;

    enum                    play_style{FORWARD, REVERSE};

public:
    /*ctr*/                 Animation();
    /*dtr*/                 ~Animation();

    void                    set_frame_dimensions(int, int);
    void                    create_frame(SDL_Rect&);
    void                    create_frame(int, int);
    void                    next_frame();
    void                    previous_frame();
    void                    jump_to_frame();
};
#endif // ANIMATION_H_
