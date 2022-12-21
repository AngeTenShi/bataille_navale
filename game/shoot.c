#include "../bataille.h"

int	check_position(game *prop, char **temp_pos)
{
	if (ft_strlen_2d(temp_pos) != 2)
		return (0);
	if (strlen(temp_pos[0]) != 1 && strlen(temp_pos[1]) != 1)
		return (0);
	if (atoi(temp_pos[0]) >= prop->size_x || atoi(temp_pos[1]) >= prop->size_y)
		return (0);
	return (1);
}

int	shoot(char **temp_pos, char ***board, char player)
{
	int		x;
	int		y;
	char	cible;
	char	myself;

	if (player == '1')
	{
		cible = 'B';
		myself = 'A';
	}
	else
	{
		cible = 'A';
		myself = 'B';
	}
	x = atoi(temp_pos[0]);
	y = atoi(temp_pos[1]);
	if ((*board)[y][x] == 0)
	{
		printf("*** Raté tu feras mieux la prochaine fois ***\n");
		(*board)[y][x] = '#';
	}
	else if ((*board)[y][x] == cible)
	{
		printf("*** Touché !! ***\n");
		(*board)[y][x] = '*';
	}
	else if ((*board)[y][x] == myself)
		printf("*** You can't shoot your self ***\n");
	return (1);
}

int	check_shoot(game *prop, char **temp_buf)
{
	char	**temp_pos;

	if (temp_buf[0][0] =='J' && (temp_buf[0][1] == '1' || temp_buf[0][1] == '2') && strlen(temp_buf[0]) == 2)
	{
		if (temp_buf[1][0] == 'T' && strlen(temp_buf[1]) == 1)
		{
			if (strchr(temp_buf[2], ':') != NULL)
			{
				temp_pos = ft_split(temp_buf[2], ':');
				if (!check_position(prop, temp_pos))
				{
					free_split(temp_buf);
					free_split(temp_pos);
					return (0);
				}
				else
				{
					if (temp_buf[0][1] == '1')
						shoot(temp_pos, &prop->board_j2, temp_buf[0][1]);
					else
						shoot(temp_pos, &prop->board_j1, temp_buf[0][1]);
					free_split(temp_pos);
				}
			}
			else
			{
				print_error("Invalid format for shooting boats\n", temp_buf);
				return (0);
			}
		}
		else
		{
			print_error("Invalid format for shooting boats\n", temp_buf);
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

int	shoot_boat(game *prop, char *buffer)
{
	char	**temp_buf;

	temp_buf = ft_split(buffer, ' ');
	if (ft_strlen_2d(temp_buf) != 3)
	{
		print_error("Invalid format for shooting boats\n", temp_buf);
		return (0);
	}
	else
	{
		if (!check_shoot(prop, temp_buf))
			return (0);
	}
	free_split(temp_buf);
	return (1);
}