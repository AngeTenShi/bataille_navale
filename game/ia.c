#include "../bataille.h"

IA	*init_IA(void)
{
	IA *player;

	player = malloc_prof(sizeof(IA));
	player->last_touch_x = 0;
	player->last_touch_y = 0;
	return (player);
}

int	ia_play(game *prop, IA *player)
{
	int	x;
	int	y;
	char *input;
	int	temp_x;
	int	temp_y;

	temp_x = player->last_touch_x;
	temp_y = player->last_touch_y;

	srand(time(NULL));
	if (player->last_touch_x != 0)
	{
		if (prop->size_x < player->last_touch_x + 1)
			x = player->last_touch_x + 1;
		else if (player->last_touch_x - 1 >= 0)
			x = player->last_touch_x - 1;
		else
			x = player->last_touch_x;
	}
	else
		x = rand() % prop->size_x;
	if (player->last_touch_y != 0)
	{
		if (x == player->last_touch_x)
			y = player->last_touch_y;
		else
		{
			if (prop->size_y < player->last_touch_y + 1)
				y = player->last_touch_y + 1;
			else if (player->last_touch_y - 1 >= 0)
				y = player->last_touch_y - 1;
		}
	}
	else
		y = rand() % prop->size_y;
	input = calloc_prof(9, 1);
	sprintf(input, "J2 T %d:%d", x, y);
	if (prop->board_j1[y][x] == '#')
	{
		if (x == temp_x)
			player->last_touch_x = 0;
		if (y == temp_y)
			player->last_touch_y = 0;
	}
	if (!identify_command(prop, input))
	{
		free_prof(input);
		return (0);
	}
	free_prof(input);
	return (1);
}

void	ia_placeboat(game *prop)
{
	int	i;
	int	x;
	int	y;
	char *input;
	boats	*tmp;

	srand(time(NULL));
	tmp = prop->player_two_boats;
	i = 0;
	while (i < 4)
	{
		input = calloc_prof(50, 1);
		x = rand() % (prop->size_x - tmp->size);
		y = rand() % (prop->size_y - tmp->size); /* X ET Y ALEATOIRE POUR PLACER LES BATEAUX DE L'IA selon la taille du bateau */
		if (rand() % 2 == 0) /* UNE CHANCE SUR DEUX QUE LE BATEAUX SOIT EN VERTICALE OU HORIZONTALE */
			sprintf(input, "J2 P %s %d-%d:%d", tmp->name, x, x + tmp->size - 1, y);
		else
			sprintf(input, "J2 P %s %d:%d-%d", tmp->name, x, y, y + tmp->size - 1);
		if (place_boats(prop, input))
		{
			tmp = tmp->next;
			i++;
			prop->count++;
		}
		free_prof(input);
	}
	printf("IA has finished placing it's boats\n");
}