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

# define EPSILON 0.0000001

typedef struct s_camera
{
	t_point		place;
	t_point		view;
	t_space		base;

	int			fov;
}				t_camera;

typedef struct s_light
{
	t_point		place;
	t_colors	color;
	float		rate;
}				t_light;

typedef struct s_image
{
	char	*data;
	int		sizeline;
	int		endian;
	int		sizepix;
}				t_image;

typedef struct s_scene
{
	int			xsize;
	int			ysize;
	float		ambiantr;
	t_colors	ambiantc;
	int			ambiantdef;
	void		*wink;
	void		*mlink;
	void		*ilink;

	t_list		*cams;
	t_list		*lights;
	t_list		*spheres;
	t_list		*planes;
	t_list		*squares;
	t_list		*cylindres;
	t_list		*triangles;
	t_camera	*pov;
	t_image		*img;
	int			changed;
	char		*data;	
}				t_scene;

/*
** Utils fonctions
*/

char			**mini_split(char *str, char *charset);
int				ft_strcmp(char *a, char *b);
int				array_length(t_camera **array);
void			scene_free(t_scene *scene);

t_point			rotation(t_point vect, double angle, int axis);
t_space			rotationfull(t_space base, double angle, int axis);
t_point			translation(t_point vect, double shift, int axis);

int				export_bmp(char *file, t_scene *scene);

/*
** Parsing Fonctions
*/

int				add_camera(char **infos, t_scene *scene);
int				add_light(char **infos, t_scene *scene);
int				add_ambiantlight(char **infos, t_scene *scene);
int				add_sizes(char **infos, t_scene *scene);
int				add_colors(int r, int g, int b, t_colors *colors);
t_space			get_cam_space(t_point direction);

/*
** Window Fonctions
*/

void			change_cam(t_camera **pov, t_list *cams);
int				window_start(t_scene *scene, int save);
void			window_destroy(t_scene *scene);
int				exit_prog(t_scene *scene);
int				calculate(t_scene *scene);
int				draw(t_scene *scene);
t_colors		ray_color(t_ray r, t_scene *scene);
t_colors		total_light(t_impact i, t_scene *scene);
void			error_exit(int error);

#endif
