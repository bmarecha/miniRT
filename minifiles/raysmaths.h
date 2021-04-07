#ifndef RAYSMATHS
# define RAYSMATHS

# include "forms.h"

typedef struct s_ray
{
        t_point         origin;
        t_point         dir;
        t_colors        color;
}               t_ray;

float                           prod_scal(t_point u, t_point v);
t_point                         prod_vect(t_point u, t_point v);
t_point                         scale_v(t_point v, float l);
t_point                         add_v(t_point v, t_point u);
t_point                         less_v(t_point v, t_point u);
int                             inter_triang(void *p, t_ray *r);

#endif
