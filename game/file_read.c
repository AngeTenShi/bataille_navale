#include "../bataille.h"

void	read_file_description(game *prop, char *file)
{
	char	*buffer;
	char	**temp_buf;
	FILE	*fptr;

	if (!(fptr = fopen(file, "r")))
	{
		printf("File doesn't exist\n");
		return ;
	}
	buffer = calloc_prof(1024, sizeof(char));
	while (fgets(buffer, 1024, fptr) != NULL)
	{
		if (buffer[0] == '#')
			continue ;
		trim_commentary(buffer);
		if (prop->count == 0)
		{
			if (get_size_from_buffer(prop, buffer))
			{
				init_board(prop);
				write_into_savefile(prop, buffer);
				prop->count++;
			}
			else
			{
				printf("Exiting because of your configuration file\n");
				break ;
			}
		}
		else
		{
			if (strchr(buffer, 'P') != NULL)
			{
				temp_buf = ft_split(buffer, ' ');
				if (ft_strlen_2d(temp_buf) == 4)
				{
					if (temp_buf[0][1])
					{
						if (temp_buf[0][1] == '1')
							add_boat(&prop->player_one_boats, ft_strdup(temp_buf[2]), -1);
						else
							add_boat(&prop->player_two_boats, ft_strdup(temp_buf[2]), -1);
					}
				}
				if (ft_strlen_2d(temp_buf) == 3)
				{
					if (temp_buf[0][1])
					{
						if (temp_buf[0][1] == '1')
							add_boat(&prop->player_one_boats, ft_strdup("noname"), -1);
						else
							add_boat(&prop->player_two_boats, ft_strdup("noname"), -1);
					}
				}
				free_split(temp_buf);
			}
			if (!identify_command(prop, buffer))
			{
				free_prof(buffer);
				fclose(fptr);
				return ;
			}
		}
	}
	free_prof(buffer);
	fclose(fptr);
	if (!strcmp(file, "/dev/stdin"))
	{
		printf("YOU CAN START THE GAME LIKE THAT : ./program -f save_file\n");
	}
	else
		interactive_mode(prop);
}