#ifndef CONDITION_H
#define CONDITION_H

#include <stdbool.h>
enum key_state
{
    KEY_RELEASED,
    KEY_JUST_RELEASED,
    KEY_PRESSED,
    KEY_JUST_PRESSED,
};
enum condition_type
{
    RIGHT_KEY_RELEASED,
    RIGHT_KEY_JUST_RELEASED,
    RIGHT_KEY_PRESSED,
    RIGHT_KEY_JUST_PRESSED,
    DISTANCE_MIN,
    DISTANCE_MAX,
    FLOOR,
    CD,
    HEALTH_MIN,
    HEALTH_MAX
};

struct condition
{
    struct player* player;
    int info;
    enum condition_type condition_type;
	bool (*condition_function)(struct player *, int, enum condition_type);
	struct condition *condition;
};

struct condition *create_health_min_condition(struct player *player, int health);
bool test_health_min_condition(struct player *player, int health);
struct condition *create_condition(struct player *player, int info, enum condition_type condition_type);
bool test_condition(struct player *player, int info, enum condition_type condition_type);

#endif /* !CONDITION_H */
