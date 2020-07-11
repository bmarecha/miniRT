/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   addambiant.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmarecha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/10 14:15:08 by bmarecha          #+#    #+#             */
/*   Updated: 2020/07/11 17:33:50 by bmarecha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int			add_sizes(char **infos, t_scene *scene)
{
	int x;
	int y;

	if (!infos[1] || !infos[2] || infos[3])
		return (-1);
	if ((x = ft_atoi(infos[1])) == 0 ||
			(y = ft_atoi(infos[2])) == 0)
		return (-1);
	scene->xsize = x;
	scene->ysize = y;
	return (0);
}

int			add_ambiantlight(char **infos, t_scene *scene)
{
	float lum;

	if (!infos[1] || !infos[2] || !infos[3] || !infos[4] || infos[5])
		return (-1);
	if ((lum = ft_atof(infos[1])) < 0 || lum > 1)
		return (-1);
	scene->ambiantr = lum;
	if (add_colors(ft_atoi(infos[2]), ft_atoi(infos[3]), ft_atoi(infos[4]),
			&(scene->ambiantc)) == -1)
		return (-1);
	return (0);
}

int			add_light(char **infos, t_scene *scene)
{
	t_light		*new;

	if (!infos[1] || !infos[2] || !infos[3] || !infos[4] || !infos[5]
		|| !infos[6] || !infos[7] || infos[8] || !scene)
		return (-1);
	if (!(new = malloc(sizeof(t_light))))
		return (-1);
	point_create(infos[1], infos[2], infos[3], &(new->place));
	if ((new->rate = ft_atof(infos[4])) > 1 || new->rate < 0)
		return (-1);
	if (add_colors(ft_atoi(infos[5]), ft_atoi(infos[6]),
				ft_atoi(infos[7]), &(new->color)) == -1)
		return (-1);
	return (0);
}

int			add_camera(char **infos, t_scene *scene)
{
	t_camera	*new;

	if (!infos[1] || !infos[2] || !infos[3] || !infos[4] || !infos[5]
		|| !infos[6] || !infos[7] || infos[8] || !scene)
		return (-1);
	if (!(new = malloc(sizeof(t_camera))))
		return (-1);
	point_create(infos[1], infos[2], infos[3], &(new->place));
	point_create(infos[4], infos[5], infos[6], &(new->view));
	if (!(new->fov = ft_atoi(infos[7])) || new->view.x * new->view.x > 1
			|| new->view.y * new->view.y > 1 || new->view.z * new->view.z > 1)
	{
		free(new);
		return (-1);
	}
	ft_lstadd_front(&(scene->cams), ft_lstnew(new));
	return (0);
}

int			add_colors(int r, int g, int b, t_colors *colors)
{
	if (r < 0 || g < 0 || b < 0 || r > 255 || g > 255 || b > 255)
		return (-1);
	colors->r = r;
	colors->g = g;
	colors->b = b;
	return (0);
}
