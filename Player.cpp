#include "Player.h"

Player::Player(queue<string>* debug, Point p, char id, Point bounds) : SpaceObject(debug, p, id, bounds) {
}

void Player::getInput(int i) {
    keyPresses.push(i);
}

void Player::update() {
    if (!keyPresses.empty()) {
        int next = keyPresses.front();
        switch (next) {
            case 68:
            case KEY_LEFT:
                next = loc.getX();
                if (next - 1 < 0) {
                    loc.setX(bounds.getX() - 1);
                } else {
                    loc.setX(--next);
                }
                break;
            case 67:
            case KEY_RIGHT:
                next = loc.getX();
                if (next + 1 > bounds.getX()) {
                    loc.setX(1);
                } else {
                    loc.setX(++next);
                }
                log(string("right"));
                break;
            case 65:
            case KEY_UP:
                next = loc.getY();
                if (next - 1 < 0) {
                    loc.setY(bounds.getY() - 1);
                } else {
                    loc.setY(--next);
                }
                break;
            case 66:
            case KEY_DOWN:
                next = loc.getY();
                if (next > bounds.getY()) {
                    loc.setY(1);
                } else {
                    loc.setY(++next);
                }
                break;
            default:
                mvprintw(15 - 1, 0, std::to_string(next).c_str());
        }
        keyPresses.pop();
    }
}

void Player::draw() const {
    mvaddch(this->loc.getY(), this->loc.getX(), this->identifier);
}

int Player::getColorPair() {
    return 2;
}
