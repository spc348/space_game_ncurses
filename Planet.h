#ifndef PLANET_H
#define PLANET_H

#include "SpaceObject.h"
#include <ncurses.h>

class Planet : public SpaceObject{
public:
    Planet(queue<string>*, Point, char, Point);
    int getColorPair() override;
private:

};

#endif /* PLANET_H */

