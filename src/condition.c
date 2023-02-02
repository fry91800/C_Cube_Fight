#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <SDL.h>
#include "player.h"
#include "condition.h"
struct condition *create_health_min_condition(struct player *player, int health)
{
    struct condition *res = malloc(sizeof(struct condition));
    res->player = player;
    res->info = health;
    res->condition_type = HEALTH_MIN;
    res->condition_function = test_condition;
    res->condition = NULL;

    return res;
}
struct condition *create_right_key_condition(struct player *player, int key_state)
{
    struct condition *res = malloc(sizeof(struct condition));
    res->player = player;
    res->info = key_state;
    res->condition_type = KEY_PRESSED;
    res->condition_function = test_condition;
    res->condition = NULL;

    return res;
}
bool test_right_key(struct player *player, int info)
{
    if (info == KEY_PRESSED)
    {
        printf("test right key bien aiguille\n");
        return player->right_key_state == KEY_PRESSED || player->right_key_state == KEY_JUST_PRESSED;
    }
    printf("test right key mal aiguille\n");
    return false;
}
bool test_health_min_condition(struct player *player, int health)
{
    return player->health >= health;
}
struct condition *create_condition(struct player *player, int info, enum condition_type condition_type)
{
    if (condition_type == HEALTH_MIN)
    {
        return create_health_min_condition(player, info);
    }
    else if (condition_type == RIGHT_KEY_PRESSED)
    {
        return create_right_key_condition(player, info);
    }
    return NULL;
}
bool test_condition(struct player *player, int info, enum condition_type condition_type)
{
    if (condition_type == HEALTH_MIN)
    {
        return test_health_min_condition(player, info);
    }
    else if (condition_type == RIGHT_KEY_PRESSED)
    {
        return test_right_key(player, KEY_PRESSED);
    }
    return false;
}