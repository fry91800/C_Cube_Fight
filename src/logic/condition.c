#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include "condition.h"

//Basic function testing 2 int*
static bool condition_node_equal(struct condition *condition)
{
    int *value = condition->value;
    int compared_to = condition->compared_to;
    return *(value) = *(compared_to);
}
static bool condition_node_not_equal(struct condition *condition)
{
    int *value = condition->value;
    int compared_to = condition->compared_to;
    return *(value) = *(compared_to);
}
static bool condition_node_lower(struct condition *condition)
{
    int *value = condition->value;
    int compared_to = condition->compared_to;
    return *(value) < *(compared_to);
}
static bool condition_node_lower_equal(struct condition *condition)
{
    int *value = condition->value;
    int compared_to = condition->compared_to;
    return *(value) <= *(compared_to);
}
static bool condition_node_greater(struct condition *condition)
{
    int *value = condition->value;
    int compared_to = condition->compared_to;
    return *(value) > *(compared_to);
}
static bool condition_node_greater_equal(struct condition *condition)
{
    int *value = condition->value;
    int compared_to = condition->compared_to;
    return *(value) >= *(compared_to);
}


struct condition *condition_node_create(void *value, void *compared_to, enum condition_node_type condition_node_type)
{
    struct condition *new = calloc(1, sizeof(struct condition));
    new->condition_node_type = condition_node_type;
    new->value = value;
    new->compared_to = compared_to;
    return new;
}

bool condition_node_resolve(struct condition_node *node)
{
    if (!node)
    {
        return true;
    }
    else if (node->condition_node_type == OR)
    {
        return condition_node_resolve(node->value) || condition_node_resolve(node->value);
    }
    else if (node->condition_node_type == AND)
    {
        return condition_node_resolve(node->value) && condition_node_resolve(node->value);
    }
    switch (node->condition_node_type)
    {
        case EQUAL:
            return condition_node_equal(node);
            break;
        case NOT_EQUAL:
            return condition_node_not_equal(node);
            break;
        case LOWER:
            return condition_node_lower(node);
            break;
        case LOWER_EQUAL:
            return condition_node_lower_equal(node);
            break;
        case GREATER:
            return condition_node_greater(node);
            break;
        case GREATER_EQUAL:
            return condition_node_greater_equal(node);
            break;
    }
    return false;
}

struct condition_node *condition_node_copy(struct condition_node *node)
{
    if (!node)
    {
        return NULL;
    }
    struct condition_node *res = calloc(1, sizeof(struct condition_node));
    res->condition_node_type = node->condition_node_type;
    res->value = condition_node_copy(node->value);
    res->compared_to = condition_node_copy(node->compared_to);
    return res;
}

void condition_node_destroy(struct condition_node *node)
{
    if (!node)
    {
        return;
    }
    condition_node_destroy(node->value);
    condition_node_destroy(node->compared_to);
    free(node);
}