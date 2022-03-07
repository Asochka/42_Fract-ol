#ifndef FRACTOL_H
# define FRACTOL_H

# include <mlx.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <math.h>
# include <stdint.h>

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
}					t_image;

#endif