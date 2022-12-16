#include "../bataille.h"

int	is_only_number(char *str1, char *str2)
{
	int	i;

	i = 0;
	while (str1[i])
	{
		if (!isdigit(str1[i]))
			return (0);
		i++;
	}
	i = 0;
	while (str2[i])
	{
		if (!isdigit(str2[i]))
			return (0);
		i++;
	}
	return (1);
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

int	get_position(game *prop, char **temp_pos)
{
	char	*first_pos;
	char	*second_pos;
	char	**temp_range;
	int		i;

	first_pos = temp_pos[0];
	second_pos = temp_pos[1];
	temp_range = NULL;

	if (strchr(first_pos, '-') != NULL && strchr(second_pos, '-') != NULL)
	{
		printf("Error : You are making something wrong placing boats\n");
		return (0);
	}
	else if (strchr(first_pos, '-') != NULL)
	{
		if (!check_into_board(prop, atoi(second_pos), 0))
		{
			printf("Error : Your boat is out of board\n");
			return (0);
		}
		temp_range = ft_split(first_pos, '-');
		if (ft_strlen_2d(temp_range) != 1)
		{
			is_only_number(temp_range[0], temp_range[1]); /* Fonction pour vérifier qu'on envoie uniquement des nombres dans les coordonnées */
			i = min(temp_range[0], temp_range[1]);
			while (i <= max(temp_range[0], temp_range[1]))
			{
				if (!check_into_board(prop, i, 1))
				{
					print_error("Error : Your boat is out of board\n", temp_range);
					return (0);
				}
				i++;
			}
			free_split(temp_range);
		}
		else
		{
			free_split(temp_range);
			printf("Error : Your boat is out of board\n");
			return (0);
		}
		 /* CONDITION qui permet de vérifier si on a pas split un nombre négatif le résultat serait donc un tableau de taille 1 */
	}
	else if (strchr(second_pos, '-') != NULL)
	{
		if (!check_into_board(prop, atoi(first_pos), 1))
		{
			printf("Error : Your boat is out of board\n");
			return (0);
		}
		temp_range = ft_split(second_pos, '-');
		if (ft_strlen_2d(temp_range) != 1)
		{
			is_only_number(temp_range[0], temp_range[1]); /* Fonction pour vérifier qu'on envoie uniquement des nombres dans les coordonnées */
			i = min(temp_range[0], temp_range[1]);
			while (i <= max(temp_range[0], temp_range[1]))
			{
				if (!check_into_board(prop, i, 0))
				{
					print_error("Error : Your boat is out of board\n", temp_range);
					return (0);
				}
				i++;
			}
			free_split(temp_range);
		}
		else
		{
			free_split(temp_range);
			printf("Error : Your boat is out of board\n");
			return (0);
		}
	}
	else
	{
		if (!check_into_board(prop, atoi(temp_pos[0]), 1) || !check_into_board(prop, atoi(temp_pos[1]), 0))
		{
			printf("Error : Your boat is out of board\n");
			return (0);
		}

	}
	return (1);
}