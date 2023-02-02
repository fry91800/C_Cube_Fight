#ifndef ACTION_H
#define ACTION_H

struct action
{
    struct condition *start_condition;
    struct effect *effect;
};

#endif /* !ACTION_H */