#include "../bataille.h"

void	write_into_savefile(game *prop, char *buffer)
{
	FILE	*fptr;
	char	temp_name[35];
	char	*filename;

	sprintf(temp_name, "./save/%s", prop->game_id);
	filename = ft_strdup(temp_name);
	if ((fptr = fopen(filename, "a+")) == NULL)
	{
		printf("Error while opening save file\n");
		free_prof(filename);
		return ;
	}
	fwrite(buffer, sizeof(char), strlen(buffer), fptr);
	free_prof(filename);
	fclose(fptr);
}

void	generate_game_id(game *prop)
{
	char	filename[25];

	srand(time(NULL));
	sprintf(filename, "game_%d.save", rand());
	prop->game_id = ft_strdup(filename);
}