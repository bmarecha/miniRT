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
#define LEFT_KEY 65361
#define UP_KEY 65362
#define DOWN_KEY 65364
#define RIGHT_KEY 65363
#define CAM_KEY 99

void	change_cam(t_camera **pov, t_list *cams)
{
	t_camera *next;
	static int i = 0;

	i++;
	if (i >= ft_lstsize(cams))
		i = 0;
	next = (t_camera *)ft_lstget(cams, i);
	if (next)
	{
		*pov = next;
		//printf("Changed to camera n°%d\n", i);
	}
	else
		printf("no cams available\n");
}

int	win_keypress(int keycode, void *param)
{
	t_scene		*scene;
//	char		*c;
	t_camera	*next;

//	c = ft_itoa(keycode);
	scene = param;
	if (keycode == EXIT_KEY)
		exit_prog(scene);
	next = scene->pov;
	if (keycode == Z_KEY)
		next->place = translation(next->place, 1.0, 0);
	else if (keycode == Q_KEY)
		next->place = translation(next->place, 1.0, 1);
	else if (keycode == D_KEY)
		next->place = translation(next->place, -1.0, 1);
	else if (keycode == S_KEY)
		next->place = translation(next->place, -1.0, 0);
	else if (keycode == UP_KEY)
		next->view = rotation(next->view, M_PI / 10.0, 2);
	else if (keycode == LEFT_KEY)
		next->view = rotation(next->view, M_PI / 10.0, 1);
	else if (keycode == RIGHT_KEY)
		next->view = rotation(next->view, M_PI / -10.0, 1);
	else if (keycode == DOWN_KEY)
		next->view = rotation(next->view, M_PI / -10.0, 2);	
	else if (keycode == CAM_KEY)
		change_cam(&next, scene->cams);
	else {
		printf("Keycode : %d, posx %f\n", keycode, scene->pov->place.x);
		return (0);
	}
	calculate(scene);
	draw(scene);
	return (0);
}

void	window_run(t_scene *scene)
{
	mlx_loop_hook(scene->wink, draw, scene);
	mlx_key_hook(scene->wink, win_keypress, scene);
	mlx_hook(scene->wink, 17, (1L << 17), exit_prog, scene);
	mlx_loop(scene->mlink);
}

void	window_destroy(t_scene *scene)
{
	if (!scene->window_supp && scene->wink)
		mlx_destroy_window(scene->mlink, scene->wink);
	mlx_destroy_display(scene->mlink);
	scene_free(scene);
}

int	window_start(t_scene *scene, int save)
{
	scene->mlink = mlx_init();
	if (!scene->mlink)
		return (EXIT_FAILURE);
	scene->wink = mlx_new_window(scene->mlink, scene->xsize, scene->ysize, "Tests");
	scene->ilink = mlx_new_image(scene->mlink, scene->xsize, scene->ysize);
	if (!scene->wink || !scene->ilink)
		return (EXIT_FAILURE);
	mlx_clear_window(scene->mlink, scene->wink);
	calculate(scene);
	if (save)
		export_bmp("miniRT_save" ,scene);
	draw(scene);
	mlx_loop_hook(scene->wink, draw, scene);
	mlx_key_hook(scene->wink, win_keypress, scene);
	mlx_hook(scene->wink, 17, (1L << 17), exit_prog, scene);
	mlx_loop(scene->mlink);
	return (EXIT_SUCCESS);	
}
