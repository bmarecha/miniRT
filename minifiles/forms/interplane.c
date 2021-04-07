#include "minirt.h"

double	inter_pla(void *p, t_ray *r)
{
	t_point	starts;
	double	ir;
	double	ori;
	t_plane	*pl;

	pl = (t_plane *)p;
	ori = prod_scal(pl->norm,r->dir);
	if (!ori)
		return INFINITY;
	starts = less_v(pl->start, r->origin);
	ir = (prod_scal(pl->norm, starts)/ori);
	if (ir <= 0)
		return INFINITY;
	r->dir = scale_v(r->dir, ir);
	r->color = pl->color;
	return ir;
}
