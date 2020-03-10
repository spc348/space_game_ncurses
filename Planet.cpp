#include "Planet.h"

Planet::Planet(queue<string>* log, Point loc, char id, Point bounds) : SpaceObject(log, loc, id, bounds) {
}

int Planet::getColorPair() {
    return 3;
}