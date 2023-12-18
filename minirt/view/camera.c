#include "view.h"
#include "../vector/vector.h"
#include "../minirt.h"

t_camera	init_camera(t_coord origin, t_vector dir)
{
	t_camera	cam;
	t_vector	temp_left_bot;
	float		ratio_w;
	float		ratio_h;

	cam.origin = origin;
	cam.dir = dir;
	//cam.fov = 90;
	//cam.focal_len = (float)WIDTH / 2 / get_tan(cam.fov / 2);
	cam.focal_len = 1.0;
	ratio_h = 2;
	ratio_w = 2 * WIDTH / HEIGHT;
	if (vec_len(vec_cross_product(vec(0, 1.0, 0), cam.dir)))
		cam.horizon_vec = vec_mul_num(vec_unit(vec_cross_product(cam.dir, vec(0, 1.0, 0))), ratio_w);
	else 
		cam.horizon_vec = vec_mul_num(vec_unit(vec_cross_product(cam.dir, vec(0, 0, -1.0))), ratio_w);
	cam.vertical_vec = vec_mul_num(vec_unit(vec_cross_product(cam.horizon_vec, cam.dir)), ratio_h);
	temp_left_bot = vec_add(cam.origin, vec_mul_num(cam.dir, cam.focal_len)); //뷰포트의 중점좌표
	temp_left_bot = vec_sub(temp_left_bot, vec_div_num(cam.horizon_vec, 2));
	temp_left_bot = vec_sub(temp_left_bot, vec_div_num(cam.vertical_vec, 2));
	cam.left_bottom = temp_left_bot;
	return (cam);
}
