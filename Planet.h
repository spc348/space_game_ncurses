/*
 * Samuel Cahn 
 * Space Opera
 * 2020-0108 CIS 554 Object Oriented Programming
 * Final Project
 */

#ifndef PLANET_H
#define PLANET_H

#include "SpaceObject.h"
#include <ncurses.h>

class Planet : public SpaceObject{
public:
    // ctr
    Planet(queue<string>*, Point, char, Point);
    // overriding the color for the icon
    int getColorPair() override;
private:

};

#endif /* PLANET_H */

