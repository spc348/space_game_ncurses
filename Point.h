#ifndef POINT_H
#define POINT_H
#include <string>
using std::string;
class Point {
public:
    Point();
    Point(int, int);
    int getX() const;
    int getY() const;
    void setX(int);
    void setY(int);
    string pointString();
private:
    int x;
    int y;

};

#endif /* POINT_H */

