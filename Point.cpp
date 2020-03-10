#include "Point.h"
#include <string>
using std::string;

Point::Point() : x{0}, y{0}
{
}

Point::Point(int y, int x) : y{y}, x{x}
{
}

int Point::getX() const {
    return this->x;
}

int Point::getY() const {
    return this->y;
}

void Point::setX(int x) {
    this->x = x;
}

void Point::setY(int y) {
    this->y = y;
}

string Point::pointString(){
    string s;
    s.append(std::to_string(this->y));
    s.append(" ");
    s.append(std::to_string(this->x));
    return s;
}