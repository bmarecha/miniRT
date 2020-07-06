/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmarecha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/07 15:20:46 by bmarecha          #+#    #+#             */
/*   Updated: 2019/12/16 12:47:55 by bmarecha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_strrchr(char *str, char c)
{
	if (*str == c)
		return (1);
	while (*str++)
		if (*str == c)
			return (1);
	return (0);
}

char	*ft_stradd(char *dest, const char *src)
{
	unsigned long	i;
	unsigned long	b;
	char			*res;

	i = 0;
	b = 0;
	while (dest[i])
		i++;
	while (src[b])
		b++;
	if (!(res = malloc(i + b + 1)))
		return (NULL);
	res[i + b] = 0;
	while (b--)
		res[i + b] = src[b];
	while (i-- > 0)
		res[i] = dest[i];
	free(dest);
	return (res);
}

char	*ft_cpyto(char *src, char c)
{
	int		i;
	char	*cpy;

	i = 0;
	if (!src)
		return (NULL);
	while (src[i] && src[i] != c)
		i++;
	if (!(cpy = malloc(i + 1)))
		return (NULL);
	cpy[i] = '\0';
	while (i-- > 0)
		cpy[i] = src[i];
	return (cpy);
}

char	*ft_resetto(char *str, char c)
{
	int		i;
	int		j;
	char	*res;

	i = 0;
	j = 0;
	while (str[i + j])
	{
		if (str[i] != c)
			i++;
		else
			j++;
	}
	if (!(res = malloc(j + 1)))
	{
		free(str);
		return (NULL);
	}
	res[j] = 0;
	while (j--)
		res[j] = str[j + i + 1];
	free(str);
	return (res);
}
