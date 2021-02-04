#include "minirt.h"

int	calculate(t_scene *scene)
{
	int i;
	int j;
	static int phase = 0;
	t_colors **tab;

	i = -1;
	tab = scene->vue->pixels;
	while (tab[++i])
	{
		j = 0;
		while (scene->ysize > j)
		{
			tab[i][j] = scene->ambiantc - phase;
			j++;
		}
	}
	scene->vue->changed = 1;
	printf("Calculated\n");
	phase += 100;
	return (1);
}
int	draw(t_scene *scene)
{
	int i;
	int j;
	t_colors **tab;

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
			mlx_pixel_put(scene->mlink, scene->wink, i, j,
				(int) tab[i][j]);
		}
		j = -1;
	}
	scene->vue->changed = 0;
	return (1);
}
