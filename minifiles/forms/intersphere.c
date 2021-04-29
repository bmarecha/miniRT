#include "minirt.h"

static void		solve_sphere(t_sphere *sp, double x[2], t_point o, t_point d)
{
	double	disc;
	t_point	oc;
	double	k[3];

	oc = less_v(o, sp->center);
	k[0] = prod_scal(d, d);
	k[1] = 2 * prod_scal(d, oc);
	k[2] = prod_scal(oc, oc) - sp->rayon * sp->rayon;
	disc = k[1] * k[1] - (4 * k[0] * k[2]);
	if (disc < 0)
	{
		x[0] = INFINITY;
		x[1] = INFINITY;
		return ;
	}
	x[0] = (-k[1] + sqrt(disc)) / (2 * k[0]);
	x[1] = (-k[1] - sqrt(disc)) / (2 * k[0]);
}

double			inter_sphere(void *p, t_impact *i)
{
	double	min;
	double	x[2];
	t_sphere	*sp;
	t_ray		*r;

	r = &(i->ray);
	sp = (t_sphere *)p;
	min = INFINITY;
	solve_sphere(sp, x, r->origin, r->dir);
	if (x[0] > EPSILON && x[0] < INFINITY)
		min = x[0];
	if (x[1] > EPSILON && x[1] < INFINITY && x[1] < x[0])
		min = x[1];
	if (min == INFINITY)
		return (INFINITY);
	r->color = sp->color;
	r->dir = scale_v(r->dir, min);
	i->norm = less_v(add_v(r->dir, r->origin), sp->center);
	return (min);
}
