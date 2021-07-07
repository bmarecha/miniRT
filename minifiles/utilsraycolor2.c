#include "forms.h"

int	cotoi(t_colors c)
{
	return (c.r * 1000000 + c.g * 1000 + c.b);
}

void	overflow_control(t_colors *c)
{
	if (c->r > 255)
		c->r = 255;
	if (c->g > 255)
		c->g = 255;
	if (c->b > 255)
		c->b = 255;
}
