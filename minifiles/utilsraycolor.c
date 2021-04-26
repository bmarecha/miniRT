#include "forms.h"

int		cotoi(t_colors c)
{
	return (c.r * 1000000 + c.g * 1000 + c.b);
}

void		overflow_control(t_colors *c)
{
	if (c->r > 255)
		c->r = 255;
	if (c->g > 255)
		c->g = 255;
	if (c->b > 255)
		c->b = 255;
}

/*
**void		overflow_control2(t_colors *c)
**{
**	int overr;
**	int overg;
**	int overb;
**
**	overr = 0;
**	overg = 0;
**	overb = 0;
**	if (c->r > 255)
**		overr = (c->r - 255) / 2;
**	if (c->g > 255)
**		overg = (c->r - 255) / 2;
**	if (c->b > 255)
**		overb = (c->r - 255) / 2;
**	c->r = c->r + overg + overb;
**	c->g = c->g + overr + overb;
**	c->b = c->b + overg + overr;
**	overflow_control(c);
**}
*/

t_colors	scal_color(t_colors c, float f)
{
	t_colors res;

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
	t_colors res;

	res.r = c.r + a.r;
	res.g = c.g + a.g;
	res.b = c.b + a.b;
	overflow_control(&res);

	return (res);
}

t_colors	prod_color(t_colors c, t_colors a)
{
	t_colors res;

	res.r = c.r * a.r / 255;
	res.g = c.g * a.g / 255;
	res.b = c.b * a.b / 255;

	return (res);
}

t_colors	sup_color(t_colors c, t_colors a)
{
	t_colors res;

	res = a;
	if (c.r > a.r)
		res.r = c.r;
	if (c.g > a.g)
		res.g = c.g;
	if (c.b > a.b)
		res.b = c.b;
	return (res);
}
