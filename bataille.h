#ifndef BATAILLE_H
# define BATAILLE_H

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <stddef.h>
#include <string.h>
#include <ctype.h>
#include <time.h> /* USED FOR RANDOMIZED THE SEED TO GENERATE SAVE FILE */

/* STRUCTURE QUI IDENTIFIE CHAQUE BATEAU */
typedef struct boats
{
	char			*name;
	int				size;
	int				placed;
	struct boats	*next;
}	boats;


/* STRUCTURE GLOBALE QUI CONTINET LES PROPRIÉTES DE LA PARTIE */
typedef struct game_properties
{
	int		size_x;
	int		size_y;
	char	**board_j1;
	char	**board_j2;
	int		game_begin;
	boats	*player_one_boats;
	boats	*player_two_boats;
	int		count;
	int		nb_boats_j1;
	int		nb_boats_j2;
	char	*game_id;
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
void	set_boat_place(char *name, boats *list_boat);
void	read_file_description(game *prop, char *file);

/* GAME */

void	interactive_mode(game *prop);
void	init_boats(game *prop);
void	add_boat(boats **boat_list, char *name, int size);
int		place_boats(game *prop, char *buffer);
int		get_position(game *prop, char **temp_pos, char player, char *boat);
void	init_board(game *prop);
void	place_on_board(game *prop, char *x, char *y, char player);
void	print_board(game *prop, char **board);
int		identify_command(game *prop, char *buffer);
int		shoot_boat(game *prop, char *buffer);

/* CHECKS */
int	check_if_size_boat(game *prop, char *boat, int size, char player);
int	check_if_conflict(game *prop, int x, int y, char player);
int	check_into_board(game *prop, int val, int x_or_y);
int	check_game_begin(game *prop);
int	check_for_four(game *prop, char **temp_buf);
int	check_for_three(game *prop, char **temp_buf);
int	check_game_finished(game *prop);

/* SAVE */
void	generate_game_id(game *prop);
void	write_into_savefile(game *prop, char *buffer);

/* UTILS */
int		min(char *first, char *second);
int		max(char *first, char *second);
char	**ft_split(char const *s, char c);
int		get_size_from_buffer(game *prop, char *buffer);

/* ERROR */
void	print_error(char *message, char **to_free);

/* FREE */
void	free_boats_name(game *prop);
void	free_split(char **splitted);
void	free_boats(boats *bateaux);


#endif