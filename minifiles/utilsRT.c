/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilsRT.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmarecha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/09 15:17:24 by bmarecha          #+#    #+#             */
/*   Updated: 2020/07/10 15:35:11 by bmarecha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int		ft_strcmp(char *a, char *b)
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

int		array_length(t_camera **array)
{
	int i;

	if (!array)
		return (0);
	i = 0;
	while (array[i])
		i++;
	
	return i;
}
/*
void	array_free(void *array)
{
	int i;

	i = 0;
	while (array[i])
	{
		free(array[i];)
		i++;
	}
	free(array);
}

void	*array_add(void **array, void *cell)
{
	void	*newarray;
	int		i;

	if (!(newarray = malloc(sizeof(void *) * (array_length(array) + 2))))
		return NULL;
	i = -1;
	if (array)
		while (array[++i])
			newarray[i] = array[i]
	newarray[i] = malloc(sizeof(*cell));
	newarray[i++] = cell;
	newarray[i] = 0;
	free(array);
	return (newarray);
}*/
