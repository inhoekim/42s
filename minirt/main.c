#include "mlx/mlx.h"
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
	/*
    float      normalized_x;
    float      normalized_y;
	void	*mlx_ptr;
	void	*win_ptr;
	t_data      data;
	*/
    t_triple	pixel_color;
    t_camera    cam;
    t_ray       ray;
	t_sphere	sp;
    
    cam = init_camera(vec(0, 0, 0), vec(0, 0, -1));
	sp = sphere(vec(0, 0, -5), 2);

	printf("P3\n%d %d\n255\n", WIDTH, HEIGHT);
    y = HEIGHT - 1;
    while (y >= 0)
    {
        x = 0;
       while (x < WIDTH)
        {
            ray = ray_primary(&cam, x / (float)(WIDTH - 1), y / (float)(HEIGHT - 1));
            pixel_color = ray_color(&ray, &sp);
            write_color(pixel_color);
			//my_mlx_pixel_put(&data, x, canv.height - 1 - y, create_trgb(0, pixel_color.x * 255.999, pixel_color.y * 255.999, pixel_color.z * 255.999));
            ++x;
        }
        --y;
    }
	//mlx_put_image_to_window(vars.mlx, vars.win, data.img, 0, 0);
	//mlx_key_hook(vars.win, key_hook, &vars);
	//mlx_loop(mlx_ptr);
}