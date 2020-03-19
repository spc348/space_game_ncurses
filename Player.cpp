/*
 * Samuel Cahn 
 * Space Opera
 * 2020-0108 CIS 554 Object Oriented Programming
 * Final Project
 */

#include "Player.h"

// ctr

Player::Player(queue<string>* debug, Point p, char id, Point bounds, int bubble)
: SpaceObject(debug, p, id, bounds), currentDir(0), Collider(&loc, bubble, debug), gameOver(false) {
}

void Player::getInput(int i) {
    // push keyboard input onto the queue
    keyPresses.push(i);
}

void Player::update() {
    // move player if keyboard input stored
    if (!keyPresses.empty()) {
        int next = keyPresses.front();
        switch (next) {
            case 68:
            case KEY_LEFT:
                currentDir = 0;
                next = loc.getX();
                if (next - 1 < 0) {
                    loc.setX(bounds.getX() - 1);
                } else {
                    loc.setX(--next);
                }
                break;
            case 67:
            case KEY_RIGHT:
                currentDir = 1;
                next = loc.getX();
                if (next + 1 > bounds.getX()) {
                    loc.setX(1);
                } else {
                    loc.setX(++next);
                }
                break;
            case 65:
            case KEY_UP:
                currentDir = 2;
                next = loc.getY();
                if (next - 1 < 0) {
                    loc.setY(bounds.getY() - 1);
                } else {
                    loc.setY(--next);
                }
                break;
            case 66:
            case KEY_DOWN:
                currentDir = 3;
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
    }// update player location to cause the ship to float
    // create movement between key presses
    else {
        switch (this->currentDir) {
            case 0:
            {
                int next = loc.getX();
                if (next - 1 < 0) {
                    loc.setX(bounds.getX() - 1);
                } else {
                    loc.setX(--next);
                }
            }
                break;
            case 1:
            {
                int next = loc.getX();
                if (next + 1 > bounds.getX()) {
                    loc.setX(1);
                } else {
                    loc.setX(++next);
                }
            }
                break;
            case 2:
            {
                int next = loc.getY();
                if (next - 1 < 0) {
                    loc.setY(bounds.getY() - 1);
                } else {
                    loc.setY(--next);
                }
            }
                break;
            case 3:
            {
                int next = loc.getY();
                if (next > bounds.getY()) {
                    loc.setY(1);
                } else {
                    loc.setY(++next);
                }
            }
                break;
            default:
                break;
        }
    }
}

void Player::draw() const {
    // draw the icon at new location
    mvaddch(this->loc.getY(), this->loc.getX(), this->identifier);
}

int Player::getColorPair() {
    // yellow on black
    return 2;
}
// collision call back

void Player::onCollision() {
    this->gameOver = true;
}

// check if player hit

bool Player::getGameOver() {
    return this->gameOver;
}