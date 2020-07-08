/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmarecha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 18:10:16 by bmarecha          #+#    #+#             */
/*   Updated: 2020/07/06 18:10:32 by bmarecha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"
#include "../gnl/get_next_line.h"

int read_line(char *line, t_scene *scene)
{
	char	**infos;
	int		res;

	res = -1;
	infos = ft_split(line, "\n\t ,");
	if (ft_strcmp(infos[0], "R") == 0 && scene->xsize == 0)
		res = add_sizes(infos, scene);
	if (ft_strcmp(infos[0], "A") == 0 && scene->ambiantr == 0)
		res = add_ambiantlight(infos, scene);

	free(infos);
	return (res);
}

int read_file(int fd, t_scene *scene)
{
	int res;
	char **line;
	
	line = malloc(1);
	while ((res = get_next_line(fd, line)) == 1)
	{
		printf("[%d] ||| %s\n", res, *line);
		if (read_line(*line, scene) == -1)
			return (-1);
		free(*line);
	}
	free(*line);
	free(line);
	close(fd);
	return(-1);
}

int main (int argc, char **argv)
{
	t_scene *scene;
	int fd;

	if (argc >= 0)
	{
		fd = open(argv[1], O_RDONLY);
		if ((scene = malloc(sizeof(t_scene))) == NULL)
			return (0);
		if (read_file(fd, scene) != -1)
		{
			printf("\n%d\n%d\n%d\n%d", scene->xsize, scene->ysize,
					scene->ambiantc.r, scene->ambiantc.g);
		}
		else
			printf("Map error");
		free(scene);
	}
	else
		printf("Map missing");
}
