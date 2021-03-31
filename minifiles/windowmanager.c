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
#define CAM_KEY 100

int	win_keypress(int keycode, void *param)
{
	t_scene		*scene;
	char		*c;
	static int	i = 0;
	t_camera	*next;

	c = ft_itoa(keycode);
	scene = param;
	if (keycode == EXIT_KEY)
	{
		free(c);
		exit_prog(scene);
		return (1);
	}
	else if (keycode == CAM_KEY)
	{
		i++;
		if (i >= ft_lstsize(scene->cams))
			i = 0;
		next = (t_camera *)ft_lstget(scene->cams, i);
		if (next)
		{
			scene->pov = next;
			calculate(scene);
			draw(scene);
		}
		else
			printf("no cams available\n");
	}
	else
		printf("Keycode : %s, cam n°%d, posx %f\n", c, i, scene->pov->place.x);
	free(c);
	return (0);
}

int	exit_prog(t_scene *scene)
{
	mlx_destroy_image(scene->mlink, scene->ilink);
	window_destroy(scene);
	exit(0);
	return (1);
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
	scene_free(scene);
}

int	window_start(t_scene *scene)
{
	scene->mlink = mlx_init();
	if (!scene->mlink)
		return (EXIT_FAILURE);
	scene->wink = mlx_new_window(scene->mlink, scene->xsize, scene->ysize, "Tests");
	scene->ilink = mlx_new_image(scene->mlink, scene->xsize, scene->ysize);
	if (!scene->wink || !scene->ilink)
		return (EXIT_FAILURE);
	calculate(scene);
	draw(scene);
	window_run(scene);
	return (EXIT_SUCCESS);	
}
