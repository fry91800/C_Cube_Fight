#ifndef ACTION_H
#define ACTION_H

#include "spell.h"
struct action
{
    struct condition *start_condition;
    struct spell *spell;
};

bool action_fills_condition(struct action *action);
struct action *action_create(struct condition *start_condition, struct spell *spell);
struct action *action_copy(struct action *action);
void action_destroy(struct action *action);

#endif /* !ACTION_H */