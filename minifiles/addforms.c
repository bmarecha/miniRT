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
	new->diameter = ft_atof(i[4]);
	ft_lstadd_front(lst, ft_lstnew(new));
	return (0);
}

int	add_plane(char **i, t_list **lst)
{
	t_plane	*new;
	t_colors color;
	t_point u; 

	if (!i[1] || !i[2] || !i[3] || !i[4] || !i[5] || !lst
		|| !i[6] || !i[7] || !i[8] || !i[9] || i[10])
		return (-1);
	new = malloc(sizeof(t_plane));
	if (!(i[4] * i[4] > 1 || i[5] * i[5] > 1 || i[6] * i[6] > 1) || !new
		|| add_colors(atoi(infos[7]), atoi(infos[8]), atoi(infos[9]),
		&(color)))
		return (-1);
	new->color = color;
// en 2d : (x, y) -> ( x - y / 2 , x + y / 2  ) and ( y + x / 2, y - x / 2 )
// en 3d : (x, y, z) -> ( , x + y + z / 3  ) and (   )
	point_create(i[4], i[5], i[6], &(new->way1));
	point_create(infos[1], infos[2], infos[3], &(new->start));
	ft_lstadd_front(lst, ft_lstnew(new));
	return (0);
}

int	add_square(char **i, t_list **lst)
{
	t_square	*new;

	if (!infos[1] || !infos[2] || !infos[3] || !infos[4] || !infos[5]
		|| !infos[6] || !infos[7] || !infos[8] || !infos[9]
		|| !infos[10] || infos[11] || !lst)
		return (-1);
	new = malloc(sizeof(t_square));
	if (!new)
		return (-1);
	if (add_colors(atoi(infos[8]), atoi(infos[9]), atoi(infos[10]),
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
	new->height = ft_atof(infos[7]);
	if (*lst)
		ft_lstadd_front(lst, ft_lstnew(new));
	else
		*lst = ft_lstnew(new);
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

int	add_triangle(char **infos, t_list **lst)
{
	t_triangle	*new;

	if (!infos[1] || !infos[2] || !infos[3] || !infos[4] || !infos[5]
		|| !infos[6] || !infos[7] || !infos[8] || !infos[9] || !lst
		|| !infos[10] || !infos[11] || !infos[12] || infos[13])
		return (-1);
	new = malloc(sizeof(t_triangle));
	if (!new)
		return (-1);
	if (add_colors(atoi(infos[10]), atoi(infos[11]), atoi(infos[12]),
			&(new->color)) == -1)
		return (-1);
	point_create(infos[1], infos[2], infos[3], &(new->first));
	point_create(infos[4], infos[5], infos[6], &(new->second));
	point_create(infos[7], infos[8], infos[9], &(new->third));
	ft_lstadd_front(lst, ft_lstnew(new));
	return (0);
}
