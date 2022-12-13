#include "../bataille.h"

void	get_size_from_buffer(game *prop, char *buffer)
{
	int		size_x;
	int		size_y;
	char	**temp_buf;
	char	**temp_size;

	temp_buf = ft_split(buffer, ' ');

	if (ft_strlen_2d(temp_buf) != 2)
		printf("Project size not correct re enter one\n");
	else
	{
		if (!strncmp(temp_buf[0], "Projet", 6) && strlen(temp_buf[0]) == 6)
		{
			temp_size = ft_split(temp_buf[1], 'x');
			size_x = atoi(temp_size[0]);
			size_y = atoi(temp_size[1]);
			if (!size_x || !size_y)
				printf("Project size not correct re enter one\n");
			free(temp_size);
			prop->size_x = size_x;
			prop->size_y = size_y;
		}
		else
			printf("Project size not correct re enter one\n");
	}
	free(temp_buf);
}

void	interactive_mode(game *prop)
{
	int interactive;
	char *buffer;

	interactive = 1;
	buffer = (char *)calloc_prof(50, sizeof(char));
	while (interactive)
	{
		if (!prop->size_x)
			printf("Enter a correct size to begin (format : Projet 1x1)\n");
		printf("Bataille navale > ");
		fgets(buffer, 50, stdin);
		if (!(prop->size_x))
			get_size_from_buffer(prop, buffer);
		if (!strncmp(buffer, "exit", 4))
			interactive = 0;
		fflush(stdin);
	}
	free(buffer);
}
