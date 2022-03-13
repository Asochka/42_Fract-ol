#include "../includes/fractol.h"

void	my_mlx_pixel_put(t_image *data, int x, int y, int color)
{
	char	*dst;

	dst = data->data_addr + (y * data->size_line + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	create_trgb(int r, int g, int b)
{
	return (r << 16 | g << 8 | b);
}

void	ft_instr_message(int k)
{
	if (k == 0)
		ft_printf(ERR_NUM_ARGV);
	if (k == 1)
		ft_printf(ERR_FRACTOL_INIT);
	if (k == 2)
		ft_printf(ERR_WINDOW_INIT);
	if (k == 3)
		ft_printf(ERR_IMAGE_INIT);
	if (k == 4)
		ft_printf(ERR_FRACTAL_NAME);
	if (k == 5)
		ft_printf(ERR_THREADS);
	exit (0);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

int	ft_check_name(char *s, t_image *fractal)
{
	if (ft_strcmp(s, "Julia") == 0)
	{
		fractal->fract = 0;
		return 0;
	}
	else if (ft_strcmp(s, "Mandelbrot") == 0)
	{
		fractal->fract = 1;
		return 1;
	}
	// else if (ft_strcmp(s, "") == 0)
	// {
	// 	fractal->fract = 2;
	// 	return 2;
	// }
	else
		return -1;
}

void	ft_empty_fractal(t_image *fractal)
{
	// fractal->image = 0;
	// fractal->data_addr = 0;
	// fractal->bits_per_pixel = 0;
	// fractal->size_line = 0;
	// fractal->endian = 0;
	fractal->scale = 250.0;//or 200
	fractal->n = 0;//number of iterations
	fractal->color.channel[0] = 0;
	fractal->color.channel[1] = 0;
	fractal->color.channel[2] = 0;
	fractal->color.channel[3] = 0;
	fractal->c.re = 0;
	fractal->c.im = 0;

	// data->x0 = -500;
	// data->y0 = 500;
}

void	ft_init_image(t_image *fractal)
{
	fractal->image = mlx_new_image(fractal->mlx_ptr, WIDTH, HEIGHT);
	if (!fractal->image)
		ft_instr_message(3);
	fractal->data_addr = mlx_get_data_addr(fractal->image, &fractal->bits_per_pixel,
			&fractal->size_line, &fractal->endian);
	if (!fractal->data_addr)
		ft_instr_message(3);
}

int	key_hook(int keycode, t_image *data)
{
	mlx_clear_window(data->mlx_ptr, data->mlx_win);
	if (keycode == KEY_ESC)
		close_window(keycode, data);
	if (keycode == KEY_C)
		get_color(data);
	draw_fractal(data);
	return (keycode);
}

int	mouse_hook(int keycode, int x, int y, t_image *data)
{
	mlx_clear_window(data->mlx_ptr, data->mlx_win);
	if (keycode == SCROLL_DOWN)
	{
		data->scale *= 1.2;
		x = 0;
		y = 0;
	}
	if (keycode == SCROLL_UP && data->scale > 0)
	{
		data->scale *= 0.8;
		x = 0;
		y = 0;
	}
	draw_fractal(data);
	return (keycode);
}

int	expose_hook(t_image *data)
{
	draw_fractal(data);
	return (0);
}

void	ft_make_hooks(t_image *fractal)
{
	mlx_expose_hook(fractal->mlx_win, expose_hook, fractal);
	mlx_key_hook(fractal->mlx_win, key_hook, fractal);
	mlx_hook(fractal->mlx_win, KEY_CROSS, MASK_CROSS, close_window, fractal);
	mlx_mouse_hook(fractal->mlx_win, mouse_hook, fractal);
	mlx_loop(fractal->mlx_ptr);
}

int	close_window(int keycode, t_image *list)
{
	exit(0);
	(void)list;
	return (keycode);
}

void	ft_create_fractal(t_image *fractal, char *name)
{
	void	*mlx;

	mlx = mlx_init();
	ft_empty_fractal(fractal);
	if (!(fractal->mlx_ptr = mlx))
		ft_instr_message(2);
	if (!(fractal->mlx_win = mlx_new_window(fractal->mlx_win, WIDTH, HEIGHT, name)))
		ft_instr_message(2);
	ft_init_image(fractal);
	ft_make_hooks(fractal);
	return (fractal);
}

int	main(int argc, char **argv)
{
	t_image	*fractal;

	fractal = (t_image *)malloc(sizeof(t_image));
	if (!fractal)
		exit (0);
	if (argc != 2)
		ft_instr_message(0);
	else if (ft_check_name(argv[1], fractal) == -1)
		ft_instr_message(4);
	else
		ft_create_fractal(fractal, argv[1]);
	

	// my_mlx_pixel_put(&img, 5, 5, 0x00FF0000);
	// mlx_put_image_to_window(mlx, mlx_win, img.image, 0, 0);
	// mlx_loop(mlx);
}

void	get_color(t_image *img)
{
	img->n = (img->n)%10 * create_trgb((int)(sqrt(img->z.re * img->z.re + img->z.im * img->z.im) * 133) % 255,
			(int)(sqrt(img->z.re * img->z.re + img->z.im * img->z.im) * 1000) % 255,
			(int)(sqrt(img->z.re * img->z.re + img->z.im * img->z.im) * 2912) % 255);

	if (data->num == 0)
	{
		data->num = 1;
		data->r += 3;
		data->g += 0;
		data->b -= 1;
	}
	else if (data->num == 1)
	{
		data->num = 2;
		data->r = 1;
		data->g = 10;
		data->b = 0;
	}
	else if (data->num == 2)
	{
		data->num = 0;
		data->r = 2;
		data->g = 5;
		data->b = 6;
	}
}
