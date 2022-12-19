#include "../bataille.h"

void init_boats(game *prop)
{
	int i;
	char *name_tabs[4] = {"Gaia", "Oedipe", "Athena", "Herecles"};

	if (prop->player_one_boats != NULL || prop->player_two_boats != NULL)
		return ;
	i = 0;
	prop->player_one_boats = (boats *)malloc_prof(sizeof(boats) * 4);
	prop->player_two_boats = (boats *)malloc_prof(sizeof(boats) * 4);
	while (i < 4)
	{
		prop->player_one_boats[i].name = ft_strdup(name_tabs[i]);
		prop->player_two_boats[i].name = ft_strdup(name_tabs[i]);
		if (i == 0)
			prop->player_one_boats[i].size = 2;
		else if (i == 1 || i == 2)
			prop->player_one_boats[i].size = 3;
		else
			prop->player_one_boats[i].size = 4;
		prop->player_two_boats[i].size = prop->player_one_boats[i].size;
		prop->player_one_boats[i].id = i;
		prop->player_two_boats[i].id = i;
		prop->player_one_boats[i].placed = 0;
		prop->player_two_boats[i].placed = 0;
		i++;
	}
}

/* DIFFÉRENTS CHECK POUR DIFFÉRENTS FORMATS */
int	check_for_four(game *prop, char **temp_buf)
{
	char	**temp_pos;

	if (temp_buf[0][0] =='J' && (temp_buf[0][1] == '1' || temp_buf[0][1] == '2') && strlen(temp_buf[0]) == 2)
	{
		if (temp_buf[1][0] == 'P' && strlen(temp_buf[1]) == 1)
		{
			if (is_boat(temp_buf[2]))
			{
				if (strchr(temp_buf[3], ':') != NULL)
				{
					temp_pos = ft_split(temp_buf[3], ':');
					if (!get_position(prop, temp_pos, temp_buf[0][1], temp_buf[2]))
					{
						free_split(temp_buf);
						free_split(temp_pos);
						return (0);
					}
					else
					{
						place_on_board(prop , temp_pos[0] , temp_pos[1], temp_buf[0][1]);
						/*set_boat_place(); // TODO */
						if (temp_buf[0][1] == '1')
							print_board(prop, prop->board_j1);
						else
							print_board(prop, prop->board_j2);
						prop->nb_boats++;
						free_split(temp_pos);
					}
				}
				else
				{
					print_error("Invalid format for placing boats\n", temp_buf);
					return (0);
				}
			}
			else
			{
				print_error("Invalid Boat Name\n", temp_buf);
				return (0);
			}
		}
		else
		{
			print_error("Invalid format for placing boats\n", temp_buf);
			return (0);
		}
	}
	else
	{
		print_error("Bad player number\n", temp_buf);
		return (0);
	}
	return (1);
}

/* DIFFÉRENTS CHECK POUR DIFFÉRENTS FORMATS */
int	check_for_three(game *prop, char **temp_buf)
{
	char	**temp_pos;

	if (temp_buf[0][0] =='J' && (temp_buf[0][1] == '1' || temp_buf[0][1] == '2') && strlen(temp_buf[0]) == 2)
	{
		if (temp_buf[1][0] == 'P' && strlen(temp_buf[1]) == 1)
		{
			if (strchr(temp_buf[2], ':') != NULL)
			{
				temp_pos = ft_split(temp_buf[2], ':');
				if (!get_position(prop, temp_pos, temp_buf[0][1], NULL))
				{
					free_split(temp_buf);
					free_split(temp_pos);
					return (0);
				}
				else
				{
					place_on_board(prop , temp_pos[0] , temp_pos[1], temp_buf[0][1]);
				/*set_boat_place(); // TODO */
					if (temp_buf[0][1] == '1')
					{
						print_board(prop, prop->board_j1);
						prop->nb_boats_j1++;
					}
					else
					{
						print_board(prop, prop->board_j2);
						prop->nb_boats_j2++;
					}
					free_split(temp_pos);
				}
			}
			else
			{
				print_error("Invalid format for placing boats\n", temp_buf);
				return (0);
			}
		}
		else
		{
			print_error("Invalid Player only two players in the game\n", temp_buf);
			return (0);
		}
	}
	else
	{
		print_error("Bad player number\n", temp_buf);
		return (0);
	}
	return (1);
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

int	shoot_boat(game *prop, char *buffer)
{
	(void)prop;
	(void)buffer;
	return (1);
}