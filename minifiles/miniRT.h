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

void printtest(void);

#endif
