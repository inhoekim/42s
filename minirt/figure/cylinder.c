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
	cylinder->cy_vec = dir;
	cylinder->num.delimeter = num.delimeter;
	cylinder->num.height = num.height;
	return (cylinder);
}

t_cylinder_float	cylinder_float(float x, float y)
{
	t_cylinder_float	cylinder_float;

	cylinder_float.delimeter = x;
	cylinder_float.height = y;
	return (cylinder_float);
}

int	cy_boundary(t_cylinder *cy, t_vector at_point)
{
	double	hit_height;
	double	max_height;

	hit_height = vec_dot_product(vec_sub(at_point, cy->origin), cy->cy_vec);
	max_height = cy->num.height / 2;
	
	if (fabs(hit_height) > max_height)
		return (0);
	return (1);
}

t_vector      get_cylinder_normal(t_cylinder *cy, t_vector at_point, double hit_height)
{
    t_triple hit_center;
    t_vector normal;

    hit_center = vec_add(cy->origin, vec_mul_num(cy->cy_vec, hit_height));
    normal = vec_sub(at_point, hit_center);

    return (vec_unit(normal));
}

int      hit_cylinder_cap(t_obj_list *cy_obj, t_ray *ray, t_hit *rec, double height)
{
    const t_cylinder *cy = cy_obj->data;
    const double r = cy->num.delimeter / 2;
    const t_vector    circle_center = vec_add(cy->origin, vec_mul_num(cy->cy_vec, height));
    const float root = vec_dot_product(vec_sub(circle_center, ray->origin), cy->cy_vec);
    const float diameter = vec_len(vec_sub(circle_center, ray_at(ray, root)));
	if (fabs(r) < fabs(diameter))
		return (0);
    if (root < rec->t_min || rec->t_max < root)
       return (0);
    rec->t = root; 
    rec->coord = ray_at(ray, root);
    rec->t_max = rec->t;
    if (0 < height)
        rec->normal_vec = cy->cy_vec;
    else
        rec->normal_vec = vec_mul_num(cy->cy_vec, -1);

    // rec->normal = vunit(vminus(circle_center, ray->origin)); // vmult(ray->dir, root)하면 안돼!!!
    set_face_normal(ray, rec);
    rec->albedo = cy_obj->albedo;
    return (1);
}

int      hit_cylinder_side(t_obj_list *cy_obj, t_ray *ray, t_hit *rec)
{
    t_cylinder *cy;

 
    //a, b, c는 각각 t에 관한 근의 공식 2차 방정식의 계수
    double  a;
		double  half_b;
    double  c;
    t_vector  u;
    t_vector  o;
    t_vector  delta_P;
    double r;

    double discriminant; // 판별식
    double sqrtd;
    double root;
    double hit_height;
    
    cy = cy_obj->data;
    u = ray->dir_vec;
    o = cy->cy_vec;
    r = cy->num.delimeter / 2;
    delta_P = vec_sub(ray->origin, cy->origin);
    a = vec_len_square(vec_cross_product(u, o));
    half_b = vec_dot_product(vec_cross_product(u, o), vec_cross_product(delta_P, o));
    c = vec_len_square(vec_cross_product(delta_P, o)) - pow(r, 2);
    discriminant = half_b * half_b - a * c;
    if (discriminant < 0) 
        return (0);
    // 이 시점에서 판별식이 참이 나왔기에 근이 존재한다고 판단한다.
    sqrtd = sqrt(discriminant); 
    root = (-half_b - sqrtd) / a;  // 근의 공식 해, 작은 근부터 고려.
    if (root < rec->t_min || rec->t_max < root)
    {
    root = (-half_b + sqrtd) / a; 
        if (root < rec->t_min || rec->t_max < root)
        return (0);
    }
    //    print_vec(vmult(ray->dir, root));
    // print_vec(ray_at(ray, root));
    if (!(hit_height = cy_boundary(cy, ray_at(ray, root))))
        return (0);

    rec->t = root; // 광선의 원점과 교점까지의 거리를 rec에 저장한다.
    rec->coord = ray_at(ray, root); // 교점의 좌표를 rec에 저장한다.
    rec->normal_vec = get_cylinder_normal(cy, rec->coord, hit_height);
	  set_face_normal(ray, rec); 
    rec->albedo = cy_obj->albedo;
    return (1);
}

t_bool      hit_cylinder(t_obj_list *cy_obj, t_ray *ray, t_hit *rec)
{
    t_cylinder *cy = cy_obj->data;
    int result;

    result = 0;
	printf("%p\n", cy);
    result += hit_cylinder_cap(cy_obj, ray, rec, cy->num.height / 2);
    result += hit_cylinder_cap(cy_obj, ray, rec, -(cy->num.height / 2));
    result += hit_cylinder_side(cy_obj, ray, rec);
    return (result);
}