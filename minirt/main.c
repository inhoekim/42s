#include <mlx.h>
#include "vector/vector.h"
#include "view/view.h"
#include "figure/figure.h"

void    write_color(t_coord color)
{
    printf("%d %d %d\n", (int)(255.999 * color.x),
                        (int)(255.999 * color.y),
                        (int)(255.999 * color.z));
}
int		create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

void			my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;
	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	key_hook(int keycode, t_vars *vars)
{
	if(keycode == 53)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		exit(0);
	}
	return (0);
}

int main(void)
{
    int         x;
    int         y;
    float      normalized_x;
    float      normalized_y;
	void	*mlx_ptr;
	void	*win_ptr;
    t_triple	pixel_color;
    t_camera    cam;
    t_ray       ray;
	t_sphere	sp;
	t_coord		origin;
	t_vector	dir;
    t_data      data;

	origin.x = 0;
	origin.y = 0;
	origin.z = 0;
	dir.x = 1;
	dir.y = 1;
	dir.z = 1;
    cam = init_camera(origin, dir);
	sp = sphere(vec(0, 0, -5), 2);

    y = HEIGHT - 1;
    while (y >= 0)
    {
        x = 0;
       while (x < WIDTH)
        {
            ray = ray_primary(&cam, x, y);
            pixel_color = ray_color(&ray);
            //write_color(pixel_color);
			my_mlx_pixel_put(&data, x, canv.height - 1 - y, create_trgb(0, pixel_color.x * 255.999, pixel_color.y * 255.999, pixel_color.z * 255.999));
            ++x;
        }
        --y;
    }
	mlx_put_image_to_window(vars.mlx, vars.win, data.img, 0, 0);
	mlx_key_hook(vars.win, key_hook, &vars);
	mlx_loop(mlx_ptr);
}