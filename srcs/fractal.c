/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smana <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 13:31:00 by smana             #+#    #+#             */
/*   Updated: 2022/03/21 13:31:03 by smana            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	draw_fractal(t_image *data)
{
	int		i;
	int		j;
	double	x;
	double	y;
	int		iter;

	i = 0;
	while (i++ < WIDTH)
	{
		j = 0;
		while (j++ < HEIGHT)
		{
			x = (data->x0 + i) / (double) data->scale;
			y = (data->y0 - j) / (double) data->scale;
			iter = choose_fractal(data, x, y);
			data->color_final = ((255 - iter * data->color.channel[0]) << 16)
				+ ((255 - iter * data->color.channel[1]) << 8) + \
				(255 - iter * data->color.channel[2]);
			my_mlx_pixel_put(data, i, j, data->color_final);
		}
	}
	mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, data->image, 0, 0);
}

int	ft_mandelbrot(double x, double y)
{
	double	c_re;
	double	c_im;
	double	tmp_re;
	double	tmp_im;
	int		i;

	c_re = x;
	c_im = y;
	i = 0;
	x = 0;
	y = 0;
	while (i < 100 && (x * x + y * y < 4))
	{
		tmp_re = x * x - y * y;
		tmp_im = 2 * x * y;
		x = tmp_re + c_re;
		y = tmp_im + c_im;
		i++;
	}
	return (i);
}

int	ft_julia(double x, double y, t_image *data)
{
	double	tmp_re;
	double	tmp_im;
	int		i;

	data->c.re = 0.36;
	data->c.im = 0.36;
	i = 0;
	while (i < 100 && (x * x + y * y < 4))
	{
		tmp_re = x * x - y * y;
		tmp_im = 2 * x * y;
		x = tmp_re + data->c.re;
		y = tmp_im + data->c.im;
		i++;
	}
	return (i);
}

double	choose_fractal(t_image *data, double x, double y)
{
	if (data->fract == 0)
		return (ft_julia(x, y, data));
	else if (data->fract == 1)
		return (ft_mandelbrot(x, y));
	else
		return (0.0);
}
