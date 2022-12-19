#include "../bataille.h"

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
	int	size_of_boat;
	int	i;
	int	nb_boats;
// DEFINIR DE QUELLES LISTES DE BATEAUX ON PARLE J1 OU 2
	if (player == '1')
		nb_boats = prop->nb_boats_j1;
	else
		nb_boats = prop->nb_boats_j2;
	i = 0;
	if (boat == NULL)
		return (1);
	if (size > 4)
	{
		printf("Boat too long\n");
		return (0);
	}
	if (is_boat(boat))
	{
		while (i < 4)
		{
			if (!strncmp(boat, prop->player_one_boats[i].name, strlen(boat)) && strlen(boat) == strlen(prop->player_one_boats[i].name))
			{
				size_of_boat = prop->player_one_boats[i].size;
				break ;
			}
			i++;
		}
	}
	else
	{
		while (i < nb_boats)
		{
			if (!strncmp(boat, prop->player_one_boats[i].name, strlen(boat)) && strlen(boat) == strlen(prop->player_one_boats[i].name))
			{
				size_of_boat = prop->player_one_boats[i].size;
				break ;
			}
			i++;
		}
	}
	if (size == size_of_boat)
		return (1);
	else
		return (0);

}


int	check_game_begin(game *prop)
{
	/*
	if (prop->nb_boats < 4 || prop->nb_boats > 6 )
		return (0); */
	return (1);
}