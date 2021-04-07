#include "minirt.h"

void	assign_color(int color, char *pixel, int sizepix)
{
	int	i;
	int	j;
	int	temp;

	i = -1;
	while (++i < sizepix / 8)
	{
		temp = color;
		j = i;
		while (j-- > 0)
			temp /= 1000;
		pixel[i] = (char)(temp % 1000);
	}
}

int	get_pix_color(int pixieme, t_scene *scene, t_space space)
{
	int	res;
	double	angle;
	t_ray	x;
	double	x_shift;
	double	y_shift;
	double	z_shift;

       	angle = scene->pov->fov - ((double)scene->pov->fov) / 2.0;
	angle = angle * (M_PI / 180.0);
	x.origin = scene->pov->place;
	z_shift = (-2.0 / scene->ysize) * (pixieme / scene->ysize) + 1;
	y_shift = sin(angle * ((double)(pixieme % scene->xsize)) / ((double)scene->xsize));
	x_shift = cos(angle);
	x.dir = scale_v(space.u, x_shift);
	x.dir = add_v(scale_v(space.v, y_shift), x.dir);
	x.dir = add_v(scale_v(space.w, z_shift), x.dir);
	res = ray_color(x, scene);
	return (res);
}

int	calculate(t_scene *scene)
{
	int		i;
	int		color;
	t_space		space;
	t_image		img;

	i = 0;
	img = *(scene->img);
	space = scene->pov->base;
	while (i < scene->ysize * img.sizeline / 4)
	{
		color = get_pix_color(i, scene, space);
		assign_color(color, img.data + i * 4, img.sizepix);
		i += 1;
	}
	scene->changed = 1;
	printf("Calculated, %d, %d\n", img.sizepix, img.sizeline);
	return (1);
}

int	draw(t_scene *scene)
{
	printf("TryDraw");
	if (!scene->changed || !scene->ilink)
		return (1);
	printf("drawing\n");
	mlx_put_image_to_window(scene->mlink, scene->wink, scene->ilink, 0, 0);
	scene->changed = 0;
	return (1);
}
