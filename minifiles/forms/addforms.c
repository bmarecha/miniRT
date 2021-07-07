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
	t_plane		*new;
	t_colors	color;
	t_point		u;
	t_space		base;

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
	point_create(i[4], i[5], i[6], &(norm));
	if (norm.x * norm.x + norm.y * norm.y + norm.z * norm.z > 1)
		return (-1);
	new = malloc(sizeof(t_square));
	if (!new || add_colors(atoi(i[8]), atoi(i[9]), atoi(i[10]), &c) == -1)
		return (-1);
	base = get_cam_space(norm);
	create_inv_vect(base.v, base.w, &(new->inv_u), &(new->inv_v));
	create_plane(&(new->plane), i + 1, base, c);
	new->height = ft_atof(i[7]);
	ft_lstadd_front(lst, ft_lstnew(new));
	return (0);
}

int	add_cylindre(char **i, t_list **lst)
{
	t_cylindre	*new;
	t_point		norm;
	t_space		base;
	t_colors	c;
	t_plane		copy;

	if (!i[1] || !i[2] || !i[3] || !i[4] || !i[5] || !i[6] || !i[7]
		|| !i[8] || !i[9] || !i[10] || !i[11] || i[12] || !lst)
		return (-1);
	point_create(i[4], i[5], i[6], &(norm));
	if (norm.x * norm.x + norm.y * norm.y + norm.z * norm.z > 1)
		return (-1);
	new = malloc(sizeof(t_cylindre));
	if (!new || add_colors(atoi(i[9]), atoi(i[10]), atoi(i[11]), &c) == -1)
		return (-1);
	base = get_cam_space(norm);
	new->height = ft_atof(i[8]);
	create_plane(&copy, i + 1, base, c);
	create_circle(&(new->bottom), copy, ft_atof(i[7]) / 2);
	copy.start = add_v(copy.start, scale_v(copy.norm, new->height));
	create_circle(&(new->top), copy, new->bottom.radius);
	new->color = c;
	ft_lstadd_front(lst, ft_lstnew(new));
	return (0);
}

int	add_triangle(char **i, t_list **lst)
{
	t_triangle	*new;
	t_space		base;
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
	base.v = less_v(new->second, new->first);
	base.w = less_v(new->third, new->first);
	base.u = normalize(prod_vect(base.v, base.w));
	create_plane(&(new->plane), i + 1, base, c);
	create_inv_vect(base.v, base.w, &(new->inv_u), &(new->inv_v));
	ft_lstadd_front(lst, ft_lstnew(new));
	return (0);
}
