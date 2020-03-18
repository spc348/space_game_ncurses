/*
 * Samuel Cahn 
 * Space Opera
 * 2020-0108 CIS 554 Object Oriented Programming
 * Final Project
 */

#ifndef SPACEOBJECT_H
#define SPACEOBJECT_H

#include "Point.h"
#include <ncurses.h>
#include <queue>
#include <string>

using std::string;
using std::queue;

class SpaceObject {
public:
    // ctr
    SpaceObject();
    // ctr
    SpaceObject(queue<string>*, Point, char, Point);
    virtual ~SpaceObject(){}
    // draw the icon
    virtual void draw() const;
    // send message to debug log
    void log(string);
    // set the bounds for derived classes to do bounds check
    void setBounds(Point);
    // virtual method to allow derived classes to change their color
    virtual int getColorPair();
    // return location for collision
    Point* getLoc();
    // Allow change of color;
    void setColorPair(int);
protected:
    // queue of debug messages
    queue<string>* debug;
    // location of the icon in the terminal
    Point loc;
    // icon for object
    char identifier;
    // bounds in type Point
    Point bounds;
    // color variable 
    int colorPair;
};

#endif /* SPACEOBJECT_H */

