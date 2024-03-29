/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   windowmanager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmarecha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 13:47:29 by bmarecha          #+#    #+#             */
/*   Updated: 2020/07/15 17:11:41 by bmarecha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

#define EXIT_KEY 65307
#define D_KEY 100
#define A_KEY 97
#define W_KEY 119
#define S_KEY 115
#define Z_KEY 122
#define Q_KEY 113
#define E_KEY 101
#define LEFT_KEY 65361
#define UP_KEY 65362
#define DOWN_KEY 65364
#define RIGHT_KEY 65363
#define CAM_KEY 99

int	keypress_2(int keycode, t_scene *scene, t_camera *next)
{
	if (keycode == UP_KEY)
		next->base = rotationfull(next->base, M_PI / 10.0, 2);
	else if (keycode == LEFT_KEY)
		next->base = rotationfull(next->base, M_PI / -10.0, 1);
	else if (keycode == RIGHT_KEY)
		next->base = rotationfull(next->base, M_PI / 10.0, 1);
	else if (keycode == DOWN_KEY)
		next->base = rotationfull(next->base, M_PI / -10.0, 2);
	else if (keycode == CAM_KEY)
		change_cam(&(scene->pov), scene->cams);
	else
		return (0);
	return (1);
}

int	win_keypress(int keycode, void *param)
{
	t_scene		*scene;
	t_camera	*next;

	scene = param;
	if (keycode == EXIT_KEY)
		exit_prog(scene);
	next = scene->pov;
	if (keycode == Z_KEY)
		next->place = translation(next->place, 1.0, 0);
	else if (keycode == Q_KEY)
		next->place = translation(next->place, -1.0, 1);
	else if (keycode == D_KEY)
		next->place = translation(next->place, 1.0, 1);
	else if (keycode == S_KEY)
		next->place = translation(next->place, -1.0, 0);
	else if (keycode == A_KEY)
		next->place = translation(next->place, -1.0, 2);
	else if (keycode == E_KEY)
		next->place = translation(next->place, 1.0, 2);
	else if (!keypress_2(keycode, scene, next))
		return (0);
	calculate(scene);
	draw(scene);
	return (0);
}

void	window_destroy(t_scene *scene)
{
	if (scene->wink)
	{
		mlx_destroy_window(scene->mlink, scene->wink);
		mlx_destroy_display(scene->mlink);
		free(scene->mlink);
	}
	scene_free(scene);
}

int	window_start2(t_scene *scene, int save)
{
	scene->img = malloc(sizeof(t_image));
	if (!scene->img)
		return (-1);
	mlx_clear_window(scene->mlink, scene->wink);
	scene->img->data = mlx_get_data_addr(scene->ilink, &(scene->img->sizepix),
			&(scene->img->sizeline), &(scene->img->endian));
	calculate(scene);
	if (save)
		return (export_bmp("miniRT_save.bmp", scene));
	draw(scene);
	mlx_loop_hook(scene->wink, draw, scene);
	mlx_key_hook(scene->wink, win_keypress, scene);
	mlx_hook(scene->wink, 33, 0, exit_prog, scene);
	mlx_hook(scene->wink, 12, (1L << 15), draw, scene);
	mlx_loop(scene->mlink);
	return (EXIT_SUCCESS);
}

int	window_start(t_scene *scene, int save)
{
	int	display_res[2];

	scene->mlink = mlx_init();
	if (!scene->mlink)
		return (EXIT_FAILURE);
	mlx_get_screen_size(scene->mlink, display_res, display_res + 1);
	if (display_res[0] < scene->xsize)
		scene->xsize = display_res[0];
	if (display_res[1] < scene->ysize)
		scene->ysize = display_res[1];
	scene->wink = mlx_new_window(scene->mlink,
			scene->xsize, scene->ysize, "RT");
	scene->ilink = mlx_new_image(scene->mlink, scene->xsize, scene->ysize);
	if (!scene->wink || !scene->ilink)
		return (EXIT_FAILURE);
	if (window_start2(scene, save) == -1)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
