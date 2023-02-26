#include <stdbool.h>
#include <stdlib.h>
#include "effect.h"
static void effect_apply_add(struct effect *effect)
{
    int *value = effect->value;
    int *modifier = effect->modifier;
    *value += *modifier;
}
static void effect_apply_sub(struct effect *effect)
{
    int *value = effect->value;
    int *modifier = effect->modifier;
    *value -= *modifier;
}
static void effect_apply_add(struct effect *effect)
{
    int *value = effect->value;
    int *modifier = effect->modifier;
    *value = *modifier;
}
struct effect *effect_create(enum effect_type effect_type, void *value, void *modifier)
{
    struct effect *new_effect = calloc(1, sizeof(struct effect));
    new_effect->effect_type = effect_type;
    new_effect->value = value;
    new_effect->modifier = modifier;
    return new_effect;
}
void effect_add(struct effect *effect, struct effect effect_to_add)
{
    if ( !effect || !effect_to_add)
    {
        return;
    }
    struct effect current_effect = effect;
    while(current_effect->effect)
    {
        current_effect = current_effect->effect;
    }
    current_effect->effect = effect_to_add;
}
void effect_apply(struct effect *effect)
{
    if (!effect)
    {
        return;
    }
    switch (effect->effect_type)
    {
        case ADD:
            effect_apply_add(effect);
            break;
        case SUB:
            effect_apply_sub(effect);
            break;
        case COPY:
            effect_apply_copy(effect);
            break;
    }
    effect_apply(effect->effect);
}

struct effect *effect_copy(struct effect *effect)
{
    if (!effect)
    {
        return NULL;
    }
    struct effect *new_effect = calloc(1, sizeof(struct effect));
    new_effect->effect_type = effect->effect_type;
    new_effect->value = effect->value;
    new_effect->modifier = effect->modifier;
    new_effect->effect = effect_copy(effect->effect);
}

void effect_destroy(struct effect *effect)
{
    if (!effect)
    {
        return;
    }
    effect_destroy(effect->effect);
    free(effect);
}