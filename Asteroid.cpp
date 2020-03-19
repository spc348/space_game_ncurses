/*
 * Samuel Cahn 
 * Space Opera
 * 2020-0108 CIS 554 Object Oriented Programming
 * Final Project
 */

#include "Asteroid.h"

// ctr

Asteroid::Asteroid(queue<string>* log, Point location, char c, Point bounds, int b, int dir)
: SpaceObject(log, location, c, bounds), Collider(&loc, b, log), currentDir(dir) {
}

// function called each frame
void Asteroid::update() {
    switch (this->currentDir) {
        case 0:
        {
            int next = loc.getX();
            if (next - 1 < 0) {
                loc.setX(bounds.getX() - 1);
            } else {
                loc.setX(--next);
            }
        }
            break;
        case 1:
        {
            int next = loc.getX();
            if (next + 1 > bounds.getX()) {
                loc.setX(1);
            } else {
                loc.setX(++next);
            }
        }
            break;
        case 2:
        {
            int next = loc.getY();
            if (next - 1 < 0) {
                loc.setY(bounds.getY() - 1);
            } else {
                loc.setY(--next);
            }
        }
            break;
        case 3:
        {
            int next = loc.getY();
            if (next > bounds.getY()) {
                loc.setY(1);
            } else {
                loc.setY(++next);
            }
        }
            break;
        default:
            break;
    }
}

// call back on collision
// should occur when hitting other asteroids
void Asteroid::onCollision() {
    // seed random
    srand(time(0));
    this->currentDir = rand() % 4;
}



