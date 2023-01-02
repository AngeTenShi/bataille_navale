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

int	is_boat(char *str)
{
	/* A REFAIRE AVEC LES TABLEAUX DE BATEAUX */
	int i;
	char	*name_tabs[4] = {"\"Gaia\"","\"Oedipe\"","\"Athena\"","\"Herecles\""};

	i = 0;
	while (i < 4)
	{
		if (strlen(name_tabs[i]) == strlen(str))
		{
			if (!strncmp(str , name_tabs[i], strlen(str)))
				return (1);
		}
		i++;
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