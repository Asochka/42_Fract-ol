#include <fractol.h>

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	main(int argc, char **argv)
{
	void	*mlx;
	void	*mlx_win;
	void	*img;
	t_image	img;

	mlx = mlx_init();
	img = mlx_new_image(mlx, WIDTH, HEIGHT);
	mlx_win = mlx_new_window(mlx, WIDTH, HEIGHT);

	img.data_addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);
	my_mlx_pixel_put(&img, 5, 5, 0x00FF0000);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}
}