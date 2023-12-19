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