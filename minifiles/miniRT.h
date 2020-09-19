/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmarecha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/11 13:33:06 by bmarecha          #+#    #+#             */
/*   Updated: 2020/07/15 17:08:51 by bmarecha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H
# include <stdio.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include "libft.h"
# include "mlx.h"

typedef struct	s_point
{
	float		x;
	float		y;
	float		z;
}				t_point;

typedef	struct	s_colors
{
	int			r;
	int			g;
	int			b;
}				t_colors;

typedef struct	s_camera
{
	t_point		place;
	t_point		view;

	int			fov;
}				t_camera;

typedef	struct	s_light
{
	t_point		place;
	t_colors	color;
	float		rate;
}				t_light;

typedef	struct	s_sphere
{
	t_point		center;
	float		diameter;
	t_colors	color;
}				t_sphere;

typedef	struct	s_plane
{
	t_point		start;
	t_point		way;
	t_colors	color;
}				t_plane;

typedef	struct	s_square
{
	t_point		start;
	t_point		way;
	float		height;
	t_colors	color;
}				t_square;

typedef	struct	s_cylindre
{
	t_point		start;
	t_point		way;
	float		diameter;
	float		height;
	t_colors	color;
}				t_cylindre;

typedef	struct	s_triangle
{
	t_point		first;
	t_point		second;
	t_point		third;
	t_colors	color;
}				t_triangle;

typedef	struct	s_scene
{
	int			xsize;
	int			ysize;
	float		ambiantr;
	t_colors	ambiantc;
	int			ambiantdef;
	void		*wink;
	void		*mlink;
	int			window_supp;

	t_list		*cams;
	t_list		*lights;
	t_list		*spheres;
	t_list		*planes;
	t_list		*squares;
	t_list		*cylindres;
	t_list		*triangles;
}				t_scene;

float			ft_atof(char *str);
char			**mini_split(char *str, char *charset);
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
int				array_length(t_camera **array);
void			point_create(char *x, char *y, char *z, t_point *point);
void			scene_free(t_scene *scene);
int				window_start(t_scene *scene);
void			window_destroy(t_scene *scene);
int				exit_prog(t_scene *scene);

#endif
