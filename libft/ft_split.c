/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmarecha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/19 10:30:26 by bmarecha          #+#    #+#             */
/*   Updated: 2019/11/23 15:26:57 by bmarecha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*ft_strndup(const char *src, int n)
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

static int		ft_word_count(const char *str, char c)
{
	int i;
	int inside;
	int words;

	i = 0;
	inside = 0;
	words = 0;
	while (str[i])
	{
		if (str[i] == c)
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

static char		**all_free(char **split, int i)
{
	while (--i)
		free(split[i]);
	free(split);
	return (NULL);
}

char			**ft_split(char const *str, char c)
{
	char	**split;
	int		words;
	int		i;
	int		length[2];

	if (str == NULL)
		return (NULL);
	words = ft_word_count(str, c);
	if ((split = (char **)malloc(sizeof(char *) * (words + 1))) == NULL)
		return (NULL);
	i = 0;
	length[1] = 0;
	while (i < words)
	{
		length[0] = length[1];
		while (str[length[1]] && str[length[1]] != c)
			length[1]++;
		if (length[1] == length[0])
			length[1]++;
		else if ((split[i++] = ft_strndup(str + length[0],
			length[1] - length[0])) == NULL)
			return (all_free(split, --i));
	}
	split[i] = 0;
	return (split);
}
