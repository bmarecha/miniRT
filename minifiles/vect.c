#include <stdio.h>
typedef struct	s_point
{
	double		x;
	double		y;
	double		z;
}				t_point;

typedef	struct	s_triangle
{
	t_point		first;
	t_point		second;
	t_point		third;
}				t_triangle;

void	print_point(t_point p)
{
	printf("( %f, %f, %f)", p.x, p.y, p.z);
}

double	prod_scal(t_point u, t_point v)
{
	return (u.x * v.x + u.y * v.y + u.z * v.z);
}

t_point	prod_vect(t_point u, t_point v)
{	
	t_point w;

	w.x = u.y * v.z - u.z * v.y;
	w.y = u.z * v.x - u.x * v.z;
	w.z = u.x * v.y - u.y * v.x;

	return w;
}

t_point	scale_vect(t_point v, double l)
{
	t_point w;

	w.x = v.x * l;
	w.y = v.y * l;
	w.z = v.z * l;

	return w;
}

t_point	add_vect(t_point v, t_point u)
{
	t_point w;

	w.x = v.x + u.x;
	w.y = v.y + u.y;
	w.z = v.z + u.z;

	return w;
}

t_point	less_vect(t_point v, t_point u)
{
	t_point w;

	w.x = v.x - u.x;
	w.y = v.y - u.y;
	w.z = v.z - u.z;

	return w;
}
