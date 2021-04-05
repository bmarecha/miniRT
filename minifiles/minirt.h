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
# include <math.h>
# include "libft.h"
# include "mlx.h"
# include "forms.h"
# include "raysmaths.h"

typedef struct s_camera
{
	t_point		place;
	t_point		view;

	int			fov;
}				t_camera;

typedef struct s_light
{
	t_point		place;
	t_colors	color;
	float		rate;
}				t_light;

typedef	struct s_scene
{
	int			xsize;
	int			ysize;
	float		ambiantr;
	t_colors	ambiantc;
	int			ambiantdef;
	void		*wink;
	void		*mlink;
	void		*ilink;
	int			window_supp;

	t_list		*cams;
	t_list		*lights;
	t_list		*spheres;
	t_list		*planes;
	t_list		*squares;
	t_list		*cylindres;
	t_list		*triangles;
	t_camera	*pov;
	int		changed;
	
}				t_scene;

float				ft_atof(char *str);
char				**mini_split(char *str, char *charset);
int				ft_strcmp(char *a, char *b);
int				add_camera(char **infos, t_scene *scene);
int				add_light(char **infos, t_scene *scene);
int				add_ambiantlight(char **infos, t_scene *scene);
int				add_sizes(char **infos, t_scene *scene);
int				add_colors(int r, int g, int b, t_colors *colors);
int				array_length(t_camera **array);
void				scene_free(t_scene *scene);
int				window_start(t_scene *scene, int save);
void				window_destroy(t_scene *scene);
int				exit_prog(t_scene *scene);
int				calculate(t_scene *scene);
int				draw(t_scene *scene);
t_colors			ray_color(t_ray r, t_scene *scene);
t_point				rotation(t_point vect, double angle, int axis);
t_point				translation(t_point vect, double shift, int axis);
void				error_exit(int error);
void				export_bmp(char *file, t_scene *scene);

#endif
