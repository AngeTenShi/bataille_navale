#include "../bataille.h"

void	interactive_mode()
{
	int interactive;
	char *buffer;

	interactive = 1;
	buffer = (char *)calloc_prof(50, sizeof(char));
	while (interactive)
	{
		printf("Game interaction : ");
		scanf("%s", buffer);
		printf("Test : %s\n", buffer);
		fflush(stdin);
	}
	free(buffer);
}
