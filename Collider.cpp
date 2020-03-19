/*
 * Samuel Cahn 
 * Space Opera
 * 2020-0108 CIS 554 Object Oriented Programming
 * Final Project
 */

#include "Collider.h"

// ctr
Collider::Collider(Point* point, int b, queue<string>* log)
: colliderLocation{point}, bubble{b}, colliderLog{log}
{

}

// check for collision

bool Collider::collide(Collider* other) {
    int xDiff = other->colliderLocation->getX() - this->colliderLocation->getX();
    bool withinX = (xDiff <= this->bubble && xDiff > 0) ||
            (0 - this->bubble <= xDiff && xDiff <= 0);
    int yDiff = other->colliderLocation->getY() - this->colliderLocation->getY();
    bool withinY = (yDiff <= this->bubble && yDiff > 0) ||
            (0 - this->bubble <= yDiff && yDiff <= 0);
//    debugging
//    colliderLog->push(std::to_string(other->colliderLocation->getX())
//            + " " + std::to_string(this->colliderLocation->getX())
//            + " , " + std::to_string(other->colliderLocation->getY())
//            + " " + std::to_string(this->colliderLocation->getY()));
    
    this->colliding = withinX && withinY;
    // callback
    if (this->colliding) {
        // specific to derived class
        onCollision();
    }
    return this->colliding;
}

// set size of collision area

void Collider::setBubble(int size) {

    this->bubble = size;
}

// get size of collision

int Collider::getBubble() {

    return this->bubble;
}

// alert drawing function that collision occurring

bool Collider::isColliding() {

    return this->colliding;
}