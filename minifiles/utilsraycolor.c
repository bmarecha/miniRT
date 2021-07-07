#include "forms.h"

t_colors	scal_color(t_colors c, float f)
{
	t_colors	res;

	if (f < 0)
		f = 0;
	res.r = c.r * f;
	res.g = c.g * f;
	res.b = c.b * f;
	overflow_control(&res);
	return (res);
}

t_colors	add_color(t_colors c, t_colors a)
{
	t_colors	res;

	res.r = c.r + a.r;
	res.g = c.g + a.g;
	res.b = c.b + a.b;
	overflow_control(&res);
	return (res);
}

t_colors	prod_color(t_colors c, t_colors a)
{
	t_colors	res;

	res.r = c.r * a.r / 255;
	res.g = c.g * a.g / 255;
	res.b = c.b * a.b / 255;
	return (res);
}

t_colors	sup_color(t_colors c, t_colors a)
{
	t_colors	res;

	res = a;
	if (c.r > a.r)
		res.r = c.r;
	if (c.g > a.g)
		res.g = c.g;
	if (c.b > a.b)
		res.b = c.b;
	return (res);
}
