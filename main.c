#include "fractol.h"

void	my_mlx_pixel_put(t_image *data, int x, int y, int color)
{
	char	*dst;

	dst = data->data_addr + (y * data->size_line + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	main(int argc, char **argv)
{
	void	*mlx;
	void	*mlx_win;
	t_image	img;

	mlx = mlx_init();
	img.image = mlx_new_image(mlx, WIDTH, HEIGHT);
	mlx_win = mlx_new_window(mlx, WIDTH, HEIGHT, "hey");

	img.data_addr = mlx_get_data_addr(img.image, &img.bits_per_pixel, &img.size_line,
								&img.endian);
	my_mlx_pixel_put(&img, 5, 5, 0x00FF0000);
	mlx_put_image_to_window(mlx, mlx_win, img.image, 0, 0);
	mlx_loop(mlx);
}
