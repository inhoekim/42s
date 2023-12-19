#include "../minirt.h"
#include "../vector/vector.h"
#include "view.h"

t_triple    point_light_get(t_light *light, t_hit hit)
{
	t_triple	diffuse;
	t_triple	light_dir;
	float		kd; // diffuse의 강도

    light_dir = vec_unit(vec_sub(light->origin, hit.coord));
    //kd의 최소값은 0.0
    kd = fmaxf(vec_dot_product(hit.normal_vec, light_dir), 0.0);
    diffuse = vec_mul_num(vec(1, 1, 1), kd);
    return (diffuse);
}

t_triple        phong_lighting(t_info *info, t_hit hit)
{
    t_triple    light_color;

    light_color = point_light_get(&(info->light), hit);
    light_color = vec_add(light_color, vec_mul_num(info->a_light.color, info->a_light.ratio));
	if (light_color.x > 1.0)
		light_color.x = 1.0;
	if (light_color.y > 1.0)
		light_color.y = 1.0;
	if (light_color.z > 1.0)
		light_color.z = 1.0;
    return (vec_mul(hit.albedo, light_color));
    //모든 광원에 의한 빛의 양을 구한 후, 오브젝트의 반사율과 곱해준다. 그 값이 (1, 1, 1)을 넘으면 (1, 1, 1)을 반환한다.
}

t_light	*light_point(t_coord light_origin, t_triple color, float ratio)
{
	t_light *light;

	if (!(light = (t_light *)malloc(sizeof(t_light))))
		exit(1);
	light->origin = light_origin;
	light->color = color;
	light->ratio = ratio;
	return (light);
}