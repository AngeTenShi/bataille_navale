#include "bataille.h"

/* 3 MAIN STEPS : (PARSING / GAME / FREE MEMORY) */

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