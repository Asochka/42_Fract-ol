#include <stdio.h>
#include "includes/fractol.h"

int	ft_check_name(char *s, t_image *fractal)
{
	char mass_names[2][12]= {
	mass_names[0][0] = "Julia",
	mass_names[1][0] = "Mandelbrot",
//	mass_names[2] = "Burning Ship"
	};

	if (s == mass_names[0])
	{
		fractal->fract = 0;
		return 0;
	}
	else if (s == mass_names[1])
	{
		fractal->fract = 0;
		return 1;
	}
	// else if (s == mass_names[2])
	// {
	// 	fractal->fract = 0;
	// 	return 2;
	// }
	else
		return -1;
}



int main()
{
	t_image *frac;

	frac = (t_image *)malloc(sizeof(t_image));
	printf("%d", ft_check_name("Julia", frac));
}