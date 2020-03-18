/*
 * Samuel Cahn 
 * Space Opera
 * 2020-0108 CIS 554 Object Oriented Programming
 * Final Project
 */

#ifndef ASTEROID_H
#define ASTEROID_H

#include "SpaceObject.h"
#include "Collider.h"
#include <cstdlib>
#include <unistd.h>

class Asteroid : public SpaceObject, public Collider {
public:
    Asteroid(queue<string>*, Point, char, Point, int, int);
    void update();
    void onCollision() override;
private:
    int currentDir;
};

#endif /* ASTEROID_H */

