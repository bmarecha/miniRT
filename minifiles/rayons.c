#include "minirt.h"

int	closest_inlst(t_list *lst, int (*f)(void *, t_ray *), t_ray r, t_ray *min)
{
	t_list	*p;
	t_ray	tmp;
	double	sizemin;

	if (!lst)
		return (0);
	p = lst;
	tmp = r;
	if (f(p->content, &tmp) && (min->color == -1
		|| prod_scal(min->dir, min->dir) > prod_scal(tmp.dir, tmp.dir)))
	{
		*min = tmp;
		sizemin = prod_scal(min->dir, min->dir);
	}
	else
		sizemin = -1;
	while (p->next)
	{
		p = p->next;
		tmp = r;
		if (f(p->content, &tmp) && ((min->color == -1)
			|| sizemin > prod_scal(tmp.dir, tmp.dir)))
		{
			*min = tmp;
			sizemin = prod_scal(min->dir, min->dir);
		}
	}
	if (sizemin == -1)
		return (0);
	return (1);
}

int	closest_intersect(t_ray r, t_scene *scene, t_ray *result)
{
	t_ray	min;

	min.color = -1;
	if (!closest_inlst(scene->triangles, &inter_triang, r, &min))
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
