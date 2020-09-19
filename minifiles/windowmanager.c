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

int			win_changecam(int keycode, void *param)
{
	t_scene		*scene;
	char		*c;
	static int 	i = 0;

	i++;
	c = ft_itoa(keycode);
	scene = param;
	if (keycode == 53)
	{
		free(c);
		exit_prog(scene);
		return (1);
	}
	mlx_string_put(scene->mlink, scene->wink, 10, 100 + 15 * i, 255255255, c);
	free(c);
	return (0);
}

int			exit_prog(t_scene *scene)
{
	window_destroy(scene);
	exit(0);
	return (1);
}

void		window_run(t_scene *scene)
{
	//mlx_loop_hook(scene->wink, draw, scene);
	mlx_key_hook(scene->wink, &win_changecam, scene);
	mlx_hook(scene->wink, 17, (1L << 17), exit_prog, scene);
	mlx_loop(scene->mlink);
}

void		window_destroy(t_scene *scene)
{
	if (!scene->window_supp && scene->wink)
		mlx_destroy_window(scene->mlink, scene->wink);
	scene_free(scene);
}

int			window_start(t_scene *scene)
{
	if (!(scene->mlink = mlx_init())
				|| !(scene->wink = mlx_new_window(scene->mlink, scene->xsize,
				scene->ysize, "Tests")))
		return (EXIT_FAILURE);
	mlx_string_put(scene->mlink, scene->wink, 10, 50, 243224050, "Enter Text :");
	window_run(scene);
	return (EXIT_SUCCESS);	
}
