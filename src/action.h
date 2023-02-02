#ifndef ACTION_H
#define ACTION_H

struct action
{
    struct condition *start_condition;
    struct effect *effect;
};

bool fill_conditions(struct condition *condition);

#endif /* !ACTION_H */