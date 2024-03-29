#include "minirt.h"

static double	closest_inlst(t_list *lst, double (*f)(void *, t_impact *),
			t_ray r, t_impact *min)
{
	t_list		*p;
	t_impact	tmp;
	double		sizemin;
	double		len;

	p = lst;
	len = sqrt(prod_scal(r.dir, r.dir));
	if (min->ray.color.r == -1)
		sizemin = INFINITY;
	else
		sizemin = sqrt(prod_scal(min->ray.dir, min->ray.dir));
	while (p)
	{
		tmp.ray = r;
		if (f(p->content, &tmp) * len < sizemin)
		{
			*min = tmp;
			sizemin = sqrt(prod_scal(min->ray.dir, min->ray.dir));
		}
		p = p->next;
	}
	return (sizemin);
}

static int	closest_intersect(t_ray r, t_scene *scene, t_impact *res)
{
	double	sizemin;

	res->ray.color.r = -1;
	sizemin = INFINITY;
	if (closest_inlst(scene->triangles, &inter_triang, r, res) < sizemin)
		sizemin = sqrt(prod_scal(res->ray.dir, res->ray.dir));
	if (closest_inlst(scene->planes, &inter_pla, r, res) < sizemin)
		sizemin = sqrt(prod_scal(res->ray.dir, res->ray.dir));
	if (closest_inlst(scene->squares, &inter_square, r, res) < sizemin)
		sizemin = sqrt(prod_scal(res->ray.dir, res->ray.dir));
	if (closest_inlst(scene->spheres, &inter_sphere, r, res) < sizemin)
		sizemin = sqrt(prod_scal(res->ray.dir, res->ray.dir));
	if (closest_inlst(scene->cylindres, &inter_cyl, r, res) < sizemin)
		sizemin = sqrt(prod_scal(res->ray.dir, res->ray.dir));
	if (sizemin == INFINITY)
		return (0);
	if (prod_scal(res->norm, res->ray.dir) > 0)
		res->norm = scale_v(res->norm, -1);
	return (1);
}

t_colors	ray_color(t_ray r, t_scene *scene)
{
	t_impact	impact;

	r.color.r = 0;
	r.color.g = 0;
	r.color.b = 0;
	if (!closest_intersect(r, scene, &impact))
		return (r.color);
	r.color = prod_color(impact.ray.color, total_light(impact, scene));
	return (r.color);
}
