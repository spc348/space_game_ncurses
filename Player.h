/*
 * Samuel Cahn 
 * Space Opera
 * 2020-0108 CIS 554 Object Oriented Programming
 * Final Project
 */

#ifndef PLAYER_H
#define PLAYER_H

#include "SpaceObject.h"
#include <queue>
#include <string>
#include <ncurses.h>
#include "Collider.h"

using std::string;
using std::queue;

class Player : public SpaceObject, public Collider {
public:
    // ctr
    Player(queue<string>*, Point, char, Point, int);
    // function to take in keyboard input
    void getInput(int);
    // update called for non-draw behavior, called every frame
    void update();
    // overrided draw call 
    void draw() const override;
    // override call to set color
    int getColorPair() override;
    // on collision call back
    void onCollision() override;
    // check if hit
    bool getGameOver();
private:
    // queue containing input from keyboard
    std::queue<int> keyPresses;
    // last set direction, stored as int
    int currentDir;
    // toggle game stop if hit
    bool gameOver;
};

#endif /* PLAYER_H */

