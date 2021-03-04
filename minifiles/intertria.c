#include "minirt.h"

t_point	*inter_triang(t_triangle t, t_point dir, t_point start)
{
	t_point n;
	t_point starts;
	t_point u;
	t_point v;
	double iu;
	double iv;
	double ir;
	t_point *res;
	int ori;

	u = less_vect(t.second, t.first);
	v = less_vect(t.third, t.first);
	n = prod_vect(u, v);
	if (!(ori = prod_scal(n,dir)) || !(res = malloc(sizeof(t_point))))
		return NULL;
	starts = less_vect(start, t.first);
	ir = (prod_scal(n, starts)/ori) * -1;
	iu = prod_scal(prod_vect(starts,u),dir)/ori;
	iv = prod_scal(prod_vect(starts,v),dir)/ori;
	u = scale_vect(u, iu);
	v = scale_vect(v, iv);
	print_point(n);
	print_point(dir);
	printf("%f, %f\n", ori, iv);
	*res = scale_vect(dir, ir);
	*res = add_vect(start, *res);
	return res;
}
