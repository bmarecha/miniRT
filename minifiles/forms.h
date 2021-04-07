#ifndef FORMS_H
# define FORMS_H

# include "libft.h"

typedef struct s_point
{
	double		x;
	double		y;
	double		z;
}				t_point;

typedef int			t_colors;

typedef struct s_space {
	t_point	u;
	t_point	v;
	t_point	w;
}		t_space;

typedef	struct s_sphere
{
	t_point		center;
	double		diameter;
	t_colors	color;
}				t_sphere;

typedef	struct s_plane
{
	t_point		start;
	t_point		norm;
	t_point		u;
	t_point		v;
	t_colors	color;
}				t_plane;

typedef	struct s_square
{
	t_point		start;
	t_point		way;
	double		height;
	t_colors	color;
}				t_square;

typedef	struct s_cylindre
{
	t_point		start;
	t_point		way;
	double		diameter;
	double		height;
	t_colors	color;
}				t_cylindre;

typedef	struct s_triangle
{
	t_point		first;
	t_point		second;
	t_point		third;
	t_colors	color;
}				t_triangle;

void	point_create(char *x, char *y, char *z, t_point *point);
void	create_plane(t_plane *new, char **infos, t_space base, t_colors c);
int	add_sphere(char **infos, t_list **lst);
int	add_plane(char **infos, t_list **lst);
int	add_square(char **infos, t_list **lst);
int	add_cylindre(char **infos, t_list **lst);
int	add_triangle(char **infos, t_list **lst);
int	add_colors(int r, int g, int b, t_colors *colors);

#endif
