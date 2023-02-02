#ifndef GAME_H
#define GAME_H

#include "player.h"
#include "item.h"
#include "boundary.h"
#include "background.h"

enum game_state
{
    PLAY,
    PAUSE,
    QUIT
};

struct game
{
    struct player **players;
    struct item **items;
    struct boundary **boundaries;
    struct background *background;
    struct action **actions;
    struct effect **effects;
    enum game_state game_state;
};

struct game *create_game();
#endif /* !GAME_H */