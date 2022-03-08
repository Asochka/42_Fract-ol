/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_lowhex.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smana <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 17:34:36 by smana             #+#    #+#             */
/*   Updated: 2021/11/12 17:34:39 by smana            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_len_in_hex_low(unsigned int	a)
{
	int	k;

	k = 0;
	while (a > 0)
	{
		k++;
		a = a / 16;
	}
	return (k);
}

int	ft_to_hexlow(unsigned int	a)
{
	char	*k;
	int		i;
	char	*base;
	int		ret;

	base = "0123456789abcdef";
	i = ft_len_in_hex_low(a);
	ret = i;
	k = (char *)malloc((i + 1) * sizeof(char));
	k[i] = '\0';
	while (a > 0)
	{
		k[--i] = base[a % 16];
		a = a / 16;
	}
	write(1, k, ret);
	free (k);
	return (ret);
}

int	ft_print_lowhex(t_print *tab)
{
	unsigned int	a;
	int				ret;

	ret = 0;
	a = va_arg(tab->args, unsigned int);
	if (a == 0)
		ret += write(1, "0", 1);
	else
		ret = ft_to_hexlow(a);
	return (ret);
}
