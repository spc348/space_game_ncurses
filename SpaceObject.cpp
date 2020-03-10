#include "SpaceObject.h"

SpaceObject::SpaceObject() : loc(0, 0), identifier('?'), bounds(0, 0) {
}

SpaceObject::SpaceObject(queue<string>* debug, Point p, char id, Point bounds) : debug(debug), loc(p), identifier(id), bounds(bounds) {
}

void SpaceObject::draw() const {
    mvaddch(this->loc.getY(), this->loc.getX(), this->identifier);
}

void SpaceObject::log(string message) {
    debug->push(message);
}

void SpaceObject::setBounds(Point p) {
    this->bounds = p;
}

int SpaceObject::getColorPair() {
    return 1;
}