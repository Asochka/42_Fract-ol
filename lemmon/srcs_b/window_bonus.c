/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemmon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 15:29:45 by lemmon            #+#    #+#             */
/*   Updated: 2022/02/16 15:29:47 by lemmon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol_bonus.h"

int	expose_hook(t_data *data)
{
	draw_fractal(data);
	return (0);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	mouse_mouv(int x, int y, t_data *data)
{
	mlx_clear_window(data->mlx_ptr, data->mlx_win);
	x -= WIDTH / 5;
	y -= HEIGHT / 5;
	data->c_re = ((double)x / WIDTH) * 2;
	data->c_im = ((double)y / HEIGHT) * 2;
	draw_fractal(data);
	return (0);
}

t_data	*new_image(t_data *data)
{
	data->img = mlx_new_image(data->mlx_ptr, WIDTH, HEIGHT);
	if (!data->img)
		exit(INIT_ERROR);
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel,
			&data->line_length, &data->endian);
	if (!data->addr)
		exit(INIT_ERROR);
	return (data);
}

t_data	*init_window(t_data *data)
{
	data->mlx_ptr = mlx_init();
	if (!data->mlx_ptr)
		exit(INIT_ERROR);
	data->mlx_win = mlx_new_window(data->mlx_ptr, WIDTH, HEIGHT, "fractol");
	if (!data->mlx_win)
		exit(INIT_ERROR);
	new_image(data);
	mlx_expose_hook(data->mlx_win, expose_hook, data);
	mlx_key_hook(data->mlx_win, key_hook, data);
	mlx_hook(data->mlx_win, KEY_CROSS, MASK_CROSS, close_window, data);
	mlx_mouse_hook(data->mlx_win, mouse_hook, data);
	mlx_hook(data->mlx_win, 6, (1L << 6), mouse_mouv, data);
	mlx_loop(data->mlx_ptr);
	return (data);
}
