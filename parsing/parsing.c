#include "../bataille.h"


/* INITIALISATION DES PROPRIÉTES DU JEU DANS UNE STRUCTURE */

void	init_boats(game *prop)
{
	int i;
	char	*name_tabs[4] = {"Gaia","Oedipe","Athena","Herecles"};

	i = 0;
	prop->player_one_boats = (boats *)malloc(sizeof(boats) * 4);
	prop->player_two_boats = (boats *)malloc(sizeof(boats) * 4);
	while (i < 4)
	{
		prop->player_one_boats[i].name = ft_strdup(name_tabs[i]);
		prop->player_two_boats[i].name = ft_strdup(name_tabs[i]);
		if (i == 0)
			prop->player_one_boats[i].size = 2;
		else if (i == 1 || i == 2)
			prop->player_one_boats[i].size = 3;
		else
			prop->player_one_boats[i].size = 4;
		prop->player_two_boats[i].size = prop->player_one_boats[i].size;
		i++;
	}
}

game	*init_game_prop()
{
	game *ret;

	ret = (game *)malloc_prof(sizeof(game));
	ret->player_one_boats = NULL;
	ret->player_two_boats = NULL;
	ret->size_x = 0;
	ret->size_y = 0;
	ret->count = 0;
	ret->board = NULL;
	init_boats(ret);
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