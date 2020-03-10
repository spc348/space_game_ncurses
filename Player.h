#ifndef PLAYER_H
#define PLAYER_H

#include "SpaceObject.h"
#include <queue>
#include <string>
#include <ncurses.h>

using std::string;
using std::queue;

class Player : public SpaceObject {
public:
    Player(queue<string>*, Point, char, Point);
    void getInput(int);
    void update();
    void draw() const override;
    int getColorPair() override;
private:
    std::queue<int> keyPresses;
};

#endif /* PLAYER_H */

