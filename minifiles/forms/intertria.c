#include "minirt.h"

double	inter_triang(void *p, t_ray *r)
{
	t_point	n;
	t_point	starts;
	t_point	u;
	t_point	v;
	double	iu;
	double	iv;
	double	ir;
	t_point	*res;
	double	ori;
	t_triangle	*t;

	t = (t_triangle *)p;
	u = less_v(t->second, t->first);
	v = less_v(t->third, t->first);
	n = prod_vect(u, v);
	if (!(ori = prod_scal(n,r->dir)) || !(res = malloc(sizeof(t_ray))))
		return INFINITY;
	starts = less_v(r->origin, t->first);
	ir = (prod_scal(n, starts)/ori) * -1;
	iu = prod_scal(prod_vect(starts,u),r->dir)/ori;
	iv = prod_scal(prod_vect(starts,v),r->dir)/ori;
	if (ir <= 0 || iu < 0 || iv < 0 || iv + iu > 1)
		return INFINITY;
	u = scale_v(u, iu);
	v = scale_v(v, iv);
	r->dir = scale_v(r->dir, ir);
	r->color = t->color;
	return ir;
}
