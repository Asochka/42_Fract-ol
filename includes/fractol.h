#ifndef FRACTOL_H
# define FRACTOL_H

# define MOUSE_SCROLL_UP	4
# define MOUSE_SCROLL_DOWN	5

# define NUM_PAD_MINUS		78
# define NUM_PAD_PLUS		69

# define KEY_A				0
# define KEY_S				1
# define KEY_D				2
# define KEY_W				13

# define ARROW_UP			126
# define ARROW_DOWN			125
# define ARROW_LEFT			123
# define ARROW_RIGHT		124

# define COLOR_SILVER		0xCCCCCC
# define COLOR_TUNDORA		0x444444

# define MAIN_PAD_ESC		53
# define MAIN_PAD_SPACE		49
# define MAIN_PAD_C			8
# define MAIN_PAD_H			4
# define MAIN_PAD_R			15
# define MAIN_PAD_PLUS		24
# define MAIN_PAD_MINUS		27

# include <mlx.h>
# include <unistd.h>
# include <stdlib.h>
# include "../ft_printf/includes/ft_printf.h"

// # include <fcntl.h>
// # include <math.h>
// # include <stdint.h>

# define WIDTH		1000
# define HEIGHT		1000

# define THREADS	10

typedef struct		s_complex
{
	double			re;
	double			im;
}					t_complex;

typedef	struct		s_color
{
	int8_t			channel[4];
}					t_color;

/*
** image          — image identifier
** data_addr      — image
** bits_per_pixel — depth of image
** size_line      — number of bytes used to store one line of image
** endian         — little or big endian
*/

typedef struct		s_image
{
	void			*image;
	char			*data_addr;
	int				bits_per_pixel;
	int				size_line;
	int				endian;

	int				n;

	void			*mlx_ptr;
	void			*mlx_win;

	t_color			color;
	t_complex		c;

	// int		fract;
	// int		error;
	// double	scale;
	// double	x0;
	// double	y0;
}					t_image;

#endif



// # define ERR_FRACTOL_INIT	"ERROR: Can\'t initialize fractol"
// # define ERR_WINDOW_INIT	"ERROR: Can\'t initialize window"
// # define ERR_IMAGE_INIT		"ERROR: Can\'t initialize image"

// # define ERR_FRACTAL_NAME	"ERROR: No such fractal"

// # define ERR_TREADS			"ERROR: There is a problem with threads"