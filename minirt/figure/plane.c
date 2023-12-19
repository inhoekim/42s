#include "figure.h"
#include "../view/view.h"
#include "../vector/vector.h"

void	*plane(t_coord origin, t_triple color, t_vector dir)
{
	t_plane	*plane;

	if (!(plane = (t_plane *)malloc(sizeof(t_plane))))
		print_error("No space to malloc plane");
	plane->origin = origin;
	plane->pl_vec = dir;
	plane->color = color;
	return (plane);
}
