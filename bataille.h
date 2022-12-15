#ifndef BATAILLE_H
# define BATAILLE_H

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <stddef.h>
#include <string.h>
#include <ctype.h>

/* STRUCTURE QUI IDENTIFIE CHAQUE BATEAU */
typedef struct boats
{
	int		id;
	char	*name;
	int		size;
	int		placed;
}	boats;


/* STRUCTURE GLOBALE QUI CONTINET LES PROPRIÉTES DE LA PARTIE */
typedef struct game_properties
{
	int		size_x;
	int		size_y;
	char	**board_j1;
	char	**board_j2;
	boats	*player_one_boats;
	boats	*player_two_boats;
	int		count;
} game;

/*//////////////////////////////////////////////*/
/* PROTOTYPE DU PROF POUR LA GESTION DE MEMOIRE */
void *malloc_prof (size_t taille);
void *calloc_prof (size_t nb, size_t taille);
void *realloc_prof (void *ptr, size_t taille);
void free_prof (void *ptr);
/*//////////////////////////////////////////////*/


/* PARSING */

int		exec_args(int ac, char **av, game *prop);
int		ft_strlen_2d(char **tab);
char	*ft_strdup(char *c);
int		is_boat(char *str);

/* GAME */

void	interactive_mode(game *prop);
void	init_boats(game *prop);
int		place_boats(game *prop, char *buffer);
int		get_position(game *prop, char **temp_pos);
void	init_board(game *prop);
int		place_on_board(game *prop, char *x, char *y, char player);
void	print_board(game *prop, char **board);

/* UTILS */
int		min(char *first, char *second);
int		max(char *first, char *second);
char	**ft_split(char const *s, char c);

/* ERROR */
void	print_error(char *message, void *to_free);

/* FREE */
void	free_boats_name(game *prop);
void	free_split(char **splitted);

#endif