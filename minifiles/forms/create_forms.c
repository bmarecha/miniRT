#include "minirt.h"

void	create_plane(t_plane *new, char **infos, t_space base, t_colors c)
{
	new->color = c;
	new->norm = base.u;
	point_create(infos[0], infos[1], infos[2], &(new->start));
	new->u = base.v;
	new->v = base.w;
}
