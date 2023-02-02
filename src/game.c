#include <stdlib.h>
#include "game.h"

struct game *create_game()
{
    struct game *res = calloc(1, sizeof(struct game));
    res->game_state = PLAY;
    return res;
}