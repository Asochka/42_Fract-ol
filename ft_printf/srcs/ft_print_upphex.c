/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_upphex.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smana <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 17:35:40 by smana             #+#    #+#             */
/*   Updated: 2021/11/12 17:35:42 by smana            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_len_in_hex_upp(unsigned int	a)
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

int	ft_to_hexupp(unsigned int	a)
{
	char	*k;
	int		i;
	char	*base;
	int		ret;

	base = "0123456789ABCDEF";
	i = ft_len_in_hex_upp(a);
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

int	ft_print_upphex(t_print *tab)
{
	unsigned int	a;
	int				ret;

	ret = 0;
	a = va_arg(tab->args, unsigned int);
	if (a == 0)
		ret += write(1, "0", 1);
	else
		ret = ft_to_hexupp(a);
	return (ret);
}
