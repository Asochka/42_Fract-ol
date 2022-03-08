/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemmon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 12:06:10 by lemmon            #+#    #+#             */
/*   Updated: 2022/02/17 12:06:12 by lemmon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_BONUS_H
# define FRACTOL_BONUS_H

# include <mlx.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include "../ft_printf/ft_printf.h"

# define INVALID_DATA			-3
# define BAD_MEMALLOC			1
# define INIT_ERROR				-2
# define BAD_USAGE				-4

# define WIDTH  1000
# define HEIGHT 1000

# define KEY_ESC 53
# define KEY_CROSS 17
# define MASK_CROSS 131072L
# define KEY_UP 126
# define KEY_LEFT 123
# define KEY_DOWN 125
# define KEY_RIGHT 124

# define KEY_ONE	83
# define KEY_TWO	84
# define KEY_THREE	85
# define KEY_FOUR	86
# define KEY_FIVE	87
# define KEY_SIX	88
# define KEY_SEVEN	89
# define KEY_EIGHT	91
# define KEY_NINE	92
# define KEY_C		8

# define SCROLL_UP 4
# define SCROLL_DOWN 5
# define ZOOM_PLUS 1.20
# define ZOOM_MINUS 0.80

typedef struct s_data
{
	void	*mlx_ptr;
	void	*mlx_win;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		fract;
	int		error;
	double	scale;
	double	x0;
	double	y0;
	int		r;
	int		g;
	int		b;
	double	c_re;
	double	c_im;
	int		color;
	int		num;
}	t_data;

t_data	*init_window(t_data *data);
t_data	*new_image(t_data *data);
double	choose_fractal(t_data *data, double x, double y);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	draw_fractal(t_data *data);
void	init_data(t_data *data);
void	get_color(t_data *data);
void	error_message(int n);
int		mouse_hook(int keycode, int x, int y, t_data *data);
int		ft_julia(double x, double y, t_data *data);
int		check_correct_name(char *s, t_data *data);
int		close_window(int keycode, t_data *list);
int		mouse_mouv(int x, int y, t_data *data);
int		key_hook2(int keycode, t_data *data);
int		key_hook(int keycode, t_data *data);
int		ft_mandelbrot(double x, double y);
int		ft_compare(char *s1, char *s2);
int		ft_burning_ship(double x, double y);
#endif
