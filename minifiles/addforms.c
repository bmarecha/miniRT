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

int	add_sphere(char **infos, t_list **lst)
{
	t_sphere	*new;

	if (!infos[1] || !infos[2] || !infos[3] || !infos[4] || !infos[5]
		|| !infos[6] || !infos[7] || infos[8] || !lst)
		return (-1);
	new = malloc(sizeof(t_sphere));
	if (!new)
		return (-1);
	if (add_colors(atoi(infos[5]), atoi(infos[6]), atoi(infos[7]),
			&(new->color)) == -1)
		return (-1);
	point_create(infos[1], infos[2], infos[3], &(new->center));
	new->diameter = ft_atof(infos[4]);
	if (*lst)
		ft_lstadd_front(lst, ft_lstnew(new));
	else
		*lst = ft_lstnew(new);
	return (0);
}

int	add_plane(char **infos, t_list **lst)
{
	t_plane	*new;

	if (!infos[1] || !infos[2] || !infos[3] || !infos[4] || !infos[5] || !lst
		|| !infos[6] || !infos[7] || !infos[8] || !infos[9] || infos[10])
		return (-1);
	new = malloc(sizeof(t_plane));
	if (!new)
		return (-1);
	point_create(infos[4], infos[5], infos[6], &(new->way));
	if (!(new->way.x * new->way.x > 1 || new->way.y * new->way.y > 1
			|| new->way.z * new->way.z > 1))
	{
		free(new);
		return (-1);
	}
	if (add_colors(atoi(infos[7]), atoi(infos[8]), atoi(infos[9]),
			&(new->color)) == -1)
		return (-1);
	point_create(infos[1], infos[2], infos[3], &(new->start));
	if (*lst)
		ft_lstadd_front(lst, ft_lstnew(new));
	else
		*lst = ft_lstnew(new);
	return (0);
}

int	add_square(char **infos, t_list **lst)
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
