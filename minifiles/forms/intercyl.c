#include "minirt.h"

static double	test_soluce(t_cylindre cyl, t_ray r, double x[3], t_point so)
{
	t_point	stoi;
	double	size[2];
	double	ori;

	stoi = add_v(so, scale_v(r.dir, x[1]));
	size[0] = normv(stoi);
	ori = prod_scal(cyl.bottom.plane.norm, stoi);
	size[0] = sqrt(size[0] * size[0] - cyl.bottom.radius * cyl.bottom.radius);
	if (x[1] > EPSILON && size[0] < cyl.height && ori > 0 && x[1] < x[0])
		return (x[1]);
	stoi = add_v(so, scale_v(r.dir, x[0]));
	size[0] = normv(stoi);
	ori = prod_scal(cyl.bottom.plane.norm, stoi);
	size[0] = sqrt(size[0] * size[0] - cyl.bottom.radius * cyl.bottom.radius);
	if (x[0] > EPSILON && size[0] < cyl.height && ori > 0)
		return (x[0]);
	return (INFINITY);
}

static double	solve_tube(t_cylindre cyl, t_ray r, t_point *norm)
{
	double	x[3];
	double	abc[4];
	t_point	u;
	t_point	v;
	t_point	h;

	h = cyl.bottom.plane.norm;
	v = less_v(r.dir, scale_v(h, prod_scal(r.dir, h)));
	u = scale_v(h, prod_scal(less_v(r.origin, cyl.bottom.plane.start), h));
	u = less_v(less_v(r.origin, cyl.bottom.plane.start), u);
	abc[0] = prod_scal(v, v);
	abc[1] = 2 * prod_scal(v, u);
	abc[2] = prod_scal(u, u) - cyl.bottom.radius * cyl.bottom.radius;
	abc[3] = abc[1] * abc[1] - 4 * abc[0] * abc[2];
	if (abc[3] < 0 || abc[0] == 0)
		return (INFINITY);
	x[0] = (-abc[1] + sqrt(abc[3])) / (2 * abc[0]);
	x[1] = (-abc[1] - sqrt(abc[3])) / (2 * abc[0]);
	x[2] = (-abc[1]) / (2 * abc[0]);
	x[0] = test_soluce(cyl, r, x, less_v(r.origin, cyl.bottom.plane.start));
	if (x[0] != INFINITY)
		*norm = add_v(scale_v(v, x[0]), u);
	return (x[0]);
}

static double	solve_circle(t_circle c, t_ray r)
{
	double	ori;
	double	ir;
	t_point	imp;
	t_point	dist;

	ir = solve_plan(&(c.plane), &r, &ori, less_v(c.plane.start, r.origin));
	if (ir == INFINITY)
		return (INFINITY);
	imp = add_v(r.origin, scale_v(r.dir, ir));
	dist = less_v(imp, c.plane.start);
	if (normv(dist) > c.radius)
		return (INFINITY);
	return (ir);
}

double		inter_cyl(void *p, t_impact *i)
{
	double		icircle;
	double		icyl;
	t_ray		r;
	t_cylindre	c;
	t_point		norm_tube;

	c = *(t_cylindre *)p;
	r = i->ray;
	icircle = solve_circle(c.top, r);
	icyl = solve_circle(c.bottom, r);
	if (icyl < icircle)
		icircle = icyl;
	icyl = solve_tube(c, r, &norm_tube);
	if (icircle == INFINITY && icyl == INFINITY)
		return (INFINITY);
	i->ray.color = c.color;
	if (icircle < icyl)
	{
		i->norm = c.top.plane.norm;
		i->ray.dir = scale_v(r.dir, icircle);
		return (icircle);
	}
	i->norm = norm_tube;
	i->ray.dir = scale_v(r.dir, icyl);
	return (icyl);
}
