#include "minirt.h"

static int	block_inlst(t_list *p, double (*f)(void *, t_impact *), t_ray r)
{
	t_impact	tmp;
	double		dist_block;

	while (p)
	{
		tmp.ray = r;
		dist_block = f(p->content, &tmp);
		if (dist_block < 1 && dist_block > EPSILON)
			return (1);
		p = p->next;
	}
	return (0);
}

int		light_block(t_ray r, t_scene *scene)
{
	if (block_inlst(scene->triangles, &inter_triang, r))
		return (1);
	if (block_inlst(scene->planes, &inter_pla, r))
		return (1);
	if (block_inlst(scene->squares, &inter_square, r))
		return (1);
	if (block_inlst(scene->spheres, &inter_sphere, r))
		return (1);
	return (0);
}

t_colors	one_light(t_light l, t_impact i, t_scene *scene)
{
	t_colors	res;
	t_ray		r;
	double		ori;

	r = i.ray;
	res.r = 0;
	res.g = 0;
	res.b = 0;
	r.dir = less_v(l.place, r.origin);
	if (light_block(r, scene))
		return (res);
	ori = prod_scal(r.dir, i.norm)/(sqrt(prod_scal(i.norm,i.norm))*sqrt(prod_scal(r.dir,r.dir)));
	ori = 0.1 + ori * 0.9;
	return (scal_color(l.color, l.rate * ori));
}

t_colors	total_light(t_impact i, t_scene *scene)
{
	t_list		*p;
	t_colors	res;
	t_light		*curr;

	res = scal_color(scene->ambiantc, scene->ambiantr);
	i.ray.origin = add_v(i.ray.origin, i.ray.dir);
	p = scene->lights;
	while (p)
	{
		curr = p->content;
		res = sup_color(res, one_light(*curr, i, scene));
		p = p->next;
	}
	return (res);
}
