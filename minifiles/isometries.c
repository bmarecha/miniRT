#include "minirt.h"

t_point		rotation(t_point vect, double angle, int axis)
{
	t_point	res;

	if (axis == 1)
	{
		res.x = cos(angle) * vect.x - sin(angle) * vect.y;
		res.y = sin(angle) * vect.x + cos(angle) * vect.y;
		res.z = vect.z;
	}
	else if (axis == 2)
	{
		res.y = vect.y;
		res.x = cos(angle) * vect.x - sin(angle) * vect.z;
		res.z = sin(angle) * vect.x + cos(angle) * vect.z;
	}
	else if (axis == 3)
	{
		res.x = vect.x;
		res.y = cos(angle) * vect.y - sin(angle) * vect.z;
		res.z = sin(angle) * vect.y + cos(angle) * vect.z;
	}
	return (res);
}

t_point		translation(t_point vect, double shift, int axis)
{
	t_point	res;

	res = vect;
	if (axis == 0)
		res.x += shift;
	else if (axis == 1)
		res.y += shift;
	else if (axis == 2)
		res.z += shift;
	return (res);
}

t_space		rotationfull(t_space base, double angle, int axis)
{
	t_space res;
	double	co;
	double	si;

	co = cos(angle);
	si = sin(angle);
	if (axis == 1)
	{
		res.u = less_v(scale_v(base.u, co), scale_v(base.v, si));
		res.v = add_v(scale_v(base.u, si), scale_v(base.v, co));
		res.w = base.w;
	}
	else if (axis == 2)
	{
		res.v = base.v;
		res.u = less_v(scale_v(base.u, co), scale_v(base.w, si));
		res.w = add_v(scale_v(base.u, si), scale_v(base.w, co));
	}
	else if (axis == 3)
	{
		res.u = base.u;
		res.v = less_v(scale_v(base.v, co), scale_v(base.w, si));
		res.w = add_v(scale_v(base.v, si), scale_v(base.w, co));
	}
	return (res);
}
