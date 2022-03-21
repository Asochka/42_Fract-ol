/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smana <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 13:31:14 by smana             #+#    #+#             */
/*   Updated: 2022/03/21 13:31:17 by smana            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	get_color(t_image *img)
{
	if (img->n == 0)
	{
		img->n = 1;
		img->color.channel[0] += 3;
		img->color.channel[1] += 0;
		img->color.channel[2] -= 1;
	}
	else if (img->n == 1)
	{
		img->n = 2;
		img->color.channel[0] = 1;
		img->color.channel[1] = 10;
		img->color.channel[2] = 0;
	}
	else if (img->n == 2)
	{
		img->n = 0;
		img->color.channel[0] = 2;
		img->color.channel[1] = 5;
		img->color.channel[2] = 6;
	}
}

int	ft_expose_hook(t_image *img)
{
	draw_fractal(img);
	return (0);
}

int	ft_close_window(int keycode, t_image *list)
{
	exit(0);
	(void)list;
	return (keycode);
}

int	ft_key_hook(int keycode, t_image *img)
{
	mlx_clear_window(img->mlx_ptr, img->mlx_win);
	if (keycode == KEY_ESC)
		ft_close_window(keycode, img);
	if (keycode == KEY_C)
		get_color(img);
	draw_fractal(img);
	return (keycode);
}

int	ft_mouse_hook(int keycode, int x, int y, t_image *img)
{
	mlx_clear_window(img->mlx_ptr, img->mlx_win);
	if (keycode == SCROLL_DOWN)
	{
		img->scale *= 1.2;
		x = 0;
		y = 0;
	}
	if (keycode == SCROLL_UP && img->scale > 0)
	{
		img->scale *= 0.8;
		x = 0;
		y = 0;
	}
	draw_fractal(img);
	return (keycode);
}
