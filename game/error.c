#include "../bataille.h"

void	print_error(char *message, void *to_free)
{
	if (to_free != NULL)
		free_split(to_free);
	printf("%s", message);
}