#include "../minirt.h"

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
