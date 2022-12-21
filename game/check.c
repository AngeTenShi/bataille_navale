#include "../bataille.h"

int	is_not_placed(game *prop, char *name, char player)
{
	boats *boats;

	if (player == '1')
		boats = prop->player_one_boats;
	if (player == '2')
		boats = prop->player_two_boats;
	while (boats)
	{
		if (!strncmp(boats->name, name, strlen(name)) && strlen(name) == strlen(boats->name))
		{
			if (boats->placed == 1)
				return (0);
			else
				return (1);
		}
		boats = boats->next;
	}
	return (1);
}

/* Fonction pour checker si il y'a déjà un bateau là où on veut le placer*/
int	check_if_conflict(game *prop, int x, int y, char player)
{
	char	**board;

	if (player == '1')
		board = prop->board_j1;
	else
		board = prop->board_j2;
	if (board[y][x] != 0)
		return (1);
	return (0);
}

/* Fonction pour savoir si la valeur est dans le quadrillage si x_or_y = 1 on est en x sinon on est en y*/
int	check_into_board(game *prop, int val, int x_or_y)
{
	if (x_or_y)
	{
		if (val >= prop->size_x || val < 0)
			return (0);
	}
	else
	{
		if (val >= prop->size_y || val < 0)
			return (0);
	}
	return (1);
}

/* FONCTION POUR VERIFIER QUE LE BATEAU PLACE SELON LE NOM CORRESPOND À LA BONNE TAILLE*/
int	 check_if_size_boat(game *prop, char *boat, int size, char player)
{
	int		size_of_boat;
	boats	*element;

	size_of_boat = 0;
	if (player == '1')
		element = prop->player_one_boats;
	else
		element = prop->player_two_boats;
	if (boat == NULL)
		return (1);
	if (size > 4)
	{
		printf("Boat too long\n");
		return (0);
	}
	while (element)
	{
		if (!strncmp(boat, element->name, strlen(boat)) && strlen(boat) == strlen(element->name))
		{
			size_of_boat = element->size;
			break ;
		}
		element = element->next;
	}
	if (size == size_of_boat)
		return (1);
	else
		return (0);

}

int	check_same_boat(boats *list)
{
	boats	*tmp_1;
	boats	*tmp_2;
	int		count;

	tmp_1 =list;
	tmp_2 =list;
	count = 0;
	while (tmp_1 && list->next)
	{
		while (tmp_2)
		{
			if (!strncmp(tmp_2->name, tmp_1->name, strlen(tmp_1->name)))
				count++;
			tmp_2 = tmp_2->next;
		}
		if (count > 1)
			return (0);
		count = 0;
		tmp_2 = list;
		tmp_1 = tmp_1->next;
	}
	return (1);
}

int	check_same_j1_j2(game *prop)
{
	int	find;
	boats	*tmp_j1;
	boats	*tmp_j2;

	find = 0;
	tmp_j1 = prop->player_one_boats;
	tmp_j2 = prop->player_two_boats;
	while (tmp_j1)
	{
		while (tmp_j2 && find == 0)
		{
			if (!strncmp(tmp_j2->name, tmp_j1->name, strlen(tmp_j1->name)))
			{
				if (tmp_j1->size != tmp_j2->size)
					return (0);
				find = 1;
			}
			tmp_j2 = tmp_j2->next;
		}
		if (find == 0)
			return (0);
		find = 0;
		tmp_j2 = prop->player_two_boats;
		tmp_j1 = tmp_j1->next;
	}
	return (1);
}

int	check_game_begin(game *prop)
{
	int	nb_boats;

	nb_boats = prop->nb_boats_j1 + prop->nb_boats_j2;
	if (nb_boats < 2 || nb_boats > 6 )
		return (0);
	if (prop->nb_boats_j1 != prop->nb_boats_j2)
		return (0);
	if (!check_same_j1_j2(prop) || !check_same_boat(prop->player_one_boats) || !check_same_boat(prop->player_two_boats))
		return (0);
	return (1);
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
						if (is_not_placed(prop, temp_buf[2], temp_buf[0][1]))
							place_on_board(prop , temp_pos[0] , temp_pos[1], temp_buf[0][1]);
						else
						{
							free_split(temp_pos);
							free_split(temp_buf);
							return (0);
						}
						if (temp_buf[0][1] == '1')
						{
							set_boat_place(temp_buf[2], prop->player_one_boats);
							print_board(prop, prop->board_j1);
							prop->nb_boats_j1++;
						}
						else
						{
							set_boat_place(temp_buf[2], prop->player_two_boats);
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
					if (temp_buf[0][1] == '1')
					{
						set_boat_place(temp_buf[2], prop->player_one_boats);
						print_board(prop, prop->board_j1);
						prop->nb_boats_j1++;
					}
					else
					{
						set_boat_place(temp_buf[2], prop->player_two_boats);
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
			print_error("Invalid format for placing boats\n\n", temp_buf);
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
