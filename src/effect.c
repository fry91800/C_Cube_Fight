#include <stdbool.h>
#include <stdlib.h>
#include <SDL.h>
#include "player.h"
#include "effect.h"
struct effect *create_movex_effect(struct player *player, int displacement)
{
    struct effect *res = malloc(sizeof(struct effect));
    res->player = player;
    res->info = displacement;
    res->effect_type = MOVEX;
    res->effect_function = apply_effect;
    res->effect = NULL;

    return res;
}

void apply_movex_effect(struct player *player, int displacement)
{
    player->next_x = player->x + displacement;
}
struct effect *create_effect(struct player *player, int info, enum effect_type effect_type)
{
    if (effect_type == MOVEX)
    {
        return create_movex_effect(player, info);
    }
    return NULL;
}
void apply_effect(struct player *player, int info, enum effect_type effect_type)
{
    if (effect_type == MOVEX)
    {
        apply_movex_effect(player, info);
    }
}