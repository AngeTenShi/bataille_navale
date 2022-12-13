#include "../bataille.h"


/* INITIALISATION DES PROPRIÉTES DU JEU DANS UNE STRUCTURE */
game	*init_game_prop()
{
	game *ret;

	ret = (game *)malloc_prof(sizeof(game));
	ret->player_one_boats = NULL;
	ret->player_two_boats = NULL;
	ret->size_x = 0;
	ret->size_y = 0;
	ret->board = NULL;
	return (ret);
}

int	parse_args(int ac, char **av)
{
	game *prop;

	prop = init_game_prop();
	/*if (ac == 1)
		read_stdin_description(); */
	if (ac == 2 && !strncmp(av[1], "-i", 2))
		interactive_mode(prop);
	/*else if (ac == 3 && !strncmp(av[1], "-f", 2))
		read_filemap(av);
	else
		return (0); */
	return (1);
}