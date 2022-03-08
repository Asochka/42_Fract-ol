/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemmon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 15:30:25 by lemmon            #+#    #+#             */
/*   Updated: 2022/02/16 15:30:28 by lemmon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol_bonus.h"

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

int	key_hook2(int keycode, t_data *data)
{
	if (keycode == KEY_ONE)
		data->r++;
	if (keycode == KEY_TWO)
		data->g++;
	if (keycode == KEY_THREE)
		data->b++;
	if (keycode == KEY_FOUR && data->r > 0)
		data->r--;
	if (keycode == KEY_FIVE && data->g > 0)
		data->g--;
	if (keycode == KEY_SIX && data->b > 0)
		data->b--;
	return (keycode);
}

int	key_hook(int keycode, t_data *data)
{
	mlx_clear_window(data->mlx_ptr, data->mlx_win);
	if (keycode == KEY_ESC)
		close_window(keycode, data);
	if (keycode == KEY_DOWN)
		data->y0 -= 100;
	if (keycode == KEY_UP)
		data->y0 += 100;
	if (keycode == KEY_LEFT)
		data->x0 -= 100;
	if (keycode == KEY_RIGHT)
		data->x0 += 100;
	if (keycode == KEY_C)
		get_color(data);
	key_hook2(keycode, data);
	draw_fractal(data);
	return (keycode);
}

int	mouse_hook(int keycode, int x, int y, t_data *data)
{
	mlx_clear_window(data->mlx_ptr, data->mlx_win);
	if (keycode == SCROLL_DOWN)
	{
		data->scale += 50;
		data->x0 -= (WIDTH / 2 - x) * 0.2;
		data->y0 += (HEIGHT / 2 - y) * 0.2;
		draw_fractal(data);
	}
	if (keycode == SCROLL_UP && data->scale > 0)
	{
		data->scale -= 50;
		data->x0 += (x - WIDTH / 2) * 0.2;
		data->y0 -= (y - HEIGHT / 2) * 0.2;
		draw_fractal(data);
	}
	draw_fractal(data);
	return (keycode);
}
