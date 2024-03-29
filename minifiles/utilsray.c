#include "minirt.h"

void	print_point(t_point p)
{
	printf("(%f, %f, %f)\n", p.x, p.y, p.z);
}

double	normv(t_point u)
{
	return (sqrt(prod_scal(u, u)));
}

t_point	normalize(t_point u)
{
	double	norm;
	t_point	res;

	norm = normv(u);
	res.x = u.x / norm;
	res.y = u.y / norm;
	res.z = u.z / norm;
	return (res);
}

t_space	get_cam_space(t_point direction)
{
	t_space	res;

	res.u = normalize(direction);
	if (res.u.x != 0 || res.u.y != 0)
	{
		res.v.x = res.u.y;
		res.v.y = -res.u.x;
	}
	else
	{
		res.v.x = 0;
		res.v.y = res.u.z;
	}
	res.v.z = 0;
	res.v = normalize(res.v);
	res.w = prod_vect(res.u, res.v);
	res.w = normalize(res.w);
	return (res);
}
