#include <stdio.h>
#include <stdbool.h>
#include "action.h"
#include "condition.h"
#include "spell.h"

bool action_fills_condition(struct action *action)
{
    return condition_node_resolve(action->start_condition);
}

struct action *action_create(struct condition *start_condition, struct spell *spell)
{
    struct action *new_action = calloc(1, sizeof(struct action));
    new_action->start_condition = start_condition;
    new_action->spell = spell;
    return new_action;
}

struct action *action_copy(struct action *action)
{
    struct action *new_action = calloc(1, sizeof(struct action));
    new_action->start_condition = action->start_condition;
    new_action->spell = action->spell;
    return new_action;
}

void action_destroy(struct action *action)
{
    free(action);
}