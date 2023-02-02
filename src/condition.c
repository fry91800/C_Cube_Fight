#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <SDL.h>
#include "player.h"
#include "condition.h"

//Basic function testing 2 int*
bool condition_test_equal(int *value, int *compared_to)
{
    return *value = *compared_to;
}
bool condition_test_lower(int *value, int *compared_to)
{
    return *value < *compared_to;
}
bool condition_test_lower_equal(int *value, int *compared_to)
{
    return *value <= *compared_to;
}
bool condition_test_greater(int *value, int *compared_to)
{
    return *value > *compared_to;
}
bool condition_test_greater_equal(int *value, int *compared_to)
{
    return *value >= *compared_to;
}

//Return a test ready to be made(struct condition) on 2 int* passed as argument
struct condition *condition_create(int *value, int *compared_to, enum condition_type condition_type)
{
    struct condition *new_condition = calloc(1, sizeof(struct condition));
    new_condition->value = value;
    new_condition->compared_to = compared_to;
    switch (condition_type)
    {
        case EQUAL:
            new_condition->condition_function = condition_test_equal;
            break;
        case LOWER:
            new_condition->condition_function = condition_test_lower;
            break;
        case LOWER_EQUAL:
            new_condition->condition_function = condition_test_lower_equal;
            break;
        case GREATER:
            new_condition->condition_function = condition_test_greater;
            break;
        case GREATER_EQUAL:
            new_condition->condition_function = condition_test_greater_equal;
            break;
        default:
            exit(0);
    }
}

bool condition_test(struct condition *condition)
{
    return condition->condition_function(condition->value, condition->compared_to);
}

bool fill_conditions(struct condition *condition)
{
    struct condition *current_condition = condition;
    while(current_condition)
    {
        //printf("value : %d, compared to : %d\n", *(condition->value), *(condition->compared_to));
        if ((condition_test(current_condition)) == false)
        {
            return false;
        }
        current_condition = current_condition->condition;
    }
    return true;
}