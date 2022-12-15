#include "../bataille.h"

void	init_board(game *prop)
{
	int i;

	i = 0;
	prop->board_j1 = (char **)malloc_prof(sizeof(char *) * (prop->size_y + 1));
	prop->board_j2 = (char **)malloc_prof(sizeof(char *) * (prop->size_y + 1));
	while (i < prop->size_y)
	{
		prop->board_j1[i] = calloc_prof(prop->size_x, sizeof(char));
		prop->board_j2[i] = calloc_prof(prop->size_x, sizeof(char));
		i++;
	}
	prop->board_j1[i] = 0;
	prop->board_j2[i] = 0;
}

int	place_on_board(game *prop, char *x, char *y, char player)
{
	char	**temp_range;
	int		i;
	int		x_pos;
	int		y_pos;
	char	**board;

	if (player == '1')
	{
		player = 'A';
		board = prop->board_j1;
	}
	else
	{
		player = 'B';
		board = prop->board_j2;
	}
	if (strchr(x, '-') != NULL)
	{
		y_pos = atoi(y);
		temp_range = ft_split(x, '-');
		i = min(temp_range[0], temp_range[1]);
		while (i <= max(temp_range[0], temp_range[1]))
		{
			if (board[y_pos][i] != ' ')
				board[y_pos][i] = player;
			i++;
		}
	}
	if (strchr(y, '-') != NULL)
	{
		x_pos = atoi(x);
		temp_range = ft_split(y, '-');
		i = min(temp_range[0], temp_range[1]);
		while (i <= max(temp_range[0], temp_range[1]))
		{
			board[i][x_pos] = player;
			i++;
		}
	}
	free_split(temp_range);
	return (1);
}

void	print_board(game *prop, char **board)
{
	int	i = 0;
	int j = 0;

	while (i < prop->size_y)
	{
		if (i == 0)
			printf("  ");
		printf("%d",i);
		i++;
	}
	printf("\n");
	i = 0;
	while (i < prop->size_y)
	{
		if (i == 0)
			printf("  ");
		printf("_");
		i++;
	}
	printf("\n");
	i = 0;
	j = 0;
	while (i < prop->size_y)
	{
		while (j < prop->size_x)
		{
			if (j == 0)
				printf("%d|",i);
			if (board[i][j] == 0)
				printf(".");
			else
				printf("%c", board[i][j]);
			if (j == prop->size_x - 1)
				printf("|");
			j++;
		}
		printf("\n");
		j = 0;
		i++;
	}
	i = 0;
	while (i < prop->size_y)
	{
		if (i == 0)
			printf("  ");
		printf("-");
		i++;
	}
	printf("\n");
}