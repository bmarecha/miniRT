/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   addambiant.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmarecha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/10 14:15:08 by bmarecha          #+#    #+#             */
/*   Updated: 2020/07/10 14:16:44 by bmarecha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int			add_sizes(char **infos, t_scene *scene)
{
	int x;
	int y;

	if (!infos[1] || !infos[2] || infos[3])
		return (-1);
	if ((x = atoi(infos[1])) == 0 ||
			(y = atoi(infos[2])) == 0)
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
	if ((lum = 0.2) == 0)
		return (-1);
	scene->ambiantr = lum;
	if (add_colors(atoi(infos[2]), atoi(infos[3]), atoi(infos[4]),
			&(scene->ambiantc)) == -1)
		return (-1);
	return (0);
}

int			add_light(char **infos, t_scene *scene)
{
	if (!infos[1] || !infos[2] || !infos[3] || !infos[4] || !infos[5]
		|| !infos[6] || !infos[7] || infos[8])
		return (-1);
	if (!scene)
		return (-1);
	return (0);
}

int			add_camera(char **infos, t_scene *scene)
{
	int			i;

	i = -1;
	if (!infos[1] || !infos[2] || !infos[3] || !infos[4] || !infos[5]
		|| !infos[6] || !infos[7] || infos[8])
		return (-1);
	scene->cams = NULL;
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
