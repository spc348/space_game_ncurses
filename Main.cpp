/*
 * Samuel Cahn 
 * Space Opera
 * 2020-0108 CIS 554 Object Oriented Programming
 * Final Project
 */

#include <iostream>
#include <ncurses.h>
#include <unistd.h>
#include <string>
#include <queue>
#include "SpaceObject.h"
#include "Player.h"
#include "Planet.h"
#include "Star.h"
#include <vector>
#include <cstdlib>

using namespace std;

int main() {

    // seed random
    srand(time(0));

    // debug log
    queue<string> debugLog;
    // drawable objects
    vector<SpaceObject*> sos;

    // ncurses setup screen
    initscr();
    // hide keyboard input
    noecho();
    // hide cursor
    curs_set(FALSE);
    // unknown boilerplate
    cbreak();
    // how long to wait for keyboard input, causes thread to pause, ie 
    // terminal will not render until timeout has elapsed.
    // Negative values waits indefinitely for input
    timeout(300);
    // unknown boilerplate
    keypad(stdscr, TRUE);

    // x and y variables to store bounds extents
    int max_x{0};
    int max_y{0};
    // funtion to get bounds of terminal screen
    getmaxyx(stdscr, max_y, max_x);
    // convert bounds to a point
    Point bounds{max_y, max_x};

    // color boilerplate
    start_color();
    // base
    init_pair(1, COLOR_WHITE, COLOR_BLACK);
    // player
    init_pair(2, COLOR_YELLOW, COLOR_BLACK);
    // planet 
    init_pair(3, COLOR_BLUE, COLOR_BLACK);
    // alt planet
    init_pair(4, COLOR_GREEN, COLOR_BLACK);

    // Player
    // -- spawn point
    Point spawn(4, 4);
    // -- object
    Player test(&debugLog, spawn, '^', bounds);
    // add to spaceobject list
    sos.push_back(&test);

    // Planet
    // -- create random number of planets
    int numPlanets{0};
    numPlanets = (rand() % 15) + 5;
    // -- iterate through num
    for (int i = 0; i < numPlanets; i++) {
        // -- randomize location
        Point bluePlanetSpawn(rand() % max_y - 1, rand() % max_x - 1);
        // -- create as pointer
        Planet* bluePlanet = new Planet(&debugLog, bluePlanetSpawn, '@', bounds);
        // add to space obejct list
        sos.push_back(bluePlanet);
    }

    // Stars
    // -- create random number of stars
    int numStars{0};
    numStars = (rand() % 50) + 25;
    // -- iterate over all stars
    for (int i = 0; i < numStars; i++) {
        // -- randomize locations
        Point starSpawn(rand() % max_y - 1, rand() % max_x - 1);
        // -- sprite array for animations
        const char* sprite = ".,";
        // -- star object
        Star* star = new Star(&debugLog, starSpawn, sprite, bounds, 2);
        // add to space object list
        sos.push_back(star);
    }

    /// <---  game loop start ---> ///
    while (1) {
        // check if screen resized
        getmaxyx(stdscr, max_y, max_x);
        // ncurses boiler plate
        clear();
        refresh();

        // iterate over all space objects
        for (vector<SpaceObject*>::iterator it = sos.begin(); it != sos.end(); it++) {
            // cast as player to try and update
            Player* player = dynamic_cast<Player*> (*it);
            if (player) {
                player->update();
            }
            // cast as star to try and update animation
            Star* starMorph = dynamic_cast<Star*> (*it);
            if (starMorph) {
                starMorph->update();
            }
            // set next object to be drawn's color pair
            attron(COLOR_PAIR((*it)->getColorPair()));
            // draw the icon
            (*it)->draw();
            // disable objects color pair
            attroff(COLOR_PAIR((*it)->getColorPair()));
        }
        
        // draw debug log for information
        if (!debugLog.empty()) {
            mvprintw(max_y - 2, 0, debugLog.front().c_str());
        }

        // check for user input
        int input = getch();
        if (input != ERR) {
            test.getInput(input);
        }
    } // end while

    endwin();
}