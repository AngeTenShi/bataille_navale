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
		i++;
	}
	free_prof(splitted);
}

void	free_boats_name(game *prop)
{
	int i;

	i = 0;
	if (prop->player_one_boats == NULL)
		return ;
	while (i < 4)
	{
		free_prof(prop->player_one_boats[i].name);
		free_prof(prop->player_two_boats[i].name);
		i++;
	}
}