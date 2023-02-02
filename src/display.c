#include <SDL.h>
#include "player.h"
#define SIZE_SCALE 100

void clear_screen(SDL_Renderer *renderer)
{
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 
                    SDL_ALPHA_OPAQUE);
    SDL_RenderClear(renderer);
}

void display(SDL_Renderer *renderer, struct player *player)
{
    player->skin->x = player->x;
    player->skin->y = player->y;
    player->skin->w = player->size * SIZE_SCALE;
    player->skin->h = player->size * SIZE_SCALE;
    SDL_SetRenderDrawColor(renderer, 112, 168, 237, 
                    SDL_ALPHA_OPAQUE);
    SDL_RenderFillRect(renderer, player->skin);
    SDL_RenderPresent(renderer);
}