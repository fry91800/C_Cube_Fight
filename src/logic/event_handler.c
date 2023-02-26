#include <stdio.h>
#include <SDL.h>
#include "player.h"
#include "condition.h"
#include "game.h"

void process_events(struct game *game)
{
    SDL_Event event;
    struct player **current = game->players;
    if ((*current)->right_key_state == KEY_JUST_PRESSED)
        (*current)->right_key_state = KEY_PRESSED;
    if ((*current)->right_key_state == KEY_JUST_RELEASED)
        (*current)->right_key_state = KEY_RELEASED;
    while(SDL_PollEvent(&event))
    {
        if (event.key.keysym.scancode == SDL_SCANCODE_E)
        {
            if (event.type == SDL_KEYDOWN)
            {
                if (((*current)->right_key_state != KEY_PRESSED))
                {
                    (*current)->right_key_state = KEY_JUST_PRESSED;
                }
            }
            else if(event.type == SDL_KEYUP)
            {
                if (((*current)->right_key_state != KEY_RELEASED))
                {
                    (*current)->right_key_state = KEY_JUST_RELEASED;
                }
            }
        }
    }
}
