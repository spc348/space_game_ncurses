/*
 * Samuel Cahn 
 * Space Opera
 * 2020-0108 CIS 554 Object Oriented Programming
 * Final Project
 */

#ifndef STAR_H
#define STAR_H

#include "SpaceObject.h"
#include <string>

class Star : public SpaceObject{
    
public:
    // ctr
    Star(queue<string>*, Point, const char*, Point, int);
    // overrided funciton to set color
    int getColorPair() override;
    // overrided function to draw icons
    void draw() const override;
    // non-draw related function called each frame
    void update();
private:
    // string of characters to use as animation
    const char* sprite;
    // index into animation array
    int spriteIndex;
    // limit of array
    int spriteMax;
};

#endif /* STAR_H */

