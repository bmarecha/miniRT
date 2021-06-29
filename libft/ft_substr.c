/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmarecha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 12:26:42 by bmarecha          #+#    #+#             */
/*   Updated: 2019/11/23 14:44:33 by bmarecha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	char			*res;

	i = 0;
	if (s == NULL)
		return (NULL);
	while (s[i++])
		;
	if (start >= i)
		start = i - 1;
	if (i < (unsigned int)len + start)
	{
		res = malloc(i - start);
		if (res == NULL)
			return (NULL);
	}
	else if ((res = malloc(len + 1)) == NULL)
		return (NULL);
	i = 0;
	while (s[i + start] && i < len)
	{
		res[i] = s[i + start];
		i++;
	}
	res[i] = 0;
	return (res);
}
