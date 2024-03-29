/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmarecha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/19 10:30:26 by bmarecha          #+#    #+#             */
/*   Updated: 2020/07/10 15:44:17 by bmarecha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	is_in(char c, char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

static char	*ft_strndup(char *src, int n)
{
	int		i;
	char	*cpy;

	i = 0;
	while (src[i] && i < n)
		i++;
	cpy = malloc(sizeof(char) * (i + 1));
	if (!cpy)
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

static int	ft_word_count(char *str, char *charset, char ***to_malloc)
{
	int	i;
	int	inside;
	int	words;

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
	*to_malloc = (char **)malloc(sizeof(char *) * (words + 1));
	(*to_malloc)[words] = 0;
	return (words);
}

char	**mini_split(char *str, char *charset)
{
	char	**split;
	int		words;
	int		i;
	int		length[2];

	if (!str)
		return (NULL);
	split = NULL;
	words = ft_word_count(str, charset, &split);
	if (!split)
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
	return (split);
}
