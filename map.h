#ifndef MAP_H_INCLUDED
#define MAP_H_INCLUDED

#define MAP_WIDTH 20
#define MAP_HEIGHT 8

typedef struct {
    char cells[MAP_HEIGHT][MAP_WIDTH];
} Map;

void mapInit(Map *map);
char mapGet(const Map *map, int x, int y);

#endif