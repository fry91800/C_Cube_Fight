#ifndef CONDITION_H
#define CONDITION_H

#include <stdbool.h>

//Struct condition record a test to be made on 2 int pointers
enum key_state
{
    KEY_RELEASED,
    KEY_JUST_RELEASED,
    KEY_JUST_PRESSED,
    KEY_PRESSED,
};
enum condition_type
{
    EQUAL,
    LOWER,
    LOWER_EQUAL,
    GREATER,
    GREATER_EQUAL
};

struct condition
{
    int *value;
    int *compared_to;
	bool (*condition_function)(int*, int*);
	struct condition *condition;
};

bool condition_test_equal(int *value, int *compared_to);
bool condition_test_lower(int *value, int *compared_to);
bool condition_test_lower_equal(int *value, int *compared_to);
bool condition_test_greater(int *value, int *compared_to);
bool condition_test_greater_equal(int *value, int *compared_to);
bool condition_test(struct condition *condition);
struct condition *condition_create(int *value, int *compared_to, enum condition_type condition_type);
bool fill_conditions(struct condition *condition);

#endif /* !CONDITION_H */
