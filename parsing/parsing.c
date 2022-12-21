#include "../bataille.h"

/* INITIALISATION DES PROPRIÉTES DU JEU DANS UNE STRUCTURE */

void	init_game_prop(game *prop)
{
	prop->player_one_boats = NULL;
	prop->player_two_boats = NULL;
	prop->size_x = 0;
	prop->size_y = 0;
	prop->count = 0;
	prop->board_j1 = NULL;
	prop->board_j2 = NULL;
	prop->nb_boats_j1 = 0;
	prop->nb_boats_j2 = 0;
	prop->game_begin = 0;
	generate_game_id(prop);
}

int exec_args(int ac, char **av, game *prop)
{
	init_game_prop(prop);
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