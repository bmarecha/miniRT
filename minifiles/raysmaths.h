#ifndef RAYSMATHS
# define RAYSMATHS

# include "forms.h"

typedef struct s_ray
{
        t_point         origin;
        t_point         dir;
        t_colors        color;
}		t_ray;

typedef struct s_impact
{
        t_point         norm;
        t_ray		ray;
}		t_impact;

double				prod_scal(t_point u, t_point v);
t_point                         prod_vect(t_point u, t_point v);
t_point                         scale_v(t_point v, double l);
t_point                         add_v(t_point v, t_point u);
t_point                         less_v(t_point v, t_point u);
double				solve_plan(t_plane *pl, t_ray *r, double *ori, t_point s);
double				inter_triang(void *p, t_impact *i);
double				inter_pla(void *p, t_impact *i);
double				inter_square(void *p, t_impact *i);
double				inter_sphere(void *sp, t_impact *i);
double				inter_cyl(void *p, t_impact *i);

#endif
