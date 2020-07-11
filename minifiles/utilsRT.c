/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilsrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmarecha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/11 15:32:31 by bmarecha          #+#    #+#             */
/*   Updated: 2020/07/11 17:34:39 by bmarecha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

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
	return (i);
}

void	point_create(char *x, char *y, char *z, t_point *point)
{
	point->x = ft_atof(x);
	point->y = ft_atof(y);
	point->z = ft_atof(z);
}

void	scene_free(t_scene *scene)
{
	ft_lstclear(&(scene->cams), &free);
	ft_lstclear(&(scene->lights), &free);
	ft_lstclear(&(scene->spheres), &free);
	ft_lstclear(&(scene->planes), &free);
	ft_lstclear(&(scene->squares), &free);
	ft_lstclear(&(scene->cylindres), &free);
	ft_lstclear(&(scene->triangles), &free);
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
