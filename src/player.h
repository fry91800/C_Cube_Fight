#ifndef PLAYER_H
#define PLAYER_H

#include <SDL.h>
#define WAR_HEALTH 2200
struct player
{
    int size;
    int x;
    int y;
    int next_x;
    int next_y;
    int speed;
    int jump_force;
    int jump_key;
    int left_key;
    int right_key;
    int jump_key_state;
    int left_key_state;
    int right_key_state;
    int health;
    SDL_Rect *skin;
    struct player *target;
};
struct player *create_player();
#endif /* PLAYER_H*/