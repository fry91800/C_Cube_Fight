#ifndef DISPLAY_H
#define DISPLAY_H

void clear_screen(SDL_Renderer *renderer);
void display(SDL_Renderer *renderer, struct player *player);
#endif /* !DISPLAY_H */