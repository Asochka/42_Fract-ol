/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemmon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 16:30:55 by lemmon            #+#    #+#             */
/*   Updated: 2022/02/13 16:30:57 by lemmon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	expose_hook(t_data *data)
{
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
	mlx_loop(data->mlx_ptr);
	return (data);
}
