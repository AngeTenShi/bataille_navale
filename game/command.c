#include "../bataille.h"

int	identify_command(game *prop, char *buffer)
{
	char	**temp_buf;

	temp_buf = ft_split(buffer, ' ');
	if (ft_strlen_2d(temp_buf) == 1)
	{
		if (!strncmp("Afficher", buffer, strlen("Afficher")))
		{
			printf("Player One board : \n\n");
			print_board(prop, prop->board_j1);
			printf("\nPlayer Two board : \n\n");
			print_board(prop, prop->board_j2);
			write_into_savefile(prop, buffer);
		}
		else if (!strncmp("Jouer", buffer, strlen("Jouer")))
		{
			if (check_game_begin(prop)) /* Fonction qui permet de déterminer si la partie peut commencer*/
			{
				write_into_savefile(prop, buffer);
				printf("Game is going to start : \n");
			}
			else
			{
				printf("Game can't start because of the configuration\n");
				free_split(temp_buf);
				return (0);
			}
		}
		else
			printf("Unrecognized command retype one\n");
	}
	else
	{
		if (temp_buf[1][0] == 'P')
		{
			if (place_boats(prop, buffer))
				write_into_savefile(prop, buffer);
		}
		else if (temp_buf[1][0] == 'T')
		{
			if (shoot_boat(prop, buffer))
				write_into_savefile(prop, buffer);
		}
	}
	free_split(temp_buf);
	return (1);
}