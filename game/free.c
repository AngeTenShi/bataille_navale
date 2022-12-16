#include "../bataille.h"

void	free_split(char **splitted)
{
	int i;

	i = 0;
	if (!splitted)
		return ;
	while (splitted[i])
	{
		free_prof(splitted[i]);
		splitted[i] = NULL;
		i++;
	}
	free_prof(splitted);
	splitted = NULL;
}

void	free_boats_name(game *prop)
{
	int i;

	i = 0;
	if (prop->player_one_boats == NULL || prop->player_two_boats == NULL)
		return ;
	while (i < 4)
	{
		free_prof(prop->player_one_boats[i].name);
		prop->player_one_boats[i].name = NULL;
		free_prof(prop->player_two_boats[i].name);
		prop->player_two_boats[i].name = NULL;
		i++;
	}
}