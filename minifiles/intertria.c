#include "minirt.h"

int	inter_triang(void *p, t_ray *r)
{
	t_point	n;
	t_point	starts;
	t_point	u;
	t_point	v;
	double	iu;
	double	iv;
	double	ir;
	t_point	*res;
	int	ori;
	t_triangle	*t;
	//static int i = 0;

	t = (t_triangle *)p;
	u = less_vect(t->second, t->first);
	v = less_vect(t->third, t->first);
	n = prod_vect(u, v);
	if (!(ori = prod_scal(n,r->dir)) || !(res = malloc(sizeof(t_ray))))
		return 0;
	starts = less_vect(r->origin, t->first);
	ir = (prod_scal(n, starts)/ori) * -1;
	iu = prod_scal(prod_vect(starts,u),r->dir)/ori;
	iv = prod_scal(prod_vect(starts,v),r->dir)/ori;
	//if (i++ < 5)
	//	printf("%f, %f, %f, %f\n", ir, iu, iv, r->origin.x);
	//if (ir <= 0 || iu < 0 || iu > 1 || iv < 0 || iv > 1)
	//	return 0;
	u = scale_vect(u, iu);
	v = scale_vect(v, iv);
	r->dir = scale_vect(r->dir, ir);
	//r->dir = add_vect(start, r->dir);
	return 1;
}
