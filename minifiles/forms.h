#ifndef FORMS_H
# define FORMS_H

# include "libft.h"

typedef struct s_point
{
	float		x;
	float		y;
	float		z;
}				t_point;

typedef int			t_colors;

typedef	struct s_sphere
{
	t_point		center;
	float		diameter;
	t_colors	color;
}				t_sphere;

typedef	struct s_plane
{
	t_point		start;
	t_point		way1;
	t_point		way2;
	t_colors	color;
}				t_plane;

typedef	struct s_square
{
	t_point		start;
	t_point		way;
	float		height;
	t_colors	color;
}				t_square;

typedef	struct s_cylindre
{
	t_point		start;
	t_point		way;
	float		diameter;
	float		height;
	t_colors	color;
}				t_cylindre;

typedef	struct s_triangle
{
	t_point		first;
	t_point		second;
	t_point		third;
	t_colors	color;
}				t_triangle;

void                            point_create(char *x, char *y, char *z, t_point *point);
int				add_sphere(char **infos, t_list **lst);
int				add_plane(char **infos, t_list **lst);
int				add_square(char **infos, t_list **lst);
int				add_cylindre(char **infos, t_list **lst);
int				add_triangle(char **infos, t_list **lst);
int				add_colors(int r, int g, int b, t_colors *colors);


#endif
