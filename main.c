#include <ncurses.h>

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

int handleInput(void) {
    return getch();
}

void update(Game *game, int key) {
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

int main(void){
    Game game = { .running = 1 };
    initScreen();
    render(&game);
    while (game.running) {
        int key = handleInput();
        update(&game, key);
        render(&game);
    }
    endwin();

    return 0;
}