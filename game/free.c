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
	boats	*tmp_j1;
	boats	*tmp_j2;

	if (prop->player_one_boats == NULL || prop->player_two_boats == NULL)
		return ;
	tmp_j1 = prop->player_one_boats;
	tmp_j2 = prop->player_two_boats;
	while (tmp_j1)
	{
		free_prof(tmp_j1->name);
		tmp_j1->name = NULL;
		tmp_j1 = tmp_j1->next;
	}
	while (tmp_j2)
	{
		free_prof(tmp_j2->name);
		tmp_j2->name = NULL;
		tmp_j2 = tmp_j2->next;
	}
}

void	free_boats(boats *bateaux)
{
	boats	*tmp;

	while (bateaux)
	{
		tmp = bateaux;
		bateaux = bateaux->next;
		free_prof(tmp);
	}
}