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
	printf("dir : (%.2f, %.2f, %.2f)\n", res.x, res.y, res.z);
	return (res);
}

t_point		translation(t_point vect, double shift, int axis)
{
	t_point	res;

	res = vect;
	res.y = res.y + shift * axis;
	res.z = res.z + shift * (axis - 1);
	return (res);
}
