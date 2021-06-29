#include "minirt.h"

t_point	rotation(t_point vect, double angle, int axis)
{
	t_point	res;
	double	co;
	double	si;

	co = cos(angle);
	si = sin(angle);
	if (axis == 1)
	{
		res.x = co * vect.x - si * vect.y;
		res.y = si * vect.x + co * vect.y;
		res.z = vect.z;
	}
	else if (axis == 2)
	{
		res.y = vect.y;
		res.x = co * vect.x - si * vect.z;
		res.z = si * vect.x + co * vect.z;
	}
	else if (axis == 3)
	{
		res.x = vect.x;
		res.y = co * vect.y - si * vect.z;
		res.z = si * vect.y + co * vect.z;
	}
	return (res);
}

t_point	translation(t_point vect, double shift, int axis)
{
	t_point	res;

	res = vect;
	if (axis == 0)
		res.x += shift;
	else if (axis == 1)
		res.y += shift;
	else if (axis == 2)
		res.z += shift;
	printf("New pos : (%f,%f,%f)\n", res.x, res.y, res.z);
	return (res);
}

t_space	rotationfull(t_space base, double angle, int axis)
{
	t_space	res;
	double	co;
	double	si;

	if (axis == 1)
	{
		res.u = rotation(base.u, angle, axis);
		res.v = rotation(base.v, angle, axis);
		res.w = rotation(base.w, angle, axis);
	}
	else if (axis == 2)
	{	
		co = cos(angle);
		si = sin(angle);
		res.v = base.v;
		res.u = less_v(scale_v(base.u, co), scale_v(base.w, si));
		res.w = add_v(scale_v(base.u, si), scale_v(base.w, co));
	}
	return (res);
}
