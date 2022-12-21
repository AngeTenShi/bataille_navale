#include "bataille.h"

/* 3 MAIN STEPS : (PARSING / GAME / FREE MEMORY) */

void	free_game(game *prop)
{
	if (prop->board_j1 != NULL)
		free_split(prop->board_j1);
	if (prop->board_j2 != NULL)
		free_split(prop->board_j2);
	free_boats_name(prop);
	if (prop->game_id != NULL)
		free_prof(prop->game_id);
	if (prop->player_one_boats !=  NULL)
		free_boats(prop->player_one_boats);
	if (prop->player_one_boats != NULL)
		free_boats(prop->player_two_boats);
	free_prof(prop);
}


int	main(int ac, char **av)
{
	game *prop;
	if (ac > 3)
		return (0);
	prop = malloc_prof(sizeof(game));
	if (!exec_args(ac, av, prop))
		fprintf(stderr, "Invalid format to execute the game\n");
	free_game(prop);
	return (0);
}