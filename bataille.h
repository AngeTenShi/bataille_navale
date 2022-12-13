#ifndef BATAILLE_H
# define BATAILLE_H

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <stddef.h>
#include <string.h>

/* STRUCTURE QUI IDENTIFIE CHAQUE BATEAU */
typedef struct boats
{
	char *name;
	int x_pos;
	int y_pos;
}	boats;


/* STRUCTURE GLOBALE QUI CONTINET LES PROPRIÉTES DE LA PARTIE */
typedef struct game_properties
{
	int	size_x;
	int	size_y;
	char **board;
	boats *player_one_boats;
	boats *player_two_boats;
} game;

/*//////////////////////////////////////////////*/
/* PROTOTYPE DU PROF POUR LA GESTION DE MEMOIRE */
void *malloc_prof (size_t taille);
void *calloc_prof (size_t nb, size_t taille);
void *realloc_prof (void *ptr, size_t taille);
void free_prof (void *ptr);
/*//////////////////////////////////////////////*/


/* PARSING */

int	parse_args(int ac, char **av);
char	**ft_split(char const *s, char c);
int	ft_strlen_2d(char **tab);

/* GAME */

void	interactive_mode(game *prop);

#endif