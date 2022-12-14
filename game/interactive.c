#include "../bataille.h"

int	place_boats(game *prop, char *buffer)
{
	
	return (1);
}

void	init_board(game *prop)
{
	int i;

	i = 0;
	prop->board = (char **)malloc_prof(sizeof(char *) * (prop->size_y + 1));
	while (i < prop->size_y)
	{
		prop->board[i] = (char *)calloc_prof(prop->size_x, sizeof(char));
		i++;
	}
}

int	get_size_from_buffer(game *prop, char *buffer)
{
	int		size_x;
	int		size_y;
	char	**temp_buf;
	char	**temp_size;

	temp_buf = ft_split(buffer, ' ');
	if (ft_strlen_2d(temp_buf) != 2)
	{
		printf("Project size not correct re enter one\n");
		free(temp_buf);
		return (0);
	}
	else
	{
		if (!strncmp(temp_buf[0], "Projet", 6) && strlen(temp_buf[0]) == 6)
		{
			temp_size = ft_split(temp_buf[1], 'x');
			size_x = atoi(temp_size[0]);
			size_y = atoi(temp_size[1]);
			if (size_x < 5 || size_y < 5)
			{
				printf("Project size too little re enter one\n");
				free(temp_size);
				free(temp_buf);
				return (0);
			}
			free(temp_size);
			prop->size_x = size_x;
			prop->size_y = size_y;
		}
		else
			printf("Project size not correct re enter one\n");
	}
	free(temp_buf);
	return (1);
}

void	interactive_mode(game *prop)
{
	int interactive;
	char *buffer;
	int	count;

	interactive = 1;
	buffer = (char *)calloc_prof(50, sizeof(char));
	count = 0;
	while (interactive)
	{
		if (prop->count == 0)
			printf("Enter a correct size to begin (format : Projet 1x1)\n");
		if (prop->count == 1)
		{
			printf("Place your boats on the board (Format : J1/2 P Name P y:x)\n");
			printf("There is 4 types of boat per player : Gaia (size 2), Athena (size 3), Oedipe (taille 3), Herecles (size 4)\n");
		}
		printf("Bataille navale > ");
		fgets(buffer, 50, stdin);
		if (prop->count == 0)
		{
			if (get_size_from_buffer(prop, buffer))
			{
				init_board(prop);
				count++;
			}
		}
		if (prop->count == 1)
		{
			if (place_boats(prop, buffer))
				count++;
		}
		if (!strncmp(buffer, "exit", 4))
			interactive = 0;
		fflush(stdin);
		prop->count = count;
	}
	free(buffer);
}
