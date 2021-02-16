#include "minirt.h"

int	calculate(t_scene *scene)
{
	int		sizepix;
	int		sizeline;
	int		endian;
	static int	phase = 0;
	char		*tab;
	int		i;

	
	tab = mlx_get_data_addr(scene->ilink, &sizepix, &sizeline, &endian);
	i = 0;
	while (i < scene->ysize * sizeline)
	{
		//mlx_get_color_value(scene->mlink, color);
		if (i%4 ==0)
			tab[i] = (scene->ambiantc - phase)%1000;
		else if (i%4 == 1)
			tab[i] = (scene->ambiantc - phase)/1000%1000;
		else if (i%4 == 2)
			tab[i] = (scene->ambiantc - phase)/1000/1000%1000;
		else
			tab[i] = (scene->ambiantc - phase)/1000/1000/1000%1000;
		if (i < 4)
			printf("%u : %d\n", tab[i], scene->ambiantc - phase);
		i += 1;
	}
	scene->changed = 1;
	printf("Calculated, %d, %d\n", sizepix, sizeline);
	phase += 10;
	return (1);
}
int	draw(t_scene *scene)
{
	

	printf("TryDraw");
	if (!scene->changed || !scene->ilink)
		return (1);
	printf("drawing\n");
	mlx_put_image_to_window(scene->mlink, scene->wink, scene->ilink, 0, 0);
	scene->changed = 0;
	return (1);
}
