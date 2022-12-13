#include "../bataille.h"

int	parse_args(int ac, char **av)
{
	/*if (ac == 1)
		read_stdin_description(); */
	if (ac == 2 && !strncmp(av[1], "-i", 2))
		interactive_mode();
	/*else if (ac == 3 && !strncmp(av[1], "-f", 2))
		read_filemap(av);
	else
		return (0); */
	return (1);
}