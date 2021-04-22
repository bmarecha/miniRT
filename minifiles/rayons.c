#include "minirt.h"

static double	closest_inlst(t_list *lst, double (*f)(void *, t_ray *), t_ray r, t_ray *min)
{
	t_list	*p;
	t_ray	tmp;
	double	sizemin;
	double	len;

	if (!lst)
		return (INFINITY);
	p = lst;
	tmp = r;
	len = sqrt(prod_scal(r.dir, r.dir));
	if (min->color == -1)
		sizemin = INFINITY;
	else
		sizemin = sqrt(prod_scal(min->dir, min->dir));
	if (f(p->content, &tmp) * len < sizemin)
	{
		*min = tmp;
		sizemin = sqrt(prod_scal(min->dir, min->dir));
	}
	while (p->next)
	{
		p = p->next;
		tmp = r;
		if (f(p->content, &tmp)*len < sizemin)
		{
			*min = tmp;
			sizemin = sqrt(prod_scal(min->dir, min->dir));
		}
	}
	return (sizemin);
}

int	closest_intersect(t_ray r, t_scene *scene, t_ray *result)
{
	t_ray	min;
	double	sizemin;

	min.color = -1;
	sizemin = INFINITY;
	if (closest_inlst(scene->triangles, &inter_triang, r, &min) < sizemin)
		sizemin = sqrt(prod_scal(min.dir, min.dir));
	if (closest_inlst(scene->planes, &inter_pla, r, &min) < sizemin)
		sizemin = sqrt(prod_scal(min.dir, min.dir));
	if (closest_inlst(scene->squares, &inter_square, r, &min) < sizemin)
		sizemin = sqrt(prod_scal(min.dir, min.dir));
	if (closest_inlst(scene->spheres, &inter_sphere, r, &min) < sizemin)
		sizemin = sqrt(prod_scal(min.dir, min.dir));

	if (sizemin == INFINITY)
		return (0);
	*result = min;
	return (1);
}

t_colors	ray_color(t_ray r, t_scene *scene)
{
	t_ray	impact;


	if (closest_intersect(r, scene, &impact))
		r.color = impact.color;
	else
		r.color = scene->ambiantc;
	//get color of shadow rays /Don't forget ambiant ligh/ fuse colors
	return (r.color);
}
