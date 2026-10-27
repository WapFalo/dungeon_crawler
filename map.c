#include "map.h"

static const char *LEVEL[MAP_HEIGHT] = {
    "####################",
    "#........#......#..#",
    "#........#......#..#",
    "#........#......#..#",
    "#.########.........#",
    "#.########.#########",
    "#..................#",
    "####################"
};

void mapInit(Map *map) {
    for (int y = 0; y < MAP_HEIGHT; y++) {
        for (int x = 0; x < MAP_WIDTH; x++) {
            map->cells[y][x] = LEVEL[y][x];
        }
    }
}

char mapGet (const Map *map, int x, int y){
    if (x < 0 || x >= MAP_WIDTH || y < 0 || y >= MAP_HEIGHT) {
        return '#'; // return wall character
    }
    return map->cells[y][x];
}