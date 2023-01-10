#include "../bataille.h"

int get_size_from_buffer(game *prop, char *buffer)
{
	int size_x;
	int size_y;
	char **temp_buf;
	char **temp_size;

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
		if (size_x < 5 || size_y < 5 || size_x > 10 || size_y > 10)
		{
			printf("Project size too little or too long re enter one\n");
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

void interactive_mode(game *prop)
{
	int interactive;
	char *buffer;
	char	ask;
	int		ia;
	IA *player;

	interactive = 1;
	ia = 0;
	buffer = (char *)calloc_prof(1024, sizeof(char));
	printf("Welcome in the game your game id file is : %s\nYou can access it into save/%s\n", prop->game_id, prop->game_id);
	if (prop->count == 0)
	{
		printf("Do you want to play against IA ? : (y or n)\n");
		scanf("%c", &ask);
		printf("\n\n");
		if (ask == 'y')
		{
			ia = 1;
			player = init_IA();
		}
		clear_stdin();
	}
	while (interactive)
	{
		if (prop->count == 0)
			printf("Enter a correct size to begin (format : Projet 1x1)\n");
		if (prop->count == 1)
		{
			init_boats(prop);
			if (ia)
				ia_placeboat(prop);
			printf("Place your boats on the board (Format : J1/2 P \"Name\" x:y)\n");
			printf("There is 4 types of boat per player : Gaia (size 2), Athena (size 3), Oedipe (taille 3), Herecles (size 4)\n");
		}
		if (ia && prop->count % 2 == 1 && prop->count > 1 && prop->game_begin)
		{
			printf("IA IS GOING TO PLAY :\n");
			sleep(5);
			if (!ia_play(prop, player))
				break ;
			identify_command(prop, "Afficher");
		}
		printf("Bataille navale > ");
		fgets(buffer, 1024, stdin);
		trim_commentary(buffer);
		if (!strncmp(buffer, "exit", 4))
			break;
		if (prop->count == 0)
		{
			if (get_size_from_buffer(prop, buffer))
			{
				init_board(prop);
				write_into_savefile(prop, buffer);
				prop->count++;
			}
		}
		else
		{
			if (!identify_command(prop, buffer))
				break;
		}
	}
	if (ia)
		free_prof(player);
	free_prof(buffer);
}
