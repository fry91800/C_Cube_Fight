#include "stdio.h"
#include <stdbool.h>
#include "action.h"
#include "condition.h"
#include "effect.h"

bool fill_conditions(struct condition *condition)
{
    struct condition *current_condition = condition;
    while(current_condition)
    {
        if (test_condition(current_condition->player, current_condition->info, current_condition->condition_type) == false)
        {
            printf("condition evaluer a false c la merde\n");
            return false;
        }
        current_condition = current_condition->condition;
    }
    return true;
}

void add_effect(struct action **actions, struct effect **effect)
{
    ;
}