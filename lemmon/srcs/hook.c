/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemmon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 17:57:14 by lemmon            #+#    #+#             */
/*   Updated: 2022/02/16 17:57:18 by lemmon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	close_window(int keycode, t_data *list)
{
	exit(0);
	(void)list;
	return (keycode);
}

void	get_color(t_data *data)
{
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

int	key_hook(int keycode, t_data *data)
{
	mlx_clear_window(data->mlx_ptr, data->mlx_win);
	if (keycode == KEY_ESC)
		close_window(keycode, data);
	if (keycode == KEY_C)
		get_color(data);
	draw_fractal(data);
	return (keycode);
}

int	mouse_hook(int keycode, int x, int y, t_data *data)
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
