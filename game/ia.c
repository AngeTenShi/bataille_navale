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