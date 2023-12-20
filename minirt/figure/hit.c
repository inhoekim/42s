#include "figure.h"

t_bool      hit(t_obj_list *world, t_ray *ray, t_hit *hit)
{
	t_bool	hit_anything;
	t_hit	temp_hit;

	temp_hit = *hit; // temp_rec의 tmin, tmax 값 초기화를 위해.
	hit_anything = FALSE;
	while (world)
	{
		if (hit_obj(world, ray, &temp_hit))
		{
			hit_anything = TRUE;
			temp_hit.t_max = temp_hit.t;
			*hit = temp_hit;
		}
		world = world->next;
	}
	return (hit_anything);
}

// hit_obj는 오브젝트 타입에 맞는 hit함수로 연결해주는 관문
t_bool      hit_obj(t_obj_list *world, t_ray *ray, t_hit *hit)
{
    t_bool  hit_result;

	hit_result = FALSE;
	if (world->type == SPHERE)
		hit_result = hit_sphere(world->data, ray, hit); //hit_sphere의 첫번째 인자도 t_sphere *에서 t_object *로 수정해주자.
	if (world->type == CYLINDER)
		hit_result = hit_cylinder(world->data, ray, hit);
	if (world->type == PLANE)
		hit_result = hit_plane(world->data, ray, hit);
	return (hit_result);
}