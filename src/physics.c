#include "player.h"
#include "boundary.h"
#include "item.h"
void apply_physics(struct player **players, struct item **items, struct boundary **boundaries)
{
    struct player **player_cursor = players;
    struct item **item_cursor = items;
    struct boundary **boundary_cursor = boundaries;
    while(*player_cursor)
    {
        (*player_cursor)->x = (*player_cursor)->next_x;
        (*player_cursor)->y = (*player_cursor)->next_y;
        player_cursor++;
    }
}