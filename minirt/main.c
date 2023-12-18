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

int	key_hook(int keycode, t_mlx *my_mlx)
{
	if(keycode == 53)
	{
		mlx_destroy_window(my_mlx->mlx, my_mlx->win);
		exit(0);
	}
	return (0);
}

int main(void)
{
    int         x;
    int         y;
	void	*mlx_ptr;
	void	*win_ptr;
	t_mlx		my_mlx;
    t_triple	pixel_color;
    t_camera    cam;
    t_ray       ray;
	t_sphere	sp;
    
    cam = init_camera(vec(0, 0, 0), vec(0, 0, -1));
	sp = sphere(vec(0, 0, -5), 2);
    y = HEIGHT - 1;
	my_mlx.mlx = mlx_init();
	my_mlx.win = mlx_new_window(my_mlx.mlx, WIDTH, HEIGHT, "miniRT");
	my_mlx.data.img = mlx_new_image(my_mlx.mlx, WIDTH, HEIGHT);
	my_mlx.data.addr = mlx_get_data_addr(my_mlx.data.img, &my_mlx.data.bits_per_pixel, &my_mlx.data.line_length, &my_mlx.data.endian);
	//printf("P3\n%d %d\n255\n", WIDTH, HEIGHT);
    while (y >= 0)
    {
        x = 0;
       while (x < WIDTH)
        {
            ray = ray_primary(&cam, x / (float)(WIDTH - 1), y / (float)(HEIGHT - 1));
            pixel_color = ray_color(&ray, &sp);
            //write_color(pixel_color);
			my_mlx_pixel_put(&my_mlx.data, x, HEIGHT - 1 - y, create_trgb(0, pixel_color.x * 255.999, pixel_color.y * 255.999, pixel_color.z * 255.999));
            ++x;
        }
        --y;
    }
	mlx_put_image_to_window(my_mlx.mlx, my_mlx.win, my_mlx.data.img, 0, 0);
	mlx_key_hook(my_mlx.win, key_hook, &my_mlx);
	mlx_loop(my_mlx.mlx);
}