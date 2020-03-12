/*
 * Samuel Cahn 
 * Space Opera
 * 2020-0108 CIS 554 Object Oriented Programming
 * Final Project
 */

#include "Planet.h"

// ctr
Planet::Planet(queue<string>* log, Point loc, char id, Point bounds) : SpaceObject(log, loc, id, bounds) {
}

int Planet::getColorPair() {
    // blue on black
    return 3;
}