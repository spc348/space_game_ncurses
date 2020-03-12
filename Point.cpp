/*
 * Samuel Cahn 
 * Space Opera
 * 2020-0108 CIS 554 Object Oriented Programming
 * Final Project
 */

#include "Point.h"
#include <string>
using std::string;

// ctr
Point::Point() : x{0}, y{0}
{
}

//ctr
Point::Point(int y, int x) : x{x}, y{y}
{
}

// x getter
int Point::getX() const {
    return this->x;
}

// y getter
int Point::getY() const {
    return this->y;
}

// x setter
void Point::setX(int x) {
    this->x = x;
}

// y setter
void Point::setY(int y) {
    this->y = y;
}

// to string function for debugging
string Point::pointString() {
    string s;
    s.append(std::to_string(this->y));
    s.append(" ");
    s.append(std::to_string(this->x));
    return s;
}