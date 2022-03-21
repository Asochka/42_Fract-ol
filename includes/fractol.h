/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smana <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 13:34:36 by smana             #+#    #+#             */
/*   Updated: 2022/03/21 13:34:38 by smana            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# define ERR_FRACTOL_INIT	"ERROR: Can\'t initialize fractol"
# define ERR_WINDOW_INIT	"ERROR: Can\'t initialize window"
# define ERR_IMAGE_INIT		"ERROR: Can\'t initialize image"
# define ERR_FRACTAL_NAME	"ERROR: No such fractal\n \
Correct names:\nJulia\nMandelbrot\n"
# define ERR_WITH_MALLOC	"ERROR: There is a problem with memory"
# define ERR_NUM_ARGV		"ERROR: Wrong number of arguments"

# define NUM_PAD_MINUS		78
# define NUM_PAD_PLUS		69

# define KEY_A				0
# define KEY_S				1
# define KEY_D				2
# define KEY_W				13

# define KEY_ESC 			53
# define KEY_CROSS 			17
# define MASK_CROSS 		131072L
# define KEY_UP 			126
# define KEY_LEFT 			123
# define KEY_DOWN 			125
# define KEY_RIGHT 			124

# define COLOR_SILVER		0xCCCCCC
# define COLOR_TUNDORA		0x444444

# define MAIN_PAD_SPACE		49
# define MAIN_PAD_H			4
# define MAIN_PAD_R			15
# define MAIN_PAD_PLUS		24
# define MAIN_PAD_MINUS		27

# define KEY_ONE			83
# define KEY_TWO			84
# define KEY_THREE			85
# define KEY_FOUR			86
# define KEY_FIVE			87
# define KEY_SIX			88
# define KEY_SEVEN			89
# define KEY_EIGHT			91
# define KEY_NINE			92
# define KEY_C				8

# define SCROLL_UP 			4
# define SCROLL_DOWN 		5

# include <../mlx/mlx.h>
# include <unistd.h>
# include <stdlib.h>
# include "../ft_printf/includes/ft_printf.h"

# define WIDTH				1000
# define HEIGHT				1000

typedef struct s_complex
{
	double			re;
	double			im;
}	t_complex;

typedef struct s_color
{
	int8_t			channel[3];
}	t_color;

typedef struct s_image
{
	void			*mlx_ptr;
	void			*mlx_win;
	void			*image;
	char			*data_addr;
	int				bits_per_pixel;
	int				size_line;
	int				endian;
	double			scale;
	int				n;
	int				color_final;
	t_color			color;
	t_complex		c;
	int				fract;
	double			x0;
	double			y0;
}	t_image;

void	ft_empty_fractal(t_image *fractal);
void	ft_init_image(t_image *fractal);
void	ft_make_hooks(t_image *fractal);
void	ft_create_fractal(t_image *fractal, char *name);
int		main(int argc, char **argv);

void	draw_fractal(t_image *data);
int		ft_mandelbrot(double x, double y);
int		ft_julia(double x, double y, t_image *data);
double	choose_fractal(t_image *data, double x, double y);

void	get_color(t_image *img);
int		ft_expose_hook(t_image *img);
int		ft_close_window(int keycode, t_image *list);
int		ft_key_hook(int keycode, t_image *img);
int		ft_mouse_hook(int keycode, int x, int y, t_image *img);

int		ft_check_name(char *s, t_image *fractal);
void	ft_instr_message(int k);
int		ft_strcmp(char *s1, char *s2);
void	my_mlx_pixel_put(t_image *img, int x, int y, int color);

#endif
/*
** image          — image identifier
** data_addr      — image
** bits_per_pixel — depth of image
** size_line      — number of bytes used to store one line of image
** endian         — little or big endian
*/
