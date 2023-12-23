#include "figure.h"
#include "../view/view.h"
#include "../vector/vector.h"

void	*cylinder(t_coord origin, t_triple color, t_vector dir, t_cylinder_float num)
{
	t_cylinder	*cylinder;

	if (!(cylinder = (t_cylinder *)malloc(sizeof(t_cylinder))))
		print_error("No space to malloc cylinder");
	cylinder->origin = origin;
	cylinder->color = color;
	cylinder->dir = dir;
	cylinder->num.delimeter = num.delimeter;
	cylinder->num.height = num.height;
	return (cylinder);
}

t_cylinder_float	cylinder_float(float del, float height) 
{
    t_cylinder_float num;

    num.delimeter = del;
    num.height = height;
    return (num);
}

float	cy_boundary(t_cylinder *cy, t_vector at_point)
{
	float	hit_height;
	float	max_height;

	hit_height = vec_dot_product(vec_sub(at_point, cy->bot_origin), cy->dir);
	max_height = cy->num.height;
	if (fabs(hit_height) > max_height || hit_height < 0)
		return (0);
	return (hit_height);
}

t_vector      get_cylinder_normal(t_cylinder *cy, t_vector at_point, float hit_height)
{
    t_triple hit_center;
    t_vector normal;

    hit_center = vec_add(cy->bot_origin, vec_mul_num(cy->dir, hit_height));
    normal = vec_sub(at_point, hit_center);

    return (vec_unit(normal));
}

int      hit_cylinder_cap(t_cylinder *cy, t_ray *ray, t_hit *rec, float height)
{
    const float r = cy->num.delimeter / 2;
    const t_vector    circle_center = vec_add(cy->origin, vec_mul_num(cy->dir, height / 2));
    // const float root = vec_dot_product(vec_sub(circle_center, ray->origin), cy->dir);
	const float root =  (vec_dot_product(vec_sub(cy->origin, ray->origin), cy->dir)) / (vec_dot_product(ray->dir, cy->dir));
    const float diameter = vec_len(vec_sub(circle_center, ray_at(ray, root)));
	if (fabs(r) < fabs(diameter))
		return (0);
    if (root < rec->t_min || rec->t_max < root)
       return (0);
    rec->t = root; 
    rec->coord = ray_at(ray, root);
    rec->t_max = rec->t;
    if (0 < height)
        rec->normal_vec = cy->dir;
    else
        rec->normal_vec = vec_mul_num(cy->dir, -1);

    // rec->normal = vunit(vminus(circle_center, ray->origin)); // vmult(ray->dir, root)하면 안돼!!!
    set_face_normal(ray, rec);
    rec->albedo = cy->color;
    return (1);
}

int      hit_cylinder_side(t_cylinder *cy, t_ray *ray, t_hit *rec)
{
	t_vector  w; // 실린더의 바닥과 카메라의 중점을 잇는 벡터
    float   a;
    float   half_b;
    float   c;
    float   r;

    float discriminant; // 판별식
    float sqrt_f;
    float root;
    float hit_height;
    
    r = cy->num.delimeter / 2;
	w = vec_sub(ray->origin, cy->bot_origin);
    a = vec_dot_product(ray->dir, ray->dir) - powf(vec_dot_product(ray->dir, cy->dir), 2.0);
    half_b = vec_dot_product(ray->dir, w) - (vec_dot_product(ray->dir, cy->dir) * vec_dot_product(w, cy->dir));
    c = vec_dot_product(w, w) - powf(vec_dot_product(w, cy->dir), 2) - r * r;
    discriminant = half_b * half_b - a * c;
    if (discriminant < FZERO) 
        return (0);
    // 이 시점에서 판별식이 참이 나왔기에 근이 존재한다고 판단한다.
    sqrt_f = sqrtf(discriminant); 
	root = (-half_b - sqrt_f) / a;  // 근의 공식 해, 작은 근부터 고려.
	if (root < rec->t_min || rec->t_max < root)
	{
		root = (-half_b + sqrt_f) / a; 
		if (root < rec->t_min || rec->t_max < root)
			return (0);
	}
    t_triple temp_coord = ray_at(ray, root);
    if (!(hit_height = cy_boundary(cy, temp_coord)))
        return (0);
    rec->t = root; // 광선의 원점과 교점까지의 거리를 rec에 저장한다.
    rec->coord = temp_coord; // 교점의 좌표를 rec에 저장한다.
    rec->normal_vec = get_cylinder_normal(cy, rec->coord, hit_height);
	set_face_normal(ray, rec);
    rec->albedo = cy->color;

    return (1);
}

t_bool      hit_cylinder(t_cylinder *cy, t_ray *ray, t_hit *rec)
{
    int result;

    result = 0;
    // result += hit_cylinder_cap(cy, ray, rec, cy->num.height / 2);
    result += hit_cylinder_cap(cy, ray, rec, -(cy->num.height / 2));
    result += hit_cylinder_side(cy, ray, rec);
    return (result);
}