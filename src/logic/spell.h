#ifndef SPELL_H
#define SPELL_H

#include <stdbool.h>
#include "../player.h"
#include "effect.h"
#include "condition.h"
#include "action.h"

struct spell
{
    struct player *caster;
    struct player *target;
    struct action **actions;
    int timer;
    struct effect *effect;
    struct condition *end_condition;
};

struct spell_list
{
    struct spell *spell;
    struct spell_list *spell_list;
}


#endif /* !SPELL_H */
