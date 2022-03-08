/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smana <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 13:52:53 by smana             #+#    #+#             */
/*   Updated: 2021/10/25 13:52:55 by smana            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	ft_stepen(int a)
{
	int	res;

	res = 1;
	while (a > 1)
	{
		res = res * 10;
		a--;
	}
	return (res);
}

static long	ft_sign(long n)
{
	if (n < 0)
		return (-1);
	else
		return (1);
}

static int	ft_size(long val)
{
	int	i;

	i = 0;
	while (val > 0)
	{
		i++;
		val = val / 10;
	}
	return (i);
}

void	ft_putnbr(int n, int *ret)
{
	char			c;
	int				i;
	long			val;

	i = 0;
	val = (long)n;
	if (ft_sign(val) == -1)
		*ret += write(1, "-", 1);
	val = ft_sign(val) * val;
	i = ft_size(val);
	if (val == 0)
		*ret += write(1, "0", 1);
	else
	{
		while (i > 0)
		{
			c = val / (ft_stepen(i)) + '0';
			*ret += write(1, &c, 1);
			if (i == 1)
				val = val % 10;
			else
				val = val % (ft_stepen(i));
			i--;
		}
	}
}
