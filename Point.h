/*
 * Samuel Cahn 
 * Space Opera
 * 2020-0108 CIS 554 Object Oriented Programming
 * Final Project
 */

#ifndef POINT_H
#define POINT_H

#include <string>

using std::string;

class Point {
public:
    // ctr
    Point();
    //ctr
    Point(int, int);
    // x getter
    int getX() const;
    // y getter
    int getY() const;
    // x setter
    void setX(int);
    // y setter
    void setY(int);
    // function for debugging
    string pointString();
private:
    // x coordinate
    int x;
    // y coordinate
    int y;

};

#endif /* POINT_H */

