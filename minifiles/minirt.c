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

int		complete_read_line(char **infos, t_scene *scene)
{
	int res;

	res = -1;
	if (!ft_strcmp(infos[0], "cy"))
		res = add_cylindre(infos, scene);
	else if (!ft_strcmp(infos[0], "tr"))
		res = add_triangle(infos, scene);
	return (res);
}

void	complete_free(char **array)
{
	int i;

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

int		read_line(char **infos, t_scene *scene)
{
	int res;

	if (!infos)
		return (-1);
	if (infos[0] == 0)
		res = 0;
	else if (!ft_strcmp(infos[0], "R") && scene->xsize == 0)
		res = add_sizes(infos, scene);
	else if (!ft_strcmp(infos[0], "A") && !scene->ambiantdef)
		res = add_ambiantlight(infos, scene);
	else if (!ft_strcmp(infos[0], "c"))
		res = add_camera(infos, scene);
	else if (!ft_strcmp(infos[0], "l"))
		res = add_light(infos, scene);
	else if (!ft_strcmp(infos[0], "sp"))
		res = add_sphere(infos, scene);
	else if (!ft_strcmp(infos[0], "pl"))
		res = add_plane(infos, scene);
	else if (!ft_strcmp(infos[0], "sq"))
		res = add_square(infos, scene);
	else
		res = complete_read_line(infos, scene);
	complete_free(infos);
	printf("%d\n",res);
	return (res);
}

int		read_file(int fd, t_scene *scene)
{
	int		res;
	char	**line;
	char	**infos;

	line = malloc(1);
	while ((res = get_next_line(fd, line)) == 1)
	{
		printf("[%d] ||| %s\n", res, *line);
		infos = mini_split(*line, "\n\t\v ,");
		if (read_line(infos, scene) == -1)
		{
			free(*line);
			free(line);
			close(fd);
			return (-1);
		}
		free(*line);
	}
	free(line);
	close(fd);
	if (scene->xsize <= 0 || scene->ysize <= 0 || !scene->cams)
		return (-1);
	return (0);
}

int		main(int argc, char **argv)
{
	t_scene	*scene;

	if (argc <= 1)
	{
		printf("Map Missing");
		return (0);
	}
	if (!(scene = malloc(sizeof(t_scene))))
		return (-1);
	ft_bzero(scene, sizeof(*scene));
	if (read_file(open(argv[1], O_RDONLY) , scene) == -1)
	{
		printf("Map error");
		scene_free(scene);
		free(scene);
		return (0);
	}
	printf("%d\n%d\n%f\n", scene->xsize, scene->ysize,
		scene->ambiantr);
	window_start(scene);
	window_destroy(scene);
	free(scene);
	return (0);
}
