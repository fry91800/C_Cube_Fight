#ifndef CONDITION_H
#define CONDITION_H

#include <stdbool.h>

//Struct condition record a test to be made on 2 int pointers
enum condition_node_type
{
    AND,
    OR,
    EQUAL,
    NOT_EQUAL,
    LOWER,
    LOWER_EQUAL,
    GREATER,
    GREATER_EQUAL
};

struct condition_node
{
    enum condition_node_type condition_node_type;
    void *value;
    void *compared_to;
};

struct condition *condition_node_create(void *value, void *compared_to, enum condition_node_type condition_node_type)
bool condition_node_resolve(struct condition_node *node);
struct condition_node *condition_node_copy(struct condition_node *node);
void condition_node_destroy(struct condition_node *node);

#endif /* !CONDITION_H */
