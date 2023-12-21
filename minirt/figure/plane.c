#include "figure.h"
#include "../view/view.h"
#include "../vector/vector.h"

void	*plane(t_coord origin, t_triple color, t_vector dir)
{
	t_plane	*plane;

	if (!(plane = (t_plane *)malloc(sizeof(t_plane))))
		print_error("No space to malloc plane");
	plane->origin = origin;
	plane->pl_normal = dir;
	plane->color = color;
	return (plane);
}

t_bool	hit_plane(t_plane *pl, t_ray *ray, t_hit *hit)
{
	float	num;
	float	denom;
	float	root;

	denom = vec_dot_product(ray->dir_vec, pl->pl_normal);
	if (fabs(denom) < 1e-3)
		return (FALSE);
	num = vec_dot_product(vec_sub(pl->origin, ray->origin), pl->pl_normal);
	root = num / denom;
	if (root < hit->t_min || hit->t_max < root)
		return (FALSE);
	hit->t = root;
	hit->coord = ray_at(ray, root);
	hit->normal_vec = pl->pl_normal;
	set_face_normal(ray, hit);
	hit->albedo = pl->color;
	return (TRUE);
}
