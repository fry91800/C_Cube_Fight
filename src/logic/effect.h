#ifndef EFFECT_H
#define EFFECT_H
enum effect_type
{
    ADD,
    SUB,
    COPY
};

struct effect
{
    enum effect_type effect_type;
    void *value;
    void *modifier;
    struct effect *effect;
};

struct effect *effect_create(enum effect_type effect_type, void *value, void *modifier);
void effect_apply(struct effect *effect);
struct effect *effect_copy(struct effect *effect);
void effect_destroy(struct effect *effect);
#endif /* !EFFECT_H */