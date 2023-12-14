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

void    set_face_normal(t_ray *r, t_hit *rec)
{
    // 광선의 방향벡터와 교점의 법선벡터의 내적이 음수이면 광선은 앞면(객체의)에 hit 한 것이다
    rec->front_face = vec_dot_product(r->dir_vec, rec->normal_vec) < 0;
    // 광선의 앞면에 hit 면 그대로 아니면 법선을 반대로 뒤집는다. (항상 광선 방향벡터와 법선 벡터를 반대인 상태로 사용하기위해)
    rec->normal_vec = (rec->front_face) ? rec->normal_vec : vec_mul_num(rec->normal_vec, -1);
}

t_bool	hit_sphere(t_sphere *sp, t_ray *ray, t_hit *hit)
{
	t_vector  co; // co->
	float	a;
	float	half_b;
	float	c;
	float	discriminant; //판별식
	float	sqrt_d;
	float	root;

	co = vec_sub(ray->origin, sp->center);
	/*
	a = vec_dot_product(ray->dir_vec, ray->dir_vec);
	b = 2.0 * vec_dot_product(co, ray->dir_vec);
	c = vec_dot_product(co, co) - (sp->radius * sp->radius);
	// discriminant 는 판별식
	discriminant = b * b - 4 * a * c;
	if (discriminant < 0)
		return (-1.0);
	return (-b - sqrt(discriminant) / (2.0 * a));
	*/
	a = vec_len_square(ray->dir_vec);
	half_b = vec_dot_product(co, ray->dir_vec);
	c = vec_len_square(co) - (sp->radius * sp->radius);
	discriminant = half_b * half_b - a * c;

	if (discriminant < 0)
		return (FALSE);
	sqrt_d =sqrt(discriminant);
	root = (-half_b - sqrt_d) / a;
	if (root < hit->t_min || hit->t_max < root)
	{
		root = (-half_b + sqrt_d) / a;
		if (root < hit->t_min || hit->t_max < root)
			return (FALSE);
	}
	hit->t = root;
	hit->coord = ray_at(ray, root);
	hit->normal_vec = vec_div_num(vec_sub(hit->coord, sp->center), sp->radius);
	set_face_normal(ray, hit); // 구의 hit 점에서 법선벡터와 광선의 방향벡터를 비교해서 앞면인지 뒷면인지 t_bool의 결과를 저장
	return (TRUE);
}
