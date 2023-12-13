#include "view.h"

t_canvas	init_canvas(int width, int height)
{
	t_canvas	canvas;

	canvas.width = width;
	canvas.height = height;
	canvas.aspect_ratio = (float)width / (float)height;
	return (canvas);
}

t_camera	init_camera(t_canvas *canvas, t_vector origin)
{
	t_camera	cam;
	float		focal_len;
	float		viewport_height;

	viewport_height = 2.0;
	focal_len = 1.0;
	cam.origin = origin;
	cam.viewport_h = viewport_height;
	cam.viewport_w = viewport_height * canvas->aspect_ratio;
	cam.focal_len = focal_len;
	cam.horizon_vec = vec(cam.viewport_w, 0, 0);
	cam.vertical_vec = vec(0, cam.viewport_h, 0);
	cam.left_bottom = vec(origin.x - (cam.viewport_w / 2), origin.y - (cam.viewport_h / 2), origin.z - focal_len);
	/*
	vec_sub(vec_sub(vec_sub(cam.origin, \
	vec_div_num(cam.horizon_vec, 2)), vec_div_num(cam.vertical_vec, 2)), \
	vec(0, 0, focal_len));
	*/
	return (cam);
}
