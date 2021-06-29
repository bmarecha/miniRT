/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmarecha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 12:11:42 by bmarecha          #+#    #+#             */
/*   Updated: 2019/11/23 15:01:49 by bmarecha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_in(char c, char const *charset)
{
	int	i;

	i = -1;
	while (charset[++i])
		if (charset[i] == c)
			return (i);
	return (-1);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		j;
	char	*res;

	i = -1;
	j = -1;
	if (s1 == NULL)
		return (NULL);
	if (set == NULL)
		return (ft_strdup(s1));
	while (is_in(s1[++i], set) != -1 && s1[i])
		;
	if (s1[i + ++j])
	{
		while (s1[i + ++j])
			;
		while (is_in(s1[i + --j], set) != -1)
			;
	}
	res = malloc(++j + 1);
	if (res == NULL)
		return (NULL);
	res[j] = '\0';
	while (j--)
		res[j] = s1[i + j];
	return (res);
}
