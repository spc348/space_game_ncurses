/*
 * Samuel Cahn 
 * Space Opera
 * 2020-0108 CIS 554 Object Oriented Programming
 * Final Project
 */

#include "SpaceObject.h"

// ctr

SpaceObject::SpaceObject() : loc(0, 0), identifier('?'), bounds(0, 0), colorPair{1} {
}

// ctr

SpaceObject::SpaceObject(queue<string>* debug, Point p, char id, Point bounds) 
: debug(debug), loc(p), identifier(id), bounds(bounds), colorPair(1) {
}

// draw icon at location

void SpaceObject::draw() const {
    mvaddch(this->loc.getY(), this->loc.getX(), this->identifier);
}

// debug log 

void SpaceObject::log(string message) {
    debug->push(message);
}

// bounds setter

void SpaceObject::setBounds(Point p) {
    this->bounds = p;
}

int SpaceObject::getColorPair() {
    // white on black
    return 1;
}

Point* SpaceObject::getLoc(){
    return &this->loc;
}

void SpaceObject::setColorPair(int color){
    this->colorPair = color;
}