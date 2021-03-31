#include "minirt.h"

float	prod_scal(t_point u, t_point v)
{
	return (u.x * v.x + u.y * v.y + u.z * v.z);
}

t_point	prod_vect(t_point u, t_point v)
{	
	t_point	w;

	w.x = u.y * v.z - u.z * v.y;
	w.y = u.z * v.x - u.x * v.z;
	w.z = u.x * v.y - u.y * v.x;
	return (w);
}

t_point	scale_vect(t_point v, float l)
{
	t_point	w;

	w.x = v.x * l;
	w.y = v.y * l;
	w.z = v.z * l;
	return (w);
}

t_point	add_vect(t_point v, t_point u)
{
	t_point	w;

	w.x = v.x + u.x;
	w.y = v.y + u.y;
	w.z = v.z + u.z;
	return (w);
}

t_point	less_vect(t_point v, t_point u)
{
	t_point	w;

	w.x = v.x - u.x;
	w.y = v.y - u.y;
	w.z = v.z - u.z;
	return (w);
}
