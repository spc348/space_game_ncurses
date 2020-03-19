/*
 * Samuel Cahn 
 * Space Opera
 * 2020-0108 CIS 554 Object Oriented Programming
 * Final Project
 */

#ifndef COLLIDER_H
#define COLLIDER_H

#include "Point.h"
#include <math.h>
#include <queue>
#include <string>
using std::queue;
using std::string;
using std::abs;

class Collider {
public:
    // ctr
    Collider(Point*, int, queue<string>*);
    // collision detection
    bool collide(Collider*);
    // set size of collision area
    void setBubble(int);
    // get size of collision
    int getBubble();
    // currently colliding
    bool isColliding();
    // on collision call back
    virtual void onCollision() = 0;
private:
    // Reference to object location
    Point* colliderLocation;
    // size around location of collision
    int bubble;
    // flag to track if in collision
    bool colliding;
    // reference to debug log
    queue<string>* colliderLog;
};

#endif /* COLLIDER_H */

