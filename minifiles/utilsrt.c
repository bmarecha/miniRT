/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilsrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmarecha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/11 15:32:31 by bmarecha          #+#    #+#             */
/*   Updated: 2020/07/15 16:58:28 by bmarecha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	ft_strcmp(char *a, char *b)
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

int	array_length(t_camera **array)
{
	int	i;

	if (!array)
		return (0);
	i = 0;
	while (array[i])
		i++;
	return (i);
}

int	exit_prog(t_scene *scene)
{
	mlx_destroy_image(scene->mlink, scene->ilink);
	window_destroy(scene);
	exit(0);
	return (1);
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
	free(scene);
}

void	error_exit(int error)
{
	write(STDERR_FILENO, "Error\n", 6);
	if (error == -2)
		write(STDERR_FILENO, "Map manquante\n", 14);
	else if (error == -3)
		write(STDERR_FILENO, "Erreur de map\n", 14);
	else if (error == -4)
		write(STDERR_FILENO, "Erreur d'allocation\n", 20);
	else if (error == -5)
		write(STDERR_FILENO, "Erreur avec le fichier .bmp\n", 28);
	exit(error);
}
