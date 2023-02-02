#include "player.h"
#include <SDL.h>
#include "condition.h"

struct player *create_player()
{
    struct player *res = calloc(1, sizeof(struct player));
    res->size = 1;
    res->speed = 1;
    res->jump_force = 1;
    res->jump_key = SDL_SCANCODE_SPACE;
    res->left_key = SDL_SCANCODE_A;
    res->right_key = SDL_SCANCODE_E;
    res->jump_key_state = KEY_RELEASED;
    res->left_key_state = KEY_RELEASED;
    res->right_key_state = KEY_RELEASED;
    res->health = 2000;
    res->skin = calloc(1, sizeof(SDL_Rect));
    
    return res;
}