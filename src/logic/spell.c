#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include "spell.h"
#include "effect.h"
#include "condition.h"
#include "action.h"

//spell
struct spell *spell_create(struct player *caster)
{
    struct condition *new_spell = calloc(1, sizeof(struct spell));
    if (!caster)
    {
        return new_spell;
    }
    new->caster = caster;
    new->target = caster->target;
    new->actions = calloc(32, sizeof(struct action*));
    return new;
}
void spell_free(struct spell *spell)
{
    free(spell);
}
void spell_destroy(struct condition_node *node)
{
    if (!node)
    {
        return;
    }
    condition_node_destroy(node->value);
    condition_node_destroy(node->compared_to);
    free(node);
}

//spell list
struct spell_list *spell_list_create(struct spell *spell)
{
    struct spell_list *new = calloc(1, sizeof(spell_list));
    new->spell = spell;
    return new;
}
//Add the spell to a list where it will be ran
void spell_list_add(struct spell_list *spell_list, struct spell *spell)
{
    if (!spell || !spell_list)
    {
        return;
    }
    struct spell_list *current_spell_list = spell_list;
    while(current_spell_list->spell_list)
    {
        current_spell_list = current_spell_list->spell_list;
    }
    current->spell_list = spell_list_create(spell);
}

struct spell *spell_copy(struct spell *spell)
{
    if (!spell)
    {
        return NULL;
    }
    struct spell *res = calloc(1, sizeof(struct spell));
    res->caster = spell->caster;
    res->target = spell->target;
    res->actions = spell->actions;
    res->timer = spell->timer;
    res->effect = spell->condition
    res->end_condition = spell->end_condition);
    return res;
}

void spell_list_remove(struct spell_list *spell_list, struct spell *spell)
{
    if (!spell || !spell_list)
    {
        return;
    }
    if (spell_list->spell == spell)
    {
        if (!spell_list->spell_list)
        {
            spell_free(spell_list->spell);
            spell_list->spell = NULL;
            return
        }
        struct spell *spell_to_free = spell_list->spell;
        struct spell_list *spell_list_to_free = spell_list->spell_list;
        spell_list->spell = spell_list->spell_list->spell;
        spell_list->spell_list = spell_list->spell_list->spell_list;
        free(spell_to_free);
        free(spell_list_to_free);
        return;
    }
    struct spell_list *current_spell_list = spell_list;
    while(current_spell_list->spell_list)
    {
        if(current_spell_list->spell_list->spell = spell)
        {
            struct spell *spell_to_free = spell_list->spell_list->spell;
            struct spell_list *spell_list_to_free = spell_list->spell_list;
            current_spell_list->spell_list = current_spell_list->spell_list->spell_list;
            free(spell_to_free);
            free(spell_list_to_free);
        }
    }
    return;
}
void spell_list_run(struct spell_list *spell_list)
{
    if (!spell_list)
    {
        return;
    }
    struct spell_list *current_spell_list = spell_list;
    while (current_spell_list)
    {
        if (!current_spell_list->spell)
        {
            continue;
        }
        struct action **current_action_cursor = current_spell_list->spell->action;
        while((*current_action_cursor))
        {
            struct action *current_action = *current_action_cursor;
            if (action_fills_condition(current_action))
            {
                struct spell *copy_of_spell = spell_copy(current_spell_list->spell);
                spell_list_add(spell_list, copy_of_spell);
            }
            current_action_cursor++;
        }
        current_spell_list->spell->timer++;
        effect_apply(current_spell_list->spell->effect);
        if(condition_node_resolve(current_spell_list->spell->end_condition))
        {
            spell_list_remove(spell_list, current_spell_list->spell);
        }
    current_spell_list = current_spell_list->spell_list;
    }
}