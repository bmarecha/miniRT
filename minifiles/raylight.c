#include "minirt.h"

static int	block_inlst(t_list *p, double (*f)(void *, t_ray *), t_ray r)
{
	t_ray	tmp;
	double	dist_block;

	while (p)
	{
		tmp = r;
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

t_colors	one_light(t_light l, t_ray r, t_scene *scene)
{
	t_colors	res;

	res.r = 0;
	res.g = 0;
	res.b = 0;
	r.dir = less_v(l.place, r.origin);
	if (light_block(r, scene))
		return (res);
	return (scal_color(l.color, l.rate));
}

t_colors	total_light(t_ray r, t_scene *scene)
{
	t_list		*p;
	t_colors	res;
	t_light		*curr;

	res = scal_color(scene->ambiantc, scene->ambiantr);
	r.origin = add_v(r.origin, r.dir);
	if (!scene->lights)
		return (res);
	p = scene->lights;
	curr = p->content;
	res = sup_color(res, one_light(*curr, r, scene));
	while (p->next)
	{
		p = p->next;
		curr = p->content;
		res = sup_color(res, one_light(*curr, r, scene));
	}
	return (res);
}
