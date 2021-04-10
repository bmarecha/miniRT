#include "minirt.h"
int g_i = 0;

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
	double	y_shift;
	double	z_shift;

       	angle = tan(scene->pov->fov * M_PI / 360);	
	x.origin = scene->pov->place;
	z_shift = (-2.0 / (double)scene->ysize) * (pixieme / scene->xsize) + 1;
	y_shift = angle * (1 - (2 * (double)(pixieme % scene->xsize)) / ((double)scene->xsize));
	x.dir = space.u;
	x.dir = add_v(scale_v(space.v, y_shift), x.dir);
	x.dir = add_v(scale_v(space.w, z_shift), x.dir);
/*	if (pixieme % scene->xsize == 0)
	{
		print_point(x.dir);
		printf("%f, %f || 0\n", angle, y_shift);
	}
	if (pixieme % scene->xsize == 500)
	{
		print_point(x.dir);
		printf("%f, %f || 500\n", angle, y_shift);
	}
*/	res = ray_color(x, scene);
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
	print_point(space.u);
	print_point(space.v);
	print_point(space.w);
	while (i < scene->ysize * img.sizeline / 4)
	{
		color = get_pix_color(i, scene, space);
		assign_color(color, img.data + i * 4, img.sizepix);
		i += 1;
	}
	scene->changed = 1;
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
