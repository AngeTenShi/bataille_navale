#include "../bataille.h"

static int	is_sep(char s, char c)
{
	if (s == c)
		return (1);
	else
		return (0);
}

static size_t	word(char const *s, char c)
{
	size_t	i;
	size_t	j;
	size_t	w;

	w = 0;
	i = 0;
	j = 0;
	while (s[i] && s[j])
	{
		i = j;
		while (is_sep(s[i], c) && s[i])
			i++;
		j = i;
		while ((!(is_sep(s[j], c))) && s[j])
			j++;
		if (j > i)
			w++;
	}
	return (w);
}

static int	alloc_char(size_t len, size_t index, char **tab)
{
	tab[index] = (char *)malloc_prof(sizeof(char) * len + 1);
	if (!tab[index])
		return (0);
	return (1);
}

static char	**walloc(char const *s, char c)
{
	char	**tab;
	size_t	i;
	size_t	j;
	size_t	w;

	w = 0;
	i = 0;
	j = 0;
	tab = (char **)malloc_prof(sizeof(char *) * (word(s, c) + 1));
	if (!tab)
		return (NULL);
	while (s[i] && s[j])
	{
		i = j;
		while (is_sep(s[i], c) && s[i])
			i++;
		j = i;
		while ((!(is_sep(s[j], c))) && s[j])
			j++;
		if (j > i)
			if (!(alloc_char(j - i, w, tab)))
				return (NULL);
		w++;
	}
	return (tab);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	size_t	w;
	size_t	i;
	size_t	j;

	if (!s)
		return (NULL);
	i = 0;
	j = 0;
	w = 0;
	tab = walloc(s, c);
	if (!tab)
		return (NULL);
	while (j < word(s, c))
	{
		w = 0;
		while (is_sep(s[i], c) && s[i])
			i++;
		while ((!(is_sep(s[i], c))) && s[i])
			tab[j][w++] = s[i++];
		tab[j][w] = 0
		;
		j++;
	}
	tab[j] = 0;
	return (tab);
}

int	ft_strlen_2d(char **tab)
{
	int i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}

char	*ft_strdup(char *c)
{
	char	*dup;

	dup = (char *)malloc_prof(strlen(c) + 1);
	if (dup != NULL)
		strcpy(dup, c);

	return (dup);
}

int	is_boat(game *prop, char *str, char player)
{
	boats	*temp;

	if (player == '1')
		temp = prop->player_one_boats;
	else
		temp = prop->player_two_boats;
	while (temp)
	{
		if (strlen(temp->name) == strlen(str))
		{
			if (!strncmp(str , temp->name, strlen(str)))
				return (1);
		}
		temp = temp->next;
	}
	return (0);
}

int	max(char *first, char *second)
{
	int f;
	int s;

	f = atoi(first);
	s = atoi(second);
	if (f > s)
		return (f);
	else
		return (s);
}

int	min(char *first, char *second)
{
	int f;
	int s;

	f = atoi(first);
	s = atoi(second);
	if (f < s)
		return (f);
	else
		return (s);
}

/* GESTION DES COMMENTAIRES DANS LE BUFFER */
void	trim_commentary(char *buffer)
{
	char	*index;
	char	*modif;

	index = strchr(buffer, '#');
	if (index != NULL)
	{
		while (index && *index)
		{
			modif = index;
			(*index)++;
			*modif = 0;
		}
	}
}

void clear_stdin()
{
	int c;
	while ((c = getchar()) != '\n' && c != EOF);
}
