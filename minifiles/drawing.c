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

void	showbits(char x)
{
	int	i;

	i = sizeof(char) * 8 - 1;
 	while (i >= 0)
	{
		putchar(x & (1 << i) ? '1' : '0');
		i--;
	}
	printf(" : ");
}

typedef struct s_space {
	t_point	u;
	t_point	v;
	t_point	w;
}		t_space;

t_space	get_cam_space(t_scene *scene)
{
	t_space	res;
	t_point	zaxis;
	t_point	normedv;

	printf("Getting the cam space\n");
	zaxis.x = 0;
	zaxis.y = 0;
	zaxis.z = 1;
	res.u = scene->pov->view;
	res.v = prod_vect(res.u, zaxis);
	normedv = scale_vect(res.v, 1 / prod_scal(res.v, res.v));
	res.w = prod_vect(res.u, normedv);
	return (res);
}

int	get_pix_color(int pixieme, t_scene *scene, t_space space)
{
	int	res;
	double	angle;
	t_ray	x;
	double	x_shift;
	double	y_shift;
	double	z_shift;

	angle = ((float)(pixieme % scene->xsize) / (float)scene->xsize);
       	angle = angle * scene->pov->fov - scene->pov->fov / 2;
	x.origin = scene->pov->place;
	z_shift = (2 / scene->ysize) * (pixieme % scene->ysize) - 1;
	y_shift = (float)(2 / scene->xsize) * angle;
	x_shift = 1 - (scene->pov->fov / 180);
	x.dir = scale_vect(space.u, x_shift);
	x.dir = add_vect(scale_vect(space.v, y_shift), x.dir);
	x.dir = add_vect(scale_vect(space.w, z_shift), x.dir);
	res = ray_color(x, scene);
	return (res);
}

int	calculate(t_scene *scene)
{
	int		sizepix;
	int		sizeline;
	int		endian;
	char		*tab;
	int		i;
	int		color;
	t_space		space;

	printf("Getting image data\n");
	tab = mlx_get_data_addr(scene->ilink, &sizepix, &sizeline, &endian);
	i = 0;
	space = get_cam_space(scene);
	while (i < scene->ysize * sizeline / 4)
	{
		color = get_pix_color(i, scene, space);
		assign_color(color, tab + i * 4, sizepix);
		if (i == 0)
		{
			showbits(tab[i]);
			printf(" %d\n", scene->ambiantc);
		}
		i += 1;
	}
	scene->changed = 1;
	printf("Calculated, %d, %d\n", sizepix, sizeline);
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
