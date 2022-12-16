#include "../bataille.h"

void *malloc_prof (size_t taille)
{
	void* p = malloc(taille);
	/*printf("Malloc : %p\n", p); */
	return (p);
}

void *calloc_prof (size_t nb, size_t taille)
{
	void* p;
	p = calloc(nb,taille);
	/* printf("Malloc : %p\n", p); */
	return (p);
}

void *realloc_prof (void *ptr, size_t taille)
{
	void* p = realloc(ptr, taille);
	return (p);
}

void free_prof (void *ptr)
{
	/*printf("Free : %p\n", ptr); */
	free(ptr);
}