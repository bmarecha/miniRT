#include "minirt.h"

double	solve_plan(t_plane *pl, t_ray *r, double *ori, t_point s)
{
	double	ir;

	*ori = prod_scal(pl->norm,r->dir);
	if (!*ori)
		return INFINITY;
	ir = prod_scal(pl->norm, s)/(*ori);
	if (ir <= 0)
		return INFINITY;
	return (ir);
}

double	inter_pla(void *p, t_impact *i)
{
	t_point	starts;
	double	ir;
	double	ori;
	t_plane	*pl;
	t_ray	*r;

	r = &(i->ray);
	pl = (t_plane *)p;
	starts = less_v(pl->start, r->origin);
	ir = solve_plan(pl, r, &ori, starts);
	if (ir == INFINITY)
		return (INFINITY);
	r->dir = scale_v(r->dir, ir);
	r->color = pl->color;
	i->norm = pl->norm;
	return (ir);
}

double	inter_square(void *p, t_impact *i)
{
	t_square	*s;
	double		ori;
	double		ic[3];
	t_point		start;
	t_ray		*r;

	r = &(i->ray);
	s = (t_square *)p;
	start = s->plane.start;
	ic[0] = solve_plan(&(s->plane), r, &ori, start);
	if (ic[0] == INFINITY)
		return (INFINITY);
	ic[1] = prod_scal(prod_vect(start,s->plane.u),r->dir)/ori;
	ic[2] = prod_scal(prod_vect(start,s->plane.v),r->dir)/ori;
	if (ic[1] < 0 || ic[2] < 0 || ic[1] < s->height || ic[2] < s->height)
		return (INFINITY);
	r->dir = scale_v(r->dir, ic[0]);
	r->color = s->plane.color;
	i->norm = s->plane.norm;
	return (ic[0]);
}

static int	is_in_tria(t_triangle t, double ori, t_point start, t_point impact)
{
	t_point		u;
	t_point		v;
	double		iu;
	double		iv;

	u = less_v(t.second, t.first);
	v = less_v(t.third, t.first);
	iu = prod_scal(prod_vect(start,v),impact)/ori;
	iv = prod_scal(prod_vect(u, start),impact)/ori;
	if (iu < 0 || iv < 0 || iv + iu > 1)
		return (0);
	return (1);
}

double	inter_triang(void *p, t_impact *i)
{
	t_point		start;
	t_triangle	*t;
	double		ori;
	double		ir;
	t_ray		*r;

	r = &(i->ray);
	t = (t_triangle *)p;
	start = less_v(t->plane.start, r->origin);
	ir = solve_plan(&(t->plane), r, &ori, start);
	if(ir == INFINITY)
		return (INFINITY);
	//Maintenant tester si c'est dans le triangle
	ori *= ir;
	if (!is_in_tria(*t, ori, start, r->dir))
		return (INFINITY);
	r->dir = scale_v(r->dir, ir);
	r->color = t->plane.color;
	i->norm = t->plane.norm;
	return ir;
}
