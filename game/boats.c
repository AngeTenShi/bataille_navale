#include "../bataille.h"

void	add_boat(boats **boat_list, char *name, int size)
{
	boats	*tmp;
	boats	*new;

	new = malloc_prof(sizeof(boats));
	new->next = NULL;
	new->placed = 0;
	new->size = size;
	new->name = name;
	tmp = *boat_list;
	if (!tmp)
	{
		*boat_list = new;
		return ;
	}
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
}

void init_boats(game *prop)
{
	int i;
	char *name_tabs[4] = {"\"Gaia\"", "\"Oedipe\"", "\"Athena\"", "\"Herecles\""};
	int	size;

	size = 0;
	if (prop->player_one_boats != NULL || prop->player_two_boats != NULL)
		return ;
	i = 0;
	while (i < 4)
	{
		if (i == 0)
			size = 2;
		else if (i == 1 || i == 2)
			size = 3;
		else
			size = 4;
		add_boat(&prop->player_one_boats, ft_strdup(name_tabs[i]), size);
		add_boat(&prop->player_two_boats, ft_strdup(name_tabs[i]), size);
		i++;
	}

}

void	set_boat_place(char *name, boats *list_boat)
{
	while (list_boat)
	{
		if (!strncmp(name, list_boat->name, strlen(name)))
		{
			list_boat->placed = 1;
			return ;
		}
		list_boat = list_boat->next;
	}
}

int	place_boats(game *prop, char *buffer)
{
	char	**temp_buf;

	temp_buf = ft_split(buffer, ' ');
	if (ft_strlen_2d(temp_buf) != 4 && ft_strlen_2d(temp_buf) != 3)
	{
		print_error("Invalid format for placing boats\n", temp_buf);
		return (0);
	}
	if (ft_strlen_2d(temp_buf) == 4)
	{
		if (!check_for_four(prop, temp_buf))
			return (0);
	}
	else if (ft_strlen_2d(temp_buf) == 3)
	{
		if (!check_for_three(prop, temp_buf))
			return (0);
	}
	free_split(temp_buf);
	return (1);
}