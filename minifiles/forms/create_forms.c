#include "forms.h"

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
