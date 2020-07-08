#include <stdlib.h>

int				ft_strcmp(char *a, char *b)
{
	while (*a && *b)
	{
		if (*a != *b)
			return (-1);
		a++;
		b++;
	}
	if (*a || *b)
		return (-1);
	return (0);
}

static int		is_in(char c, char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

static char		*ft_strndup(char *src, int n)
{
	int		i;
	char	*cpy;

	i = 0;
	while (src[i] && i < n)
		i++;
	if ((cpy = malloc(sizeof(char) * (i + 1))) == NULL)
		return (NULL);
	i = 0;
	while (src[i] && i < n)
	{
		cpy[i] = src[i];
		i++;
	}
	cpy[i] = '\0';
	return (cpy);
}

static	int		ft_word_count(char *str, char *charset)
{
	int i;
	int inside;
	int words;

	i = 0;
	inside = 0;
	words = 0;
	while (str[i])
	{
		if (is_in(str[i], charset) != -1)
			inside = 0;
		else if (inside == 0)
		{
			inside = 1;
			words++;
		}
		i++;
	}
	return (words);
}

char			**ft_split(char *str, char *charset)
{
	char	**split;
	int		words;
	int		i;
	int		length[2];

	words = ft_word_count(str, charset);
	if ((split = (char **)malloc(sizeof(char *) * (words + 1))) == NULL)
		return (NULL);
	i = 0;
	length[0] = 0;
	length[1] = 0;
	while (i < words)
	{
		while (str[length[1]] && is_in(str[length[1]], charset) == -1)
			length[1]++;
		if (length[1] == length[0])
			length[1]++;
		else
			split[i++] = ft_strndup(str + length[0], length[1] - length[0]);
		length[0] = length[1];
	}
	split[i] = 0;
	return (split);
}
