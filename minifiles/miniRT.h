/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmarecha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 17:27:17 by bmarecha          #+#    #+#             */
/*   Updated: 2020/07/06 18:55:38 by bmarecha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define  MINIRT_H
# include <stdio.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct	s_point
{
	float x;
	float y;
	float z;
}				t_point;

typedef	struct s_colors
{
	int r;
	int g;
	int b;
}				t_colors;

typedef struct	s_camera
{
	t_point place;
	t_point view;

	int fov;
}				t_camera;

typedef	struct	s_scene
{
	int xsize;
	int ysize;
	float ambiantr;
	t_colors ambiantc;

	t_camera *cams;
}				t_scene;

char			**ft_split(char *str, char *charset);
int				ft_strcmp(char *a, char *b);
int				add_sphere(char **infos, t_scene *scene);
int				add_plane(char **infos, t_scene *scene);
int				add_square(char **infos, t_scene *scene);
int				add_cylindre(char **infos, t_scene *scene);
int				add_triangle(char **infos, t_scene *scene);
int				add_camera(char **infos, t_scene *scene);
int				add_light(char **infos, t_scene *scene);
int				add_ambiantlight(char **infos, t_scene *scene);
int				add_sizes(char **infos, t_scene *scene);
int				add_colors(int r, int g, int b, t_colors *colors);


#endif
