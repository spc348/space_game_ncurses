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
    SpaceObject();
    SpaceObject(queue<string>*, Point, char, Point);
    virtual void draw() const;
    void log(string);
    void setBounds(Point);
    virtual int getColorPair();
protected:
    queue<string>* debug;
    Point loc;
    char identifier;
    Point bounds;
private:
};

#endif /* SPACEOBJECT_H */

