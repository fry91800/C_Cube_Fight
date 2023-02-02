#ifndef EFFECT_H
#define EFFECT_H
enum effect_type
{
    MOVEX,
    MOVEY,
    DAMAGE
};

struct effect
{
    struct player* player;
    int info;
    enum effect_type effect_type;
	void (*effect_function)(struct player *, int, enum effect_type);
    struct condition *end_condition;
	struct effect *effect;
};

struct effect *create_movex_effect(struct player *player, int displacement);
void apply_movex_effect(struct player *player, int displacement);
struct effect *create_effect(struct player *player, int info, enum effect_type effect_type);
void apply_effect(struct player *player, int info, enum effect_type effect_type);
#endif /* !EFFECT_H */