#include "../includes/fractol.h"

double	ft_atoi_2(const char *str)
{
	double	num2;

	num2 = 0;
	if (*str == '.')
	{
		while (*str)
			str++;
		str--;
		while (*str != '.')
		{
			num2 = num2 + *str - '0';
			num2 *= 0.1;
			str--;
		}
	}
	return (num2);
}

double	ft_atoi(const char *str)
{
	double	num1;
	double	num2;
	double	res;

	num1 = 0;
	res = 1;
	if (*str == '-')
	{
		res = -1;
		str++;
	}
	while ((*str != '.') && (*str))
	{
		num1 = num1 * 10 + *str - '0';
		str++;
	}
	num2 = ft_atoi_2(str);
	return (res * (num1 + num2));
}

void	ft_init_c(t_image *fractal, char *ar1, char *ar2)
{
	fractal->c.re = ft_atoi(ar1);
	fractal->c.im = ft_atoi(ar2);
}
