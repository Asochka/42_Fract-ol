/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemmon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 17:44:31 by lemmon            #+#    #+#             */
/*   Updated: 2022/02/13 17:44:32 by lemmon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
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

int	ft_julia(double x, double y, t_data *data)
{
	double	tmp_re;
	double	tmp_im;
	int		i;

	data->c_re = 0.36;
	data->c_im = 0.36;
	i = 0;
	while (i < 100 && (x * x + y * y < 4))
	{
		tmp_re = x * x - y * y;
		tmp_im = 2 * x * y;
		x = tmp_re + data->c_re;
		y = tmp_im + data->c_im;
		i++;
	}
	return (i);
}

double	choose_fractal(t_data *data, double x, double y)
{
	if (data->fract == 1)
		return (ft_julia(x, y, data));
	else if (data->fract == 2)
		return (ft_mandelbrot(x, y));
	else
		return (0.0);
}

void	draw_fractal(t_data *data)
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
			data->color = ((255 - iter * data->r) << 16)
				+ ((255 - iter * data->g) << 8) + (255 - iter * data->b);
			my_mlx_pixel_put(data, i, j, data->color);
		}
	}
	mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, data->img, 0, 0);
}
