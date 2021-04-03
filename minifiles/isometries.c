#include "minirt.h"

t_point		rotation(t_point vect, double angle, int axis)
{
	t_point	res;

	if (axis == 1)
	{
		res.x = cos(angle) * vect.x - sin(angle) * vect.y;
		res.y = sin(angle) * vect.x + cos(angle) * vect.y;
	}
	else if (axis == 2)
	{
		res.x = cos(angle) * vect.x - sin(angle) * vect.z;
		res.z = sin(angle) * vect.x + cos(angle) * vect.z;
	}
	return (res);
}
