#ifndef MAP_H_INCLUDED
#define MAP_H_INCLUDED

#define MAP_WIDTH 20
#define MAP_HEIGHT 8

typedef struct {
    char cells[MAP_HEIGHT][MAP_WIDTH];
} Map;

void map_init(Map *map);
char map_get(const Map *mqp, int x, int y);

#endif