/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   windowmanager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmarecha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 13:47:29 by bmarecha          #+#    #+#             */
/*   Updated: 2020/07/13 18:50:46 by bmarecha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int		win_changecam(int keycode, void *param)
{
	t_scene		*scene;
	char		*c;
	static int 	i = 0;

	i++;
	c = ft_itoa(keycode);
	scene = param;
	if (keycode == 27)
		return (0);
	mlx_string_put(scene->mlink, scene->wink, 10, 100 + 15 * i, 255255255, c);
	free(c);
	return (1);
}

void	window_run(t_scene *scene)
{
	while (mlx_key_hook(scene->wink, &win_changecam, scene))
		printf("Happy face :)\n");
	return ;
}

int		window_start(t_scene *scene)
{
	if (!(scene->mlink = mlx_init())
				|| !(scene->wink = mlx_new_window(scene->mlink, scene->xsize,
				scene->ysize, "TestWindow")))
		return (EXIT_FAILURE);
	mlx_string_put(scene->mlink, scene->wink, 10, 50, 243224050, "Enter Text :");
	window_run(scene);
	mlx_loop(scene->mlink);
	return (EXIT_SUCCESS);	
}
