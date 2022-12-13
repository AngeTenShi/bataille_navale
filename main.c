#include "bataille.h"

/* 3 MAIN STEPS : (PARSING / GAME / FREE MEMORY) */

/*
void	free_game(game_prop *prop)
{
	free_split(prop->board);
	free_boats_name(prop);
	free(prop->player_one_boats);
	free(prop->player_two_boats);
	free(prop);
}
*/

int	main(int ac, char **av)
{
	if (ac > 3)
		return (0);
	if (!parse_args(ac, av))
		fprintf(stderr, "Invalid format to execute the game\n");
	/*start_game();
	free_game(); */
	return (0);
}