/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemmon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 15:29:21 by lemmon            #+#    #+#             */
/*   Updated: 2022/02/16 15:29:25 by lemmon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol_bonus.h"

int	ft_compare(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

int	check_correct_name(char *s, t_data *data)
{
	data->fract = 0;
	data->error = 0;
	if (ft_compare(s, "Julia") == 0)
		data->fract = 1;
	else if (ft_compare(s, "Mandelbrot") == 0)
		data->fract = 2;
	else if (ft_compare(s, "Burning_ship") == 0)
		data->fract = 3;
	if (data->fract > 0)
		data->error = 1;
	return (data->error);
}

void	error_message(int n)
{
	if (n == 0)
	{
		ft_printf("\nNot enough of more params! Please, write like:\n");
		ft_printf("USAGE: ");
		write(1, "\x1B[36m", 6);
		ft_printf("./fractols Julia/Mandelbrot/Burning_ship\n\n");
	}
	if (n == 1)
	{
		ft_printf("\nWrong fractal name! Please, write like:\n");
		ft_printf("USAGE: ");
		write(1, "\x1B[36m", 6);
		ft_printf("./fractols Julia/Mandelbrot/Burning_ship\n\n");
	}
}

void	init_data(t_data *data)
{
	data->scale = 250.0;
	data->x0 = -500;
	data->y0 = 500;
	data->r = 5;
	data->g = 5;
	data->b = 4;
	data->c_re = 0;
	data->c_im = 0;
	data->num = 0;
}

int	main(int ac, char **av)
{
	t_data	*data;

	data = (t_data *)malloc(sizeof(t_data));
	if (!data)
		exit(BAD_MEMALLOC);
	if (ac != 2)
	{
		error_message(0);
		exit(INVALID_DATA);
	}
	else if (ac == 2)
	{
		if (check_correct_name(av[1], data) == 0)
		{
			error_message(1);
			exit(INVALID_DATA);
		}
		init_data(data);
		init_window(data);
		return (0);
	}
}
