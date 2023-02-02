#include <stdio.h>
#include <SDL.h>
#include "cube_fight.h"
int main(int argc, char *argv[])
{
	SDL_Window *window = NULL;
	SDL_Renderer *renderer = NULL;
	SDL_Init(SDL_INIT_VIDEO);
	window = SDL_CreateWindow("Game",
			SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
			800, 600, 0);
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_SOFTWARE);
	SDL_SetRenderDrawColor(renderer, 112, 168, 237, SDL_ALPHA_OPAQUE);
	SDL_Rect rectangle;
	rectangle.x = 300;
	rectangle.y = 300;
	rectangle.w = 200;
	rectangle.h = 120;
	SDL_RenderFillRect(renderer, &rectangle);
	SDL_RenderPresent(renderer);
	int c = 1;


    //Game init
    struct game *game = create_game();
    struct player *player1 = create_player();
    struct player **players = calloc(3, sizeof(struct player *));
    players[0] = player1;
    struct boundary **boundaries = NULL;
    struct item **items = NULL;
    struct action **actions = calloc(64, sizeof(struct action*));
    struct effect **effects = calloc(64, sizeof(struct effect*));
    game->players = players;
    game->boundaries = boundaries;
    game->items = items;
    game->actions = actions;
    game->effects = effects;
    actions[0] = calloc(1, sizeof(struct action));
    struct effect *player1_go_right = create_effect(player1, player1->speed, MOVEX);
    struct condition *player1_has_right_pressed = create_condition(player1, KEY_PRESSED, RIGHT_KEY_PRESSED);
    actions[0]->start_condition = player1_has_right_pressed;
    actions[0]->effect = player1_go_right;
    //Game init end
	while(c < 500)
	{
		clear_screen(renderer);

        process_events(game);
        //action list
        //
        if (fill_conditions(actions[0]->start_condition))
        {
            apply_effect(player1_go_right->player, player1_go_right->info, player1_go_right->effect_type);
        }
        //apply_effect(player1_go_right->player, player1_go_right->info, player1_go_right->effect_type);
        apply_physics(game->players, game->items, game->boundaries);
		display(renderer, player1);
        player1->x += 1;
		c++;
		SDL_Delay(5);

	}
	SDL_Delay(100);


	SDL_Quit();
}
