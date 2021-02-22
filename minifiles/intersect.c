#include "vect.c"

t_point	inter_triang(t_triangle t, t_point dir, t_point start)
{
	t_point n;
	t_point starts;
	t_point u;
	t_point v;
	double iu;
	double iv;
	double ir;
	t_point res;

	u = less_vect(t.second, t.first);
	v = less_vect(t.third, t.first);
	n = prod_vect(u, v);
	starts = less_vect(start, t.first);
	ir = (prod_scal(n, starts)/prod_scal(n,dir)) * -1;
	iu = prod_scal(prod_vect(starts,u),dir)/prod_scal(n,dir);
	iv = prod_scal(prod_vect(starts,v),dir)/prod_scal(n,dir);
	u = scale_vect(u, iu);
	v = scale_vect(v, iv);
	print_point(n);
	print_point(dir);
	printf("%f, %f\n", prod_scal(n,dir), iv);
	res = scale_vect(dir, ir);
	res = add_vect(start, res);
	return res;
}

int	main(void)
{
	t_point a = {.x = 3,.y = -3,.z=0};
	t_point b = {.x = -2,.y = -3,.z=0};
	t_point c = {.x = 4,.y = 1,.z=0};
	t_point d = {.x = -2,.y = -1,.z=7};
	t_triangle t = {.first=b,.second=c,.third=d};
	t_point dir = {.x = -1,.y = 0,.z=0};
	print_point(inter_triang(t, dir, a));
	printf("\n");
}

