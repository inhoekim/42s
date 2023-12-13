#include "figure.h"
#include "../view/view.h"
#include "../vector/vector.h"

t_sphere	sphere(t_coord center, double radius)
{
	t_sphere	sphere;

	sphere.center = center;
	sphere.radius = radius;
	return (sphere);
}

float	hit_sphere(t_sphere *sp, t_ray *ray)
{
	t_vector  co; // co->
	float	a;
	float	b;
	float	c;
	float	discriminant; //판별식

	co = vec_sub(ray->origin, sp->center);
	a = vec_dot_product(ray->dir_vec, ray->dir_vec);
	b = 2.0 * vec_dot_product(co, ray->dir_vec);
	c = vec_dot_product(co, co) - (sp->radius * sp->radius);
	// discriminant 는 판별식
	discriminant = b * b - 4 * a * c;
	if (discriminant < 0)
		return (-1.0);
	return (-b - sqrt(discriminant) / (2.0 * a));
}