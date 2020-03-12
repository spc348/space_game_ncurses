/*
 * Samuel Cahn 
 * Space Opera
 * 2020-0108 CIS 554 Object Oriented Programming
 * Final Project
 */

#include "Star.h"

// ctr
Star::Star(queue<string>* log, Point loc, const char* id, Point bounds, int sprites)
: SpaceObject(log, loc, id[0], bounds), sprite(id), spriteIndex{0}, spriteMax{sprites}
{
}

int Star::getColorPair() {
    // (white on black)
    return 1;
}

void Star::draw() const {
    // draw icon at index of sprite array
    mvaddch(this->loc.getY(), this->loc.getX(), this->sprite[spriteIndex]);
}

void Star::update() {
    // iterate through the array
    if (this->spriteIndex + 1 < spriteMax) {
        this->spriteIndex++;
    } else {
        this->spriteIndex = 0;
    }
}