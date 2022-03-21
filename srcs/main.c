/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smana <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 13:31:07 by smana             #+#    #+#             */
/*   Updated: 2022/03/21 13:31:10 by smana            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	ft_empty_fractal(t_image *fractal, int x)
{
	fractal->scale = 220.0;
	fractal->n = 0;
	fractal->color.channel[0] = 3;
	fractal->color.channel[1] = 9;
	fractal->color.channel[2] = 7;
	fractal->x0 = -500;
	fractal->y0 = 500;
	if (x == 1)
	{
		fractal->c.re = 0;
		fractal->c.im = 0;
	}
}

void	ft_init_image(t_image *fractal)
{
	fractal->image = mlx_new_image(fractal->mlx_ptr, WIDTH, HEIGHT);
	if (!fractal->image)
		ft_instr_message(3);
	fractal->data_addr = mlx_get_data_addr(fractal->image, \
	&fractal->bits_per_pixel,
			&fractal->size_line, &fractal->endian);
	if (!fractal->data_addr)
		ft_instr_message(3);
}

void	ft_make_hooks(t_image *fractal)
{
	mlx_expose_hook(fractal->mlx_win, ft_expose_hook, fractal);
	mlx_key_hook(fractal->mlx_win, ft_key_hook, fractal);
	mlx_hook(fractal->mlx_win, KEY_CROSS, MASK_CROSS, ft_close_window, fractal);
	mlx_mouse_hook(fractal->mlx_win, ft_mouse_hook, fractal);
	mlx_loop(fractal->mlx_ptr);
}

void	ft_create_fractal(t_image *fractal, char *name, int x)
{
	ft_empty_fractal(fractal, x);
	fractal->mlx_ptr = mlx_init();
	if (!(fractal->mlx_ptr))
		ft_instr_message(1);
	fractal->mlx_win = mlx_new_window(fractal->mlx_ptr, WIDTH, HEIGHT, name);
	if (!(fractal->mlx_win))
		ft_instr_message(2);
	ft_init_image(fractal);
	ft_make_hooks(fractal);
}

int	main(int argc, char **argv)
{
	t_image	*fractal;

	fractal = (t_image *)malloc(sizeof(t_image));
	if (!fractal)
		ft_instr_message(5);
	if (!((argc == 2) || ((argc == 4) && \
	(ft_check_name(argv[1], fractal) == 0))))
		ft_instr_message(0);
	else if (ft_check_name(argv[1], fractal) == -1)
		ft_instr_message(4);
	else if ((ft_check_name(argv[1], fractal) == 0) && (argv[2]) && (argv[3]))
	{
		ft_init_c(fractal, argv[2], argv[3]);
		ft_create_fractal(fractal, argv[1], 0);
	}
	else
		ft_create_fractal(fractal, argv[1], 1);
	return (0);
}
