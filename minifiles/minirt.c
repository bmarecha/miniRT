/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmarecha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/11 13:32:13 by bmarecha          #+#    #+#             */
/*   Updated: 2020/07/15 16:58:01 by bmarecha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "../gnl/get_next_line.h"

int	complete_read_line(char **infos, t_scene *scene)
{
	int	res;

	res = -1;
	if (!ft_strcmp(infos[0], "cy"))
		res = add_cylindre(infos, &(scene->cylindres));
	else if (!ft_strcmp(infos[0], "tr"))
		res = add_triangle(infos, &(scene->triangles));
	return (res);
}

void	complete_free(char **array)
{
	int	i;

	i = 0;
	if (!array)
		return ;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}

int	read_line(char **infos, t_scene *scene)
{
	int	res;

	if (!infos)
		return (-1);
	if (infos[0] == 0)
		res = 0;
	else if (!ft_strcmp(infos[0], "R") && scene->xsize == 0)
		res = add_sizes(infos, scene);
	else if (!ft_strcmp(infos[0], "A") && !scene->ambiantdef)
		res = add_ambiantlight(infos, scene);
	else if (!ft_strcmp(infos[0], "C"))
		res = add_camera(infos, scene);
	else if (!ft_strcmp(infos[0], "L"))
		res = add_light(infos, scene);
	else if (!ft_strcmp(infos[0], "sp"))
		res = add_sphere(infos, &(scene->spheres));
	else if (!ft_strcmp(infos[0], "pl"))
		res = add_plane(infos, &(scene->planes));
	else if (!ft_strcmp(infos[0], "sq"))
		res = add_square(infos, &(scene->squares));
	else
		res = complete_read_line(infos, scene);
	complete_free(infos);
	return (res);
}

int	read_file(int fd, t_scene *scene)
{
	char	*line;
	char	**infos;

	while (get_next_line(fd, &line) == 1)
	{
		infos = mini_split(line, "\n\t\v ,");
		free(line);
		if (read_line(infos, scene) == -1)
		{
			close(fd);
			return (-1);
		}
	}
	free(line);
	close(fd);
	if (!scene->cams)
		return (-1);
	if (scene->xsize == 0 || scene->ysize == 0)
	{
		scene->xsize = 1920;
		scene->ysize = 1080;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_scene	*scene;

	if (argc <= 1)
		error_exit(-2);
	scene = malloc(sizeof(t_scene));
	if (!scene)
		return (-1);
	ft_bzero(scene, sizeof(*scene));
	if (read_file(open(argv[1], O_RDONLY), scene) == -1)
	{
		scene_free(scene);
		error_exit(-3);
	}
	if (argc == 3 && !ft_strcmp(argv[2], "-save"))
		window_start(scene, 1);
	else
		window_start(scene, 0);
	window_destroy(scene);
	return (0);
}
