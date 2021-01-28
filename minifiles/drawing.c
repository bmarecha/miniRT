#include "minirt.h"

int	calculate(t_scene *scene)
{
	int i;
	int j;
	t_colors **tab;

	i = -1;
	tab = scene->vue->pixels;
	while (tab[++i])
	{
		j = 0;
		while (scene->ysize > j)
		{
			tab[i][j] = scene->ambiantc;
			j++;
		}
	}
	scene->vue->changed = 1;
	printf("Calculated\n");
	return (1);
}
int	draw(t_scene *scene)
{
	int i;
	int j;
	t_colors **tab;
	t_colors cur;

	printf("TryDraw");
	if (!scene->vue->changed)
		return (1);
	printf("drawing\n");
	i = -1;
	j = -1;
	tab = scene->vue->pixels;
	while (tab[++i])
	{
		while (scene->ysize > ++j)
		{
			cur = tab[i][j];
			mlx_pixel_put(scene->mlink, scene->wink, i, j,
				cur.r * 1000000 + cur.g *1000 + cur.b);
		}
		j = -1;
	}
	scene->vue->changed = 0;
	return (1);
}
