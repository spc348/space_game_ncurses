#include <iostream>
#include <ncurses.h>
#include <unistd.h>
#include <string>
#include <queue>
#include "SpaceObject.h"
#include "Player.h"
#include "Planet.h"
#include <vector>
#include <cstdlib>

using namespace std;

int main() {
    
    srand(time(0));
    
    // debug log
    queue<string> debugLog;
    // drawable objects
    vector<SpaceObject*> sos;

    initscr();
    noecho();
    curs_set(FALSE);
    cbreak();

    keypad(stdscr, TRUE);

    int max_x{0};
    int max_y{0};
    getmaxyx(stdscr, max_y, max_x);
    Point bounds{max_y, max_x};
    Point spawn(4, 4);

    start_color();
    Player test(&debugLog, spawn, '^', bounds);
    
    Point bluePlanetSpawn(rand() % max_y -1, rand() % max_x -1); 
    Planet bluePlanet(&debugLog, bluePlanetSpawn, '@', bounds);
    
    // base
    init_pair(1, COLOR_WHITE, COLOR_BLACK);
    // player
    init_pair(2, COLOR_YELLOW, COLOR_BLACK);
    // planet 
    init_pair(3, COLOR_BLUE, COLOR_BLACK);

    sos.push_back(&test);
    sos.push_back(&bluePlanet);

    /// <---  game loop start ---> ///
    while (1) {
        getmaxyx(stdscr, max_y, max_x);
        clear();
        
        // player update
        test.update();
        
        for (vector<SpaceObject*>::iterator it = sos.begin(); it != sos.end(); it++) {
            attron(COLOR_PAIR((*it)->getColorPair()));
            (*it)->draw();
            attroff(COLOR_PAIR((*it)->getColorPair()));
        }
        refresh();
        usleep(3000);
        if (!debugLog.empty()) {
            mvprintw(max_y - 2, 0, debugLog.front().c_str());
        }
        int input = getch();
        if (input > 0) {
            test.getInput(input);
        }
    }

    endwin();
}