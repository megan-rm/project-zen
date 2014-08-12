#ifndef SPRITESHEET_CACHE_H_
#define SPRITESHEET_CACHE_H_

#include <map>
#include <string>

#include "spritesheet.hpp"

class Spritesheet_Cache
{
private:
    std::map<std::string, Spritesheet*>
                                spritesheets;

public:

    /*ctr*/                     Spritesheet_Cache();
    /*dtr*/                     ~Spritesheet_Cache();
    Spritesheet* const          get_spritesheet(std::string);
};
#endif // SPRITESHEET_H_
