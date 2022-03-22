/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smana <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 13:31:22 by smana             #+#    #+#             */
/*   Updated: 2022/03/21 13:31:24 by smana            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	ft_check_name(char *s, t_image *fractal)
{
	if (ft_strcmp(s, "Julia") == 0)
	{
		fractal->fract = 0;
		return (0);
	}
	else if (ft_strcmp(s, "Mandelbrot") == 0)
	{
		fractal->fract = 1;
		return (1);
	}
	else
		return (-1);
}

void	ft_instr_message(int k)
{
	if (k == 0)
		ft_printf(ERR_NUM_ARGV);
	if (k == 1)
		ft_printf(ERR_FRACTOL_INIT);
	if (k == 2)
		ft_printf(ERR_WINDOW_INIT);
	if (k == 3)
		ft_printf(ERR_IMAGE_INIT);
	if (k == 4)
		ft_printf(ERR_FRACTAL_NAME);
	if (k == 5)
		ft_printf(ERR_WITH_MALLOC);
	exit (0);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

void	my_mlx_pixel_put(t_image *img, int x, int y, int color)
{
	char	*dst;

	dst = img->data_addr + (y * img->size_line + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}
