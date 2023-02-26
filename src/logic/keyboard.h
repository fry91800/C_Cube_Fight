#ifndef KEYBOARD_H
#define KEYBOARD_H

#include <stdbool.h>

//Struct condition record a test to be made on 2 int pointers
enum key_state
{
    KEY_RELEASED,
    KEY_JUST_RELEASED,
    KEY_JUST_PRESSED,
    KEY_PRESSED
};

#endif /* !KEYBOARD_H */
