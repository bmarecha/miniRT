#include "minirt.h"

void	change_cam(t_camera **pov, t_list *cams)
{
	t_camera	*next;
	static int	s_i = 0;

	s_i++;
	if (s_i >= ft_lstsize(cams))
		s_i = 0;
	next = (t_camera *)ft_lstget(cams, s_i);
	if (next)
	{
		*pov = next;
	}
}

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

int	get_pix_color(int col, int row, t_scene *scene, t_space space)
{
	double	img_ratio;
	double	angle;
	t_ray	x;
	double	y_shift;
	double	z_shift;

	img_ratio = ((double)scene->ysize) / (double)scene->xsize;
	angle = tan(scene->pov->fov * M_PI / 360);
	x.origin = scene->pov->place;
	z_shift = (1 - (2.0 * (double)row / (double)scene->ysize));
	z_shift *= img_ratio * angle * -1;
	y_shift = angle * (1 - (2 * (double)col) / ((double)scene->xsize));
	x.dir = space.u;
	x.dir = add_v(scale_v(space.v, y_shift), x.dir);
	x.dir = add_v(scale_v(space.w, z_shift), x.dir);
	return (cotoi(ray_color(x, scene)));
}

int	calculate(t_scene *scene)
{
	int		i;
	int		color;
	t_space	space;
	t_image	img;

	i = 0;
	img = *(scene->img);
	space = scene->pov->base;
	while (i < scene->ysize * scene->xsize)
	{
		color = get_pix_color(i % scene->xsize, i / scene->xsize, scene, space);
		assign_color(color, img.data + i * 4, img.sizepix);
		i += 1;
	}
	return (1);
}

int	draw(t_scene *scene)
{
	if (!scene->ilink)
		return (1);
	mlx_put_image_to_window(scene->mlink, scene->wink, scene->ilink, 0, 0);
	return (1);
}
