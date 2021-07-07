#include "forms.h"
#include "raysmaths.h"
#include <stdio.h>

void	point_create(char *x, char *y, char *z, t_point *point)
{
	point->x = ft_atof(x);
	point->y = ft_atof(y);
	point->z = ft_atof(z);
}

void	create_inv_vect(t_point u, t_point v, t_point *inv_u, t_point *inv_v)
{
	t_point	w;

	w = prod_vect(u, v);
	*inv_u = prod_vect(v, w);
	*inv_u = scale_v(*inv_u, 1 / prod_scal(*inv_u, u));
	*inv_v = prod_vect(w, u);
	*inv_v = scale_v(*inv_v, 1 / prod_scal(*inv_v, v));
}

void	create_plane(t_plane *n, char **infos, t_space base, t_colors c)
{
	n->color = c;
	n->norm = base.u;
	point_create(infos[0], infos[1], infos[2], &(n->start));
	n->u = base.v;
	n->v = base.w;
}

void	create_circle(t_circle *n, t_plane plan, double radius)
{
	n->plane = plan;
	n->radius = radius;
}
