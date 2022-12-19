#include "../bataille.h"

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
		free_split(temp_buf);
		return (0);
	}
	if (!strncmp(temp_buf[0], "Projet", 6) && strlen(temp_buf[0]) == 6)
	{
		temp_size = ft_split(temp_buf[1], 'x');
		size_x = atoi(temp_size[0]);
		size_y = atoi(temp_size[1]);
		if (size_x < 5 || size_y < 5)
		{
			printf("Project size too little re enter one\n");
			free_split(temp_size);
			free_split(temp_buf);
			return (0);
		}
		free_split(temp_size);
		prop->size_x = size_x;
		prop->size_y = size_y;
	}
	else
		printf("Project size not correct re enter one\n");
	free_split(temp_buf);
	return (1);
}

void	interactive_mode(game *prop)
{
	int		interactive;
	char	*buffer;
	int		count;

	interactive = 1;
	buffer = (char *)calloc_prof(50, sizeof(char));
	count = 0;
	printf("Welcome in the game your game id file is : %s\nYou can access it into save/%s\n", prop->game_id, prop->game_id);
	while (interactive)
	{
		if (prop->count == 0)
			printf("Enter a correct size to begin (format : Projet 1x1)\n");
		if (prop->count == 1)
		{
			init_boats(prop);
			printf("Place your boats on the board (Format : J1/2 P \"Name\" x:y)\n");
			printf("There is 4 types of boat per player : Gaia (size 2), Athena (size 3), Oedipe (taille 3), Herecles (size 4)\n");
		}
		printf("Bataille navale > ");
		fgets(buffer, 50, stdin);
		if (!strncmp(buffer, "exit", 4))
			break ;
		if (prop->count == 0)
		{
			if (get_size_from_buffer(prop, buffer))
			{
				init_board(prop);
				write_into_savefile(prop, buffer);
				count++;
			}
		}
		else
		{
			if (!identify_command(prop, buffer))
				break ;
			count++;
		}
		fflush(stdin);
		prop->count = count;
	}
	free_prof(buffer);
}
