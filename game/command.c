#include "../bataille.h"

int	identify_command(game *prop, char *buffer)
{
	char	**temp_buf;

	temp_buf = ft_split(buffer, ' ');
	if (ft_strlen_2d(temp_buf) == 0)
		return (1);
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
			if (prop->game_begin == 0)
			{
				if (check_game_begin(prop)) /* Fonction qui permet de déterminer si la partie peut commencer*/
				{
					write_into_savefile(prop, buffer);
					printf("******************************\n");
					printf("*   Game is going to start   *\n");
					printf("******************************\n\n");
					prop->game_begin = 1;
					prop->count = 2;
				}
				else
				{
					printf("Game can't start because of the configuration\n");
					free_split(temp_buf);
					return (0);
				}
			}
			else
				printf("You can't launched a game that is already launched\n");
		}
		else
			printf("Unrecognized command retype one\n");
	}
	else
	{
		if (temp_buf[1][0] == 'P')
		{
			if (prop->game_begin == 0)
			{
				if (place_boats(prop, buffer))
				{
					write_into_savefile(prop, buffer);
					prop->count++;
				}
			}
			else
				printf("You can't place boats while game is launched\n");
		}
		else if (temp_buf[1][0] == 'T')
		{
			if ((prop->count % 2 == 0 && temp_buf[0][1] == '1') || (prop->count % 2 == 1 && temp_buf[0][1] == '2'))
			{
				if (prop->game_begin == 1)
				{
					if (shoot_boat(prop, buffer))
					{
						write_into_savefile(prop, buffer);
						prop->count++;
					}
				}
				else
					printf("You can't shoot other boats while game isn't launched\n");
			}
			else
				printf("It's not your turn let your opponent play ...\n");
		}
		else
			printf("Unrecognized command retype one\n");
	}
	free_split(temp_buf);
	if (prop->game_begin == 1)
	{
		if (check_game_finished(prop))
			return (0);
	}
	return (1);
}