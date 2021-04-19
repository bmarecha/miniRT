/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   addforms.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmarecha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/10 14:17:24 by bmarecha          #+#    #+#             */
/*   Updated: 2020/07/11 18:04:12 by bmarecha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	add_sphere(char **i, t_list **lst)
{
	t_sphere	*new;

	if (!i[1] || !i[2] || !i[3] || !i[4] || !i[5] || !i[6]
			|| !i[7] || i[8] || !lst)
		return (-1);
	new = malloc(sizeof(t_sphere));
	if (!new)
		return (-1);
	if (add_colors(atoi(i[5]), atoi(i[6]), atoi(i[7]), &(new->color)))
		return (-1);
	point_create(i[1], i[2], i[3], &(new->center));
	new->rayon = ft_atof(i[4]) / 2;
	ft_lstadd_front(lst, ft_lstnew(new));
	return (0);
}

int	add_plane(char **i, t_list **lst)
{
	t_plane	*new;
	t_colors color;
	t_point u;
	t_space base;

	u.x = atof(i[4]);
	u.y = atof(i[5]);
	u.z = atof(i[6]);
	if (!i[1] || !i[2] || !i[3] || !i[4] || !i[5] || !lst
		|| !i[6] || !i[7] || !i[8] || !i[9] || i[10])
		return (-1);
	new = malloc(sizeof(t_plane));
	if (!new)
		return (-1);
	if ((u.x * u.x + u.y * u.y + u.z * u.z > 1) || add_colors(atoi(i[7]),
		atoi(i[8]), atoi(i[9]), &(color)))
	{
		free(new);
		return (-1);
	}
	base = get_cam_space(u);
	create_plane(new, i + 1, base, color);
	ft_lstadd_front(lst, ft_lstnew(new));
	return (0);
}

int	add_square(char **i, t_list **lst)
{
	t_square	*new;
	t_point		norm;
	t_space		base;
	t_colors	c;

	if (!i[1] || !i[2] || !i[3] || !i[4] || !i[5] || !i[6] || !i[7]
		|| !i[8] || !i[9] || !i[10] || i[11] || !lst)
		return (-1);
	new = malloc(sizeof(t_square));
	if (!new || add_colors(atoi(i[8]), atoi(i[9]), atoi(i[10]), &c) == -1)
		return (-1);
	point_create(i[4], i[5], i[6], &(norm));
	if (norm.x * norm.x + norm.y * norm.y + norm.z * norm.z > 1)
		return (-1);
	base = get_cam_space(norm);
	create_plane(&(new->plane), i + 1, base, c);
	new->height = ft_atof(i[7]);
	ft_lstadd_front(lst, ft_lstnew(new));
	return (0);
}

int	add_cylindre(char **infos, t_list **lst)
{
	t_cylindre	*new;

	if (!infos[1] || !infos[2] || !infos[3] || !infos[4] || !infos[5]
		|| !infos[6] || !infos[7] || !infos[8] || !infos[9]
		|| !infos[10] || !infos[11] || infos[12] || !lst)
		return (-1);
	new = malloc(sizeof(t_cylindre));
	if (!new)
		return (-1);
	if (add_colors(atoi(infos[9]), atoi(infos[10]), atoi(infos[11]),
			&(new->color)) == -1)
		return (-1);
	point_create(infos[1], infos[2], infos[3], &(new->start));
	point_create(infos[4], infos[5], infos[6], &(new->way));
	if (!(new->way.x * new->way.x > 1 || new->way.y * new->way.y > 1
			|| new->way.z * new->way.z > 1))
	{
		free(new);
		return (-1);
	}
	new->diameter = ft_atof(infos[7]);
	new->height = ft_atof(infos[8]);
	if (*lst)
		ft_lstadd_front(lst, ft_lstnew(new));
	else
		*lst = ft_lstnew(new);
	return (0);
}

int	add_triangle(char **i, t_list **lst)
{
	t_triangle	*new;
	t_space		base;
	t_point		norm;
	t_colors	c;

	if (!i[1] || !i[2] || !i[3] || !i[4] || !i[5]
		|| !i[6] || !i[7] || !i[8] || !i[9] || !lst
		|| !i[10] || !i[11] || !i[12] || i[13])
		return (-1);
	new = malloc(sizeof(t_triangle));
	if (!new)
		return (-1);
	if (add_colors(atoi(i[10]), atoi(i[11]), atoi(i[12]), &c) == -1)
		return (-1);
	point_create(i[1], i[2], i[3], &(new->first));
	point_create(i[4], i[5], i[6], &(new->second));
	point_create(i[7], i[8], i[9], &(new->third));
	norm = prod_vect(less_v(new->second, new->first),
			less_v(new->third, new->second));
	base = get_cam_space(norm);
	create_plane(&(new->plane), i + 1, base, c);
	ft_lstadd_front(lst, ft_lstnew(new));
	return (0);
}
