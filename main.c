#include <ncurses.h>
#include "map.h"

typedef struct {
    int running;    // 1 if the game is running, 0 if not
    int turn;       // Current turn number
    int lastKey;    // pour l'afficher et vérifier que ça marche
} Game;

void initScreen (void) {
    initscr();
    cbreak();
    noecho();
    keypad(stdscr, TRUE);
    curs_set(0);
}

int handleInput (void) {
    return getch();
}

void update (Game *game, int key) {
    if (key == 'q') game->running = 0;
    game->lastKey = key;
    game->turn++;
}

void render (const Game *game) {
    clear();
    mvprintw(0, 0, "Turn: %d", game->turn);
    mvprintw(1, 0, "Last Key: %d", game->lastKey);
    mvprintw(2, 0, "Press 'q' to quit");
    refresh();
}

static void renderMap (const Map *map) {
    for (int y = 0; y < MAP_HEIGHT; y++){
        for (int x = 0; x < MAP_WIDTH; x++){
            mvaddch(y, x, mapGet(map, x, y));
        }
    }
}

int main (void){
    Map map;
    mapInit(&map);

    initScreen();
    cbreak();
    noecho();
    curs_set(0);

    int key = 0;
    while (key != 'q') {
        erase();
        renderMap(&map);
        mvprintw(MAP_HEIGHT + 1, 0, "Press 'q' to quit");
        refresh();
        key = getch();
    }
    endwin();

    return 0;
}