#include "miniRT.h"

int add_sphere(char **infos, t_scene *scene)
{
	if (!infos[1] || !infos[2] || !infos[3] || !infos[4] || !infos[5]
		|| !infos[6] || !infos[7] || infos[8])
		return (-1);
	if (!scene)
		return (-1);
	t_sphere	*new;
	if (!(new = malloc(sizeof(t_sphere))))
		return (-1);
	if (add_colors(atoi(infos[5]), atoi(infos[6]), atoi(infos[7]), &(new->color)) == -1)
		return (-1);
	return (0);
}

int add_plane(char **infos, t_scene *scene)
{
	if (!infos[1] || !infos[2] || !infos[3] || !infos[4] || !infos[5]
			|| !infos[6] || !infos[7] || !infos[8] || !infos [9] || infos[10])
		return (-1);
	if (!scene)
		return (-1);
	return(0);
}

int add_square(char **infos, t_scene *scene)
{
	if (!infos[1] || !infos[2] || !infos[3] || !infos[4] || !infos[5]
			|| !infos[6] || !infos[7] || !infos[8] || !infos [9]
			|| !infos[10] || infos[11])
		return (-1);
	if (!scene)
		return (-1);
	return(0);
}

int add_cylindre(char **infos, t_scene *scene)
{
	if (!infos[1] || !infos[2] || !infos[3] || !infos[4] || !infos[5]
			|| !infos[6] || !infos[7] || !infos[8] || !infos [9]
			|| !infos[10] || !infos[11] || infos[12])
		return (-1);
	if (!scene)
		return (-1);
	return(0);
}

int add_triangle(char **infos, t_scene *scene)
{
	if (!infos[1] || !infos[2] || !infos[3] || !infos[4] || !infos[5]
			|| !infos[6] || !infos[7] || !infos[8] || !infos [9]
			|| !infos[10] || !infos[11] || !infos[12] || infos[13])
		return (-1);
	if (!scene)
		return (-1);
	return(0);
}
