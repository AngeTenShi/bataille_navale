#include "../bataille.h"



void	identify_command(game *prop, char *buffer)
{
	if (strlen(buffer) == 1)
	{
		if (strncmp("Afficher", buffer, strlen("Afficher")))
		{
			print_board(prop, prop->board_j1);
			print_board(prop, prop->board_j2);
		}
		else if (strncmp("Jouer", buffer, strlen("Jouer")))
		{

		}
		else
			printf("Unrecognized command retype one\n");
	}
}